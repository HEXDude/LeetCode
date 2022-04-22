#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @author HEXDude
 * @date 2022/4/21
 * @description 请你判断一个 9 x 9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。
 * 数字 1-9 在每一行只能出现一次。
 * 数字 1-9 在每一列只能出现一次。
 * 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
 * @reference https://leetcode-cn.com/problems/valid-sudoku/
 * @conclusion
 */

bool isValidSudoku(char** board, int boardSize, int* boardColSize);

int main() {
	char sudoku[9][9] = {{"5","3",".",".","7",".",".",".","."},
						{"6",".",".","1","9","5",".",".","."},
						{".","9","8",".",".",".",".","6","."},
						{"8",".",".",".","6",".",".",".","3"},
						{"4",".",".","8",".","3",".",".","1"},
						{"7",".",".",".","2",".",".",".","6"},
						{"7",".",".",".","2",".",".",".","6"},
						{".","6",".",".",".",".","2","8","."},
						{".",".",".","4","1","9",".",".","5"},
						{".",".",".",".","8",".",".","7","9"}};
	isValidSudoku(sudoku, 9, sudoku[0]);
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
	for (int i = 0; i < boardSize; ++i) {
		for (int j = 0; j < boardSize; ++j) {
			printf("%s", board[i][j]);
		}
	}

	return true;
}