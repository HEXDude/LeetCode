#include "../../../Library/header.h"

/**
 * @author HEXDude
 * @date 2022/5/9
 * @description 给你一个整数数组 nums ，判断这个数组中是否存在长度为 3 的递增子序列。
 * 如果存在这样的三元组下标 (i, j, k)且满足 i < j < k ，使得nums[i] < nums[j] < nums[k] ，返回 true ；否则，返回 false 。
 * @link https://leetcode.cn/problems/increasing-triplet-subsequence
 * @conclusion
 */

bool increasingTriplet(int *nums, int numsSize);

int main() {
	//CLion控制台不输出问题,设置缓冲区
	setbuf(stdout, NULL);
	int nums[5] = {9, 8, 4, 5, 6};
	bool result = increasingTriplet(nums, 5);
}

/**
 * 连续的三个元素升序
 * 前提假设first < second已经找到,那么现在遍历数组找第三个数字
 * 如果当前元素大于second,那么就说明找到了
 * 如果当前元素小于second并且大于first,那么说明这才应该是第二个
 * 如果当前元素小于second并且小于first,那么说明没有找到第三个,将此元素设为第三个,继续查找
 */
bool increasingTriplet(int *nums, int numsSize) {

	int first = nums[0], second = INT_MAX;

	for (int i = 1; i < numsSize; ++i) {
		if (nums[i] > second) {
			return true;
		} else if (nums[i] > first) {
			second = nums[i];
		} else {
			first = nums[i];
		}
	}

	return false;
}