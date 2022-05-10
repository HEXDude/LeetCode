#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include <C:\Users\HEXDude\WorkSpace\LeetCode\Library\uthash.h>

/**
 * @author HEXDude
 * @date 2022/5/10
 * @description 给定两个字符串形式的非负整数num1 和num2，计算它们的和并同样以字符串形式返回。
 * 你不能使用任何內建的用于处理大整数的库（比如 BigInteger），也不能直接将输入的字符串转换为整数形式。
 * @link https://leetcode.cn/problems/add-strings
 * @conclusion
 */

char *addStrings(char *num1, char *num2);

int main() {
	//CLion控制台不输出问题,设置缓冲区
	setbuf(stdout, NULL);
	char *nums1 = "11";
	char *nums2 = "123";
	char *result = addStrings(nums1, nums2);
}

/**
 * 由题意可得不能使用任何类似Java的装箱拆箱机制并且字符串中只包含数字0~9
 * 可以遍历字符串按位相加
 * 字符通过ASCII码转换成对应的整型数字
 * 进位标识保存每次进位制
 */
char *addStrings(char *num1, char *num2) {
	int num1Index = strlen(num1) - 1, num2Index = strlen(num2) - 1;
	//不理解官方为什么要+3
	char *result = (char *) malloc(sizeof(char) * (fmax(num1Index, num2Index) + 3));
	int resultIndex = 0;
	//进位
	int carry = 0;

	/**
	 * 遍历用双指针思想
	 * 两个字符串均从数字个位开始遍历,按位相加
	 * 遇到进位则保存进位
	 */
	while (num1Index >= 0 || num2Index >= 0 || carry != 0) {
		int num1Element = num1Index >= 0 ? num1[num1Index] - '0' : 0;
		int num2Element = num2Index >= 0 ? num2[num2Index] - '0' : 0;

		//此条语句在num1.num2遍历结束后会将进位补充进结果
		int sum = num1Element + num2Element + carry;
		result[resultIndex++] = (sum % 10) + '0';
		carry = sum / 10;
		num1Index--, num2Index--;
	}

	/**
	 * 翻转结果
	 * 在知道字符串长度的情况下可推导出交换公式
	 * nums[2*len - i - 1] <-> nums[2*len -i ]
	 */
	for (int i = 0; 2 * i < resultIndex; i++) {
		int t = result[i];
		result[i] = result[resultIndex - i - 1], result[resultIndex - i - 1] = t;
	}
	//字符串末尾结束符
	result[resultIndex++] = 0;

	free(result);
	return result;
}