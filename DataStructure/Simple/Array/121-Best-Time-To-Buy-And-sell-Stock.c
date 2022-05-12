#include "../../../Library/header.h"

/**
 * @author HEXDude
 * @date 2022/4/20
 * @description 给定一个数组prices,它的第i个元素prices[i]表示一支给定股票第i天的价格.
 * 你只能选择某一天买入这只股票,并选择在未来的某一个不同的日子卖出该股票.设计一个算法来计算你所能获取的最大利润.
 * @link https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
 * @conclusion
 */
int maxProfit(int *prices, int pricesSize);

int main() {
	int nums[6] = {7, 1, 5, 3, 6, 4};
	int result = maxProfit(nums, 6);
}

int maxProfit(int *prices, int pricesSize) {
	//由题意可得最大买入卖出价格为10000
	int maxPrice = 10000;
	//不可能亏本,预设利润为零
	int maxProfit = 0;

	for (int i = 0; i < pricesSize; ++i) {
		if (prices[i] < maxPrice) {
			maxPrice = prices[i];
		} else if (prices[i] - maxPrice > maxProfit) {
			maxProfit = prices[i] - maxPrice;
		}
	}

	return maxProfit;
}