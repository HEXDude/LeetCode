#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include <C:\Users\HEXDude\WorkSpace\LeetCode\Library\uthash.h>

/**
 * @author HEXDude
 * @date 2022/4/21
 * @description 给定一个非负整数numRows,生成杨辉三角的前numRows行.
 * 在杨辉三角中,每个数是它左上方和右上方的数的和.
 * 如果数组中每个元素互不相同,返回false.
 * @link https://leetcode-cn.com/problems/pascals-triangle/
 * @conclusion
 */

int **generate(int numRows, int *returnSize, int **returnColumnSizes);

int main() {
	int returnSize[0];
	int returnColumnSizes[0][0];
	generate(5, returnSize, returnColumnSizes);
}

int **generate(int numRows, int *returnSize, int **returnColumnSizes) {
	int **ret = malloc(sizeof(int *) * numRows);
	*returnSize = numRows;
	*returnColumnSizes = malloc(sizeof(int) * numRows);
	for (int i = 0; i < numRows; ++i) {
		ret[i] = malloc(sizeof(int) * (i + 1));
		(*returnColumnSizes)[i] = i + 1;
		ret[i][0] = ret[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
		}
	}
	return ret;
}