#include "../../../Library/header.h"

/**
 * @author HEXDude
 * @date 2022/5/12
 * @description 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 * @link https://leetcode.cn/problems/multiply-strings/
 * @conclusion TODO NOT ACCEPTED
 */

char *addStrings(char *num1, char *num2);

char *multiply(char *num1, char *num2);

int main() {
	// CLion控制台不输出问题,设置缓冲区
	setbuf(stdout, NULL);
	char *nums1 = "9";
	char *nums2 = "9";
	char *result = multiply(nums1, nums2);
}

/**
 * 主题思想是模拟
 * 通过模拟乘法的竖式计算来不使用类型转换函数得到乘积.
 * 因此可以将乘数拆开按位与被乘数相乘得到'位乘积'.
 * 注意乘数的每数据位与被乘数相乘的乘积均需要在乘积后补上相应的零.
 * 如个位不补,十位补1个,依次类推...
 * 并且'位乘积'的顺序是相反的.
 * 最后将若干位乘积结果按位相加即可得到num1与num2的Sting类型结果
 */
char *multiply(char *num1, char *num2) {
	//如果num1或者num2任意一个为零,直接返回零
	if (strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0) {
		return "0";
	}

	int num1Length = strlen(num1), num2Length = strlen(num2);
	//被乘数与乘数的迭代标识,从个位往上迭代
	int num1Index = num1Length - 1, num2Index = num2Length - 1;

	//进位标识,每当有进位产生时将进位的值更新到这里
	int carry = 0;

	//全局的num1与num2的位乘积结果,大小由乘数num2的位数决定 TODO FREE
	char **globalBitProduct = malloc(sizeof(char *) * num2Length);
	int globalBitProductIndex = 0;

	char *traverseBitProduct;


	while (num1Index >= 0 || num2Index >= 0 || carry != 0) {

		/**
		 * 当从尾部重新遍历num1的时候,重新初始化临时位乘积容器
		 * 并补零
		 */
		int traverseBitProductIndex;
		if (num1Index == num1Length - 1 && num2Index >= 0) {
			traverseBitProduct = malloc(sizeof(char) * 19);
			traverseBitProductIndex = num2Length - 1 - num2Index;
			memset(traverseBitProduct, '0', sizeof(traverseBitProductIndex));
		}

		//被乘数
		int multiplicand = num1Index >= 0 ? num1[num1Index--] - '0' : 0;
		//乘数
		int multiplier = num2Index >= 0 ? num2[num2Index] - '0' : 0;
		//乘积
		int multiply = (multiplicand * multiplier + carry) % 10;
		//进位值
		carry = (multiplicand * multiplier + carry) / 10;

		/**
		 * 在num1未结束的情况下
		 */
		if (num1Index >= -1 && ((multiplicand != 0 && multiplier != 0) || carry != 0)) {
			traverseBitProduct[traverseBitProductIndex++] = multiply + '0';
			if (num1Index == -1) {
				traverseBitProduct[traverseBitProductIndex++] = '\0';
				globalBitProduct[globalBitProductIndex++] = traverseBitProduct;
				num1Index = num1Length - 1;
				num2Index--;
			}
		}
	}

	/*
	 * 位乘积结果中长度最大的字符串
	 */
	int maxProductLength = strlen(globalBitProduct[globalBitProductIndex - 1]);
	char *result = malloc(sizeof(char) * 19);
	int resultColIndex = 0;

	for (int i = 0; i < maxProductLength; ++i) {
		int colSum = 0;
		for (int j = 0; j < globalBitProductIndex; ++j) {
			int tempLength = strlen(globalBitProduct[j]);
			int number = i >= tempLength ? 0 : globalBitProduct[j][i] - '0' + carry;
			colSum = colSum + number + carry;
			carry = colSum / 10;
			colSum = colSum % 10;
		}
		result[resultColIndex++] = colSum + '0';
	}
	result[resultColIndex++] = '\0';
	for (int i = 0; 2 * i < resultColIndex - 1; i++) {
		int t = result[i];
		result[i] = result[resultColIndex - i - 1 - 1], result[resultColIndex - i - 1 - 1] = t;
	}
	printf("%s\n", result);

	free(globalBitProduct);
	return result;
}