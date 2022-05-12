#include "../../../Library/header.h"

/**
 * @author HEXDude
 * @date 2022/5/8
 * @description 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
 * 每行的元素从左到右升序排列。
 * 每列的元素从上到下升序排列。
 * @link https://leetcode-cn.com/problems/search-a-2d-matrix-ii/
 * @conclusion
 */

bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize, int target);

int main() {
	//CLion控制台不输出问题,设置缓冲区
	setbuf(stdout, NULL);
	int matrixSize = 3;
	int **matrix = (int **) malloc(sizeof(int *) * matrixSize);

	int initNumber = 1;
	for (int i = 0; i < matrixSize; ++i) {
		matrix[i] = malloc(sizeof(int) * 3);
		for (int j = 0; j < matrixSize; ++j) {
			matrix[i][j] = initNumber++;
		}
	}

	bool result = searchMatrix(matrix, matrixSize, &matrixSize, 6);
	free(matrix);
}

/**
 * 可以暴力遍历矩阵所有元素,判断target是否存在即可.
 * 但是题目要求一个高效的算法,那么可以根据矩阵的两个性质得知:
 * 每一行都是从左至右递增的,那么二分查找矩阵的每一行,相较于普通
 * 暴力遍历每次至少节省每一行一半数据的开支.时间复杂度由
 * O(mn)降到O(mLogN)
 */
bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize, int target) {
	int colSize = *matrixColSize;
	for (int i = 0; i < matrixSize; ++i) {
		int left = 0, right = colSize - 1;
		while (left <= right) {
			int mid = (right - left) / 2 + left;
			if (matrix[i][mid] == target) {
				return true;
			} else if (matrix[i][mid] > target) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}
	}

	return false;
}