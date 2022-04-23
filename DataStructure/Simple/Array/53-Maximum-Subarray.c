#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include <C:\Users\HEXDude\WorkSpace\LeetCode\Library\uthash.h>

/**
 * @author HEXDude
 * @date 2022/4/18
 * @description 给你一个整数数组nums,请你找出一个具有最大和的连续子数组(子数组最少包含一个元素)，返回其最大和。
 * @link https://leetcode-cn.com/problems/maximum-subarray/
 * @conclusion 可以将算法想象成一个地毯从数组起始位置滚动到结束位置,在滚动时,每当滚动到一个节点时,此时的和大于之前所有的和,
 * 则取此段为临时最大和,并记录到全局最大值.
 */

int maxSubArray(int *nums, int numsSize);

int compare(int x, int y);

int main() {
	int nums[10] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	int result = maxSubArray(nums, sizeof(nums) / sizeof(int));
}

int maxSubArray(int *nums, int numsSize) {
	/**
	 * 分别定义一个遍历时的临时最大值,用来记录每次遍历时获得的最大值
	 * 和一个全局最大值用来记录整个数组遍历结束后的最大值
	 * 全局最大值取数组中的第一个元素,以防止最大值为负数的情况
	 */
	int tempMax = 0, globalMax = nums[0];

	for (int i = 0; i < numsSize; ++i) {
		//比较当前遍历的数与临时最大值大小,并保持临时最大值为较大值
		tempMax = compare(nums[i], tempMax + nums[i]);
		//比较临时变量值和全局最大值,并保持全局最大值为较大值
		globalMax = compare(tempMax, globalMax);
	}

	return globalMax;
}

/**
 * 比较给定的两个数,任意一个数大于等于另一个数则返回大于等于的数,否则返回另一个.
 * @param x int
 * @param y int
 * @return MAX(x,y)
 */
int compare(int x, int y) {
	if (x >= y) {
		return x;
	} else {
		return y;
	}
}