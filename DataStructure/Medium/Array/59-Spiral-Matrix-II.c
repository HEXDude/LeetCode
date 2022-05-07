#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include <C:\Users\HEXDude\WorkSpace\LeetCode\Library\uthash.h>

/**
 * @author HEXDude
 * @date 2022/5/5
 * @description 给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
 * @link https://leetcode-cn.com/problems/spiral-matrix-ii/
 * @conclusion
 */

int **generateMatrix(int n, int *returnSize, int **returnColumnSizes);

int main() {
	//CLion控制台不输出问题,设置缓冲区
	setbuf(stdout, NULL);
	int returnSize = 0;
	int **result = generateMatrix(3, &returnSize, &returnSize);
}

/**
 * 根据矩阵和螺旋的特性.将生成数组分成按圈生成
 * 每圈分成四部分.
 * 1 左上->右上-1
 * 2 右上->右下-1
 * 3 右下->左下-1
 * 4 左下->右上-1
 * 可以将算法想象成一个按顺序收缩的过程
 * 例如最开始我们从左至右生成第一行数据的时候,那么该行已经被填充完毕了,
 * 应该标识为已填充,则top++.
 * 如果要填充的数超过了最大的预期数字,那么即超过了边界,结束生成
 */
int **generateMatrix(int n, int *returnSize, int **returnColumnSizes) {
	int **matrix = malloc(sizeof(int *) * n);
	*returnSize = n;
	*returnColumnSizes = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		matrix[i] = malloc(sizeof(int) * n);
		memset(matrix[i], -1, sizeof(int) * n);
		(*returnColumnSizes)[i] = n;
	}

	/**
	 * 要填入的数字
	 */
	int content = 1;
	/**
	 * 填入的最大数
	 */
	int big = n * n;
	/**
	 * 可以将整个算法想象成一个收缩的过程
	 * left 标识矩阵在收缩过程中的左起点(边界)
	 * right 标识矩阵在收缩过程中的右起点(边界)
	 * top 标识矩阵在收缩过程中的上起点(边界)
	 * bottom 标识矩阵在收缩过程中的下起点(边界)
	 */
	int left = 0, right = n - 1, top = 0, bottom = n - 1;
	while (true) {

		/**
		 * 上边
		 * 填充left->right的top行
		 * 填充完毕换行top++
		 */
		for (int i = left; i <= right; ++i) {
			matrix[top][i] = content++;
		}
		top++;
		if (content > big) {
			break;
		}

		/**
		 * 右边
		 * 填充top->bottom的right列
		 * 填充完毕换列right--
		 */
		for (int i = top; i <= bottom; ++i) {
			matrix[i][right] = content++;
		}
		right--;
		if (content > big) {
			break;
		}

		/**
		 * 下边
		 * 填充right->left的bottom行
		 * 填充完毕换行bottom--
		 * 如果bottom < top 即已经填充完所有行了
		 */
		for (int i = right; i >= left; --i) {
			matrix[bottom][i] = content++;
		}
		bottom--;
		if (content > big) {
			break;
		}


		/**
		 * 左边
		 * 填充bottom->top的left列
		 * 填充完毕换列left++
		 * 如果left > right即已经填充完所有列了
		 */
		for (int i = bottom; i >= top; --i) {
			matrix[i][left] = content++;
		}
		left++;
		if (content > big) {
			break;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\r");
	}
	free(matrix);
	return NULL;
}