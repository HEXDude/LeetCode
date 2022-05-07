#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include <C:\Users\HEXDude\WorkSpace\LeetCode\Library\uthash.h>

/**
 * @author HEXDude
 * @date 2022/5/7
 * @description 给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。
 * @link https://leetcode-cn.com/problems/pascals-triangle-ii/
 * @conclusion
 */

/**
 * 第三方HashMap实现
 */
struct HashMap {
	/**
	 * 键
	 */
	int key;
	/**
	 * 值
	 */
	int value;
	/**
	 * 三方Hash工具
	 */
	UT_hash_handle hh;
};

int *getRow(int rowIndex, int *returnSize);

int main() {
	//CLion控制台不输出问题,设置缓冲区
	setbuf(stdout, NULL);
	int returnSize = 0;
	int *result = getRow(5, &returnSize);
}

/**
 * 由杨辉三角的性质可得
 * p1:第n行由n个数并且第一个数和最后一个数皆为1,并且从1递增后递减
 * p2:每行的第i个数是其上一行的第i-1位数与第i个数的和, [n][i] = [n-1][i-1] + [n-1][i]
 * 由以上性质可知如果需要获得一个n行的杨辉三角,至少需要定义一个n*n的二维数组
 * 时间复杂度为O(rowIndex^2) 空间复杂度O(n)
 */
int *getRow(int rowIndex, int *returnSize) {
	*returnSize = rowIndex + 1;
	int *result[rowIndex + 1];
	for (int i = 0; i <= rowIndex; ++i) {
		//每行最多i+1个元素
		result[i] = malloc(sizeof(int) * (i + 1));
		for (int j = 0; j <= i; ++j) {
			if (j == 0 || j == i) {
				result[i][j] = 1;
				printf("%d\t", result[i][j]);
			} else {
				result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
				printf("%d\t", result[i][j]);
			}
		}
		printf("\n");
	}

	free(result);
	return result[rowIndex];
}

/**
 * 力扣官方题解
 */
int *getRow_Offical(int rowIndex, int *returnSize) {
	*returnSize = rowIndex + 1;
	int *C[rowIndex + 1];
	for (int i = 0; i <= rowIndex; ++i) {
		C[i] = malloc(sizeof(int) * (i + 1));
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}
	return C[rowIndex];
}

