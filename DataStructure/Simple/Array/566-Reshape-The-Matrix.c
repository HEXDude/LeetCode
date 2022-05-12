#include "../../../Library/header.h"

/**
 * @author HEXDude
 * @date 2022/4/21
 * @description 在MATLAB中,有一个非常有用的函数reshape,它可以将一个mxn矩阵重塑为另一个大小不同(rxc)的新矩阵.但保留其原始数据.
 * 给你一个由二维数组mat表示的mxn矩阵,以及两个正整数r和c,分别表示想要的重构的矩阵的行数和列数.
 * 重构后的矩阵需要将原始矩阵的所有元素以相同的行遍历顺序填充.
 * 如果具有给定参数的reshape操作是可行且合理的,则输出新的重塑矩阵;否则,输出原始矩阵.
 * @link https://leetcode-cn.com/problems/reshape-the-matrix/
 * @conclusion
 */

int **matrixReshape(int **mat, int matSize, int *matColSize, int r, int c, int *returnSize, int **returnColumnSizes);

int main() {
	int mat[2][2] = {{1, 2},
	                 {3, 4}};

	int returnSize = 0;
	int *p = &returnSize;
	matrixReshape(mat, 2, mat[0], 1, 4, p, &p);
}

int **
matrixReshape(int **nums, int numsSize, int *numsColSize, int r, int c, int *returnSize, int **returnColumnSizes) {
	int m = numsSize;
	int n = numsColSize[0];
	if (m * n != r * c) {
		*returnSize = numsSize;
		*returnColumnSizes = numsColSize;
		return nums;
	}
	*returnSize = r;
	*returnColumnSizes = malloc(sizeof(int) * r);
	int **ans = malloc(sizeof(int *) * r);

	for (int i = 0; i < r; i++) {
		(*returnColumnSizes)[i] = c;
		ans[i] = malloc(sizeof(int) * c);
	}
	for (int x = 0; x < m * n; ++x) {
		ans[x / c][x % c] = nums[x / n][x % n];
	}
	return ans;
}