#include "../../../Library/header.h"

/**
 * @author HEXDude
 * @date 2022/5/5
 * @description 给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
 * @link https://leetcode-cn.com/problems/majority-element/
 * @conclusion 还存在时间复杂度为O(logN)或空间复杂度为O(1)的算法,但是不是太明白含义.
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

int majorityElement(int *nums, int numsSize);

int main() {
	int nums[3] = {3, 2, 3};
	int numsSize = 3;
	int result = majorityElement(nums, numsSize);
}

/**
 * 遍历数组元素,将所有元素插入到HashMao中,
 * 如果HashMap中的元素>=k/2,那么既是解.
 * 插入和查找的时间复杂度均为O(n),空间复杂度因为HashMap
 * 需要存储k个键值对,那么空间复杂度也为O(n)个.
 */
int majorityElement(int *nums, int numsSize) {
	if (numsSize == 0 || nums == NULL) {
		return 0;
	}
	if (numsSize == 1) {
		return nums[0];
	}
	struct HashMap *map = NULL;
	int k = numsSize / 2;
	for (int i = 0; i < numsSize; ++i) {
		struct HashMap *temp;
		HASH_FIND_INT(map, nums + i, temp);
		if (temp != NULL) {
			if (temp->value + 1 > k) {
				return temp->key;
			} else {
				temp->value += 1;
			}
		} else {
			temp = malloc(sizeof(struct HashMap));
			temp->key = nums[i];
			temp->value = 1;
			HASH_ADD_INT(map, key, temp);
		}
	}
	return 0;
}
