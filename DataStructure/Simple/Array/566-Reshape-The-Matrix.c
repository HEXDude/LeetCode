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

int **matrixReshape(int **mat, int matSize, int *matColSize, int r, int c, int *returnSize, int **returnColumnSizes);

int main() {
	int mat[2][2] = {{1, 2},
	                 {3, 4}};
	int matSize = 2, r = 1, c = 4;
	matrixReshape(mat, matSize, mat[0], r, c, NULL, NULL);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** nums, int numsSize, int* numsColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
	int m = numsSize;
	int n = numsColSize[0];
	if (m * n != r * c) {
		*returnSize = numsSize;
		*returnColumnSizes = numsColSize;
		return nums;
	}
	*returnSize = r;
	*returnColumnSizes = malloc(sizeof(int) * r);
	int** ans = malloc(sizeof(int*) * r);

	for (int i = 0; i < r; i++) {
		(*returnColumnSizes)[i] = c;
		ans[i] = malloc(sizeof(int) * c);
	}
	for (int x = 0; x < m * n; ++x) {
		ans[x / c][x % c] = nums[x / n][x % n];
	}
	return ans;
}