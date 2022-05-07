#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include <C:\Users\HEXDude\WorkSpace\LeetCode\Library\uthash.h>

/**
 * @author HEXDude
 * @date 2022/5/7
 * @description 给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
 * 你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
 * @link https://leetcode-cn.com/problems/rotate-image/
 * @conclusion
 */

void rotate(int **matrix, int matrixSize, int *matrixColSize);

int main() {
	//CLion控制台不输出问题,设置缓冲区
	setbuf(stdout, NULL);
	int matrixSize = 3;
	int **matrix = (int *) malloc(sizeof(int *) * matrixSize);
	int fillCount = 0;
	for (int i = 0; i < matrixSize; ++i) {
		matrix[i] = malloc(sizeof(int) * 3);
		for (int j = 0; j < matrixSize; ++j) {
			matrix[i][j] = ++fillCount;
		}
	}

	rotate(matrix, matrixSize, &matrixSize);
	free(matrix);
}

/**
 * 矩阵顺时针旋转90度可以分解为两个步骤
 * 1.左上-右下为轴翻转
 * 1 2 3    1 4 7
 * 4 5 6 -> 2 5 8
 * 7 8 9    3 6 9
 * 2.再以翻转后的矩阵竖轴中心翻转
 * 1 4 7    7 4 1
 * 2 5 8 -> 8 5 2
 * 3 6 9    9 6 3
 */
void rotate(int **matrix, int matrixSize, int *matrixColSize) {
	/**
	 * 第一步,左上-右下翻转矩阵
	 * 交换轴两侧的值
	 */
	for (int i = 0; i < matrixSize; ++i) {
		for (int j = 0; j < i; ++j) {
			int temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}

	/**
	 * 第二步,延竖轴中心位置交换相对位置的数
	 * 不用考虑列数行数的奇数问题,利用int型特性/2-1可得只需要交换的右半边
	 */
	for (int i = 0; i < matrixSize; ++i) {
		for (int j = 0; j < matrixSize / 2; ++j) {
			int temp = matrix[i][j];
			matrix[i][j] = matrix[i][matrixSize - j - 1];
			matrix[i][matrixSize - j - 1] = temp;
		}
	}
}

