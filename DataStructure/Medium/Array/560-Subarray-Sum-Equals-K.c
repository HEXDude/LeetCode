#include "../../../Library/header.h"

/**
 * @author HEXDude
 * @date 2022/5/9
 * @description 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。
 * @link https://leetcode.cn/problems/subarray-sum-equals-k/
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

int subarraySum(int *nums, int numsSize, int k);

int main() {
	//CLion控制台不输出问题,设置缓冲区
	setbuf(stdout, NULL);
	int nums[5] = {1, 2, 1, 2, 1};
	int numsSize = 5;
	int result = subarraySum(nums, numsSize, 3);
}

/**
 * 子数组是连续的
 */
int subarraySum(int *nums, int numsSize, int k) {
	int count = 0, pre = 0;
	struct HashMap *map = NULL;
	struct HashMap *temp = malloc(sizeof(struct HashMap));
	temp->key = 0;
	temp->value = 1;
	HASH_ADD_INT(map, key, temp);

	for (int i = 0; i < numsSize; ++i) {
		pre += nums[i];
		int key = pre - k;
		HASH_FIND_INT(map, &key, temp);

		if (temp != NULL) {
			count += temp->value;
		}
		HASH_FIND_INT(map, &pre, temp);
		if (temp != NULL) {
			temp->value += 1;
		} else {
			temp = malloc(sizeof(struct HashMap));
			temp->key = pre;
			temp->value = 1;
			HASH_ADD_INT(map, key, temp);
		}
	}

	HASH_CLEAR(hh, map);
	return count;
}