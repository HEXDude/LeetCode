#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include <C:\Users\HEXDude\WorkSpace\LeetCode\Library\uthash.h>

/**
 * @author HEXDude
 * @date 2022/4/19
 * @description 给你两个按非递减顺序排列的整数数组nums1和nums2,另有两个整数m和n
 * 分别表示nums1和nums2中的元素数目.
 * 请你合并nums2到nums1中,使合并后的数组同样按非递减顺序排列.
 * @link https://leetcode-cn.com/problems/merge-sorted-array/
 * @conclusion 非递减,那么就是必递增,使用双指针对两个数组进行遍历,按顺序填入结果中即可.
 */

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n);

int main() {
	int nums1[6] = {1, 2, 3, 0, 0, 0};
	int nums2[3] = {2, 5, 6};
	merge(nums1, 6, 3, nums2, 3, 3);
}

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n) {
	/**
	 * 创建一个数组接收合并数据,大小为nums1+nums2有效数据位大小
	 */
	int result[m + n];
	int tempResult;

	/**
	 * 分别为两个数组创建双指针
	 */
	int nums1Pointer = 0, nums2Pointer = 0;

	while (nums1Pointer < m || nums2Pointer < n) {
		if (nums1Pointer == m) {
			tempResult = nums2[nums2Pointer++];
		} else if (nums2Pointer == n) {
			tempResult = nums1[nums1Pointer++];
		} else if (nums1[nums1Pointer] < nums2[nums2Pointer]) {
			tempResult = nums1[nums1Pointer++];
		} else {
			tempResult = nums2[nums2Pointer++];
		}
		result[nums1Pointer + nums2Pointer - 1] = tempResult;
	}

	for (int i = 0; i != m + n; ++i) {
		nums1[i] = result[i];
	}
}