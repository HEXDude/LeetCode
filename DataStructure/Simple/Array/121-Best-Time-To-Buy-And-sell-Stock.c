/**
 * @author HEXDude
 * @date ${date}
 * @description 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
 * 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
 * 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
 * @reference https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
 * @conclusion
 */
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize);

int main() {
    int nums1[6] = {7,1,5,3,6,4};
    int nums2[5] = {7,6,4,3,1};
	int nums3[3] = {1, 4, 2};
    int nums1Size = 6, nums2Size = 5, nums3Size=  3;
	int x = maxProfit(nums3, nums3Size);
}

int maxProfit(int* prices, int pricesSize) {
	int max = 10000;
	int maxProfit = 0;

	for (int i = 0; i < pricesSize; ++i) {
		if (prices[i] < max) {
			max = prices[i];
		} else if (prices[i] - max > maxProfit) {
			maxProfit = prices[i] - max;
		}
	}

	return maxProfit;
}