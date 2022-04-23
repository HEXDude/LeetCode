#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include <C:\Users\HEXDude\WorkSpace\LeetCode\Library\uthash.h>

/**
 * @author HEXDude
 * @date 2022/4/22
 * @description 给定一个mxn的矩阵,如果一个元素为0,则将其所在行和列的所有元素都设为0.请使用原地算法.
 * @link https://leetcode-cn.com/problems/set-matrix-zeroes/
 * @conclusion 标记矩阵中的为零元素替换,O(m+n)
 */

void setZeroes(int **matrix, int matrixSize, int *matrixColSize);

int main() {
	int matrix[3][3] = {{1, 1, 1},
	                    {1, 0, 1},
	                    {1, 1, 1}};

	int matrixColSize[3] = {3, 3, 3};
	setZeroes(matrix, sizeof(matrix) / sizeof(matrix[0]), matrixColSize);
}

void setZeroes(int **matrix, int matrixSize, int *matrixColSize) {
	int row = matrixSize;
	int col = matrixColSize[0];

	//如果矩阵中某行某列为空,则将其坐标记录在这两个数组
	int rowMark[row], colMark[col];
	memset(rowMark, 0, sizeof(rowMark));
	memset(colMark, 0, sizeof(colMark));

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (!matrix[i][j]) {
				rowMark[i] = colMark[j] = true;
			}
		}
	}

	/**
	 * 根据标记修改原矩阵
	 */
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (rowMark[i] || colMark[j] ) {
				matrix[i][j] = 0;
			}
		}
	}
}