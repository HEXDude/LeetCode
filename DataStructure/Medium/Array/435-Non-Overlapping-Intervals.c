#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include <C:\Users\HEXDude\WorkSpace\LeetCode\Library\uthash.h>

/**
 * @author HEXDude
 * @date 2022/5/8
 * @description 给定一个区间的集合intervals，其中 intervals[i] = [starti, endi]。
 * 返回 需要移除区间的最小数量，使剩余区间互不重叠。
 * @link https://leetcode-cn.com/problems/non-overlapping-intervals
 * @conclusion
 */
int comparator(int **a, int **b);

int eraseOverlapIntervals(int **intervals, int intervalsSize, int *intervalsColSize);

int main() {
	//CLion控制台不输出问题,设置缓冲区
	setbuf(stdout, NULL);
	int intervalsSize = 4;
	int intervalsColSize = 2;
	int **intervals = (int **) malloc(sizeof(int *) * intervalsSize);

	int initNumber = 1;
	for (int i = 0; i < intervalsSize; ++i) {
		intervals[i] = malloc(sizeof(int) * 2);
		intervals[i][0] = initNumber++;
		intervals[i][1] = initNumber;
	}
	intervals[3][0] = 1;
	intervals[3][1] = 3;

	int result = eraseOverlapIntervals(intervals, intervalsSize, &intervalsColSize);
	free(intervals);
}

/**
 * 快排比较器
 */
int comparator(int **a, int **b) {
	return (*a)[0] - (*b)[0];
}

/**
 * 将区间按里的所有子区间按递增排序
 * 后DP
 */
int eraseOverlapIntervals(int **intervals, int intervalsSize, int *intervalsColSize) {
	qsort(intervals, intervalsSize, sizeof(int *), comparator);

	//DP
	int dp[intervalsSize];
	for (int i = 0; i < intervalsSize; ++i) {
		dp[i] = 1;
	}

	int maxn = 1;
	for (int i = 1; i < intervalsSize; ++i) {
		for (int j = 0; j < i; ++j) {
			if (intervals[j][1] <= intervals[i][0]) {
				dp[i] = fmax(dp[i], dp[j] + 1);
			}
		}
		maxn = fmax(maxn, dp[i]);
	}
	return intervalsSize - maxn;
}