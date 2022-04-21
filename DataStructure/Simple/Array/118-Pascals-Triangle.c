/**
 * @author HEXDude
 * @date 2022/4/21
 * @description 在 MATLAB 中，有一个非常有用的函数 reshape ，它可以将一个 m x n 矩阵重塑为另一个大小不同（r x c）的新矩阵，但保留其原始数据。
 * @reference https://leetcode-cn.com/problems/reshape-the-matrix/
 * @conclusion TODO 重做
 */
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes);

int main() {
	generate(5, NULL, NULL);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
	int** result = malloc(sizeof(int *) * numRows);
	for (int i = 0; i < numRows; ++i) {
		result[i] = malloc(sizeof(int) * numRows);
	}

	for (int i = 0; i < numRows; ++i) {
		for (int j = 0; j < numRows; ++j) {
			printf("%p\r", &(result[i][j]));
		}
	}

	for (int i = 0; i < numRows; ++i) {
		free(result[i]);
	}
	free(result);

	return NULL;
}