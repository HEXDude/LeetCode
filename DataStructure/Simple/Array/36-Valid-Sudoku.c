#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include <C:\Users\HEXDude\WorkSpace\LeetCode\Library\uthash.h>

/**
 * @author HEXDude
 * @date 2022/4/22
 * @description 请你判断一个9x9的数独是否有效.
 * 只需要根据以下规则验证已经填入的数字是否有效即可.
 * 数字1-9在每一行只能出现一次.
 * 数字1-9在每一列只能出现一次.
 * 数字1-9每一个以粗实线分隔的3x3宫内只能出现一次.(请参考示例图)
 * @link https://leetcode-cn.com/problems/valid-sudoku/
 * @conclusion
 */

/**
 * 第三方HashSet实现
 */
struct HashSet {
	/**
	 * 键
	 */
	int key;
	/**
	 * 三方Hash工具
	 */
	UT_hash_handle hh;
};

//行Set
struct HashSet rowSet;

//行Set
struct HashSet colSet;

//3*3Set
struct HashSet squareSet;

bool isValidSudoku(char **board, int boardSize, int *boardColSize);

bool containsOrInsert(int key, struct HashSet *targetSet);

int main() {
	char **sudoku = {"123456789", "123456789", "123456789", "123456789", "123456789", "123456789", "123456789",
	                 "123456789", "123456789"};
	isValidSudoku(sudoku, 9, NULL);
}

bool isValidSudoku(char **board, int boardSize, int *boardColSize) {
	int srcRow = boardSize;
	int srcCol = boardColSize[0];

	int **rowHash = (int **) malloc(sizeof(int *) * 9);
	int **colHash = (int **) malloc(sizeof(int *) * 9);
	int **baxHash = (int **) malloc(sizeof(int *) * 9);
	int i, j;
	for (i = 0; i < 9; i++) {
		rowHash[i] = (int *) malloc(sizeof(int) * 10);    //1-9 10个
		colHash[i] = (int *) malloc(sizeof(int) * 10);    //1-9 10个
		baxHash[i] = (int *) malloc(sizeof(int) * 10);    //1-9 10个

		memset(rowHash[i], 0, sizeof(int) * 10);
		memset(colHash[i], 0, sizeof(int) * 10);
		memset(baxHash[i], 0, sizeof(int) * 10);
	}

	int target;
	for (i = 0; i < srcRow; i++) {
		for (j = 0; j < srcCol; j++) {
			if (board[i][j] != '.') {
				target = board[i][j] - '0';//字符转数字
				//行重复检查
				if (rowHash[i][target])    //存在返回失败
				{
					return false;
				} else {
					rowHash[i][target] = 1;
				}

				//列重复检查
				if (colHash[j][target])    //存在返回失败
				{
					return false;
				} else {
					colHash[j][target] = 1;
				}

				int boxCount;
				boxCount = (i / 3) * 3 + j / 3;
				if (baxHash[boxCount][target])    //存在返回失败
				{
					return false;
				} else {
					baxHash[boxCount][target] = 1;
				}

			}
		}
	}
	return true;
}