#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include <C:\Users\HEXDude\WorkSpace\LeetCode\Library\uthash.h>

/**
 * @author HEXDude
 * @date 2022/5/6
 * @description 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。
 * @link https://leetcode-cn.com/problems/merge-intervals
 * @conclusion
 */

/**
 * 第三方HashMap实现
 */
struct HashMap {
	/**
	 * 键
	 */
	int key;
	/**
	 * 值
	 */
	int value;
	/**
	 * 三方Hash工具
	 */
	UT_hash_handle hh;
};

int **merge(int **intervals, int intervalsSize, int *intervalsColSize, int *returnSize, int **returnColumnSizes);

int main() {
	//CLion控制台不输出问题,设置缓冲区
	setbuf(stdout, NULL);
	int intervals[4][2] = {{1,  3},
	                       {2,  6},
	                       {8,  10},
	                       {15, 18}};
	int intervalsSize = 4;
	int *intervalsColSize = &(intervals[0]);
	int **intervalsP = &intervals;
	for (int i = 0; i < 4; ++i) {
		printf("%d\n", intervalsP[i][0]);
	}
	int **result = merge(intervals, intervalsSize, intervalsColSize, NULL, NULL);
}

/**
 * 区间结构体
 */
struct Duration {
	/**
	 * 左端点
	 */
	int left;

	/**
	 * 右端点
	 */
	int right;
};

int cmp(struct Duration *a, struct Duration *b) {
	return a->left - b->left;
}

/**
 * 首先二维数组里每个子元素都是数组,表示一个区间
 * 那将每个区间起始值排序,得到一个左端点递增的二维数组
 */
int **merge(int **intervals, int intervalsSize, int *intervalsColSize, int *returnSize, int **returnColumnSizes) {
	struct Duration durations[intervalsSize];
	/*将所有区间加载进区间结构体数组进行左端点递增排序*/
	for (int i = 0; i < intervalsSize; ++i) {
		durations[i].left = intervals[i][0];
		durations[i].right = intervals[i][1];
	}
	qsort(durations, intervalsSize, sizeof(struct Duration), cmp);

	int **returnInteval = (int **) malloc(sizeof(int *) * intervalsSize);
	*returnColumnSizes = (int *) malloc(sizeof(int) * intervalsSize);
	*returnSize = 0;
	for (int i = 0; i < intervalsSize; i++) {
		if (*returnSize) {
			int preEnd = returnInteval[*returnSize - 1][1];
			if (durations[i].left <= preEnd) {
				//合并
				int maxEnd = fmax(preEnd, durations[i].right);
				returnInteval[*returnSize - 1][1] = maxEnd;
			} else {
				//没有重合的
				int newRow = *returnSize;
				returnInteval[newRow] = (int *) malloc(sizeof(int) * 2);
				returnInteval[newRow][0] = durations[i].left;
				returnInteval[newRow][1] = durations[i].right;
				(*returnColumnSizes)[newRow] = 2;
				*returnSize = *returnSize + 1;
			}
		} else {
			int newRow = *returnSize;
			returnInteval[newRow] = (int *) malloc(sizeof(int) * 2);
			returnInteval[newRow][0] = durations[i].left;
			returnInteval[newRow][1] = durations[i].right;
			(*returnColumnSizes)[newRow] = 2;
			*returnSize = *returnSize + 1;

		}
	}
	return returnInteval;
}