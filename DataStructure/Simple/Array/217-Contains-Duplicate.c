#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <C:\Users\HEXDude\WorkSpace\LeetCode\Library\uthash.h>

/**
 * @author HEXDude
 * @date 2022/4/18
 * @description 给你一个整数数组nums
 * 如果任一值在数组中出现至少两次,返回true;
 * 如果数组中每个元素互不相同,返回false.
 * @link https://leetcode-cn.com/problems/contains-duplicate/
 * @conclusion 这一天的思路最简单的应该就是暴力破解,但是会导致超时.
 * 因此可以考虑以下方案:
 * 1.创建一个int[MAX(nums[i])] answer数组,遍历数组,如果遍历元素i在answer[i]中
 *   存在定义,那么说明出现了两次.(不现实,数组大小过大,需要memSet和free).
 * 2.遍历数组元素,建立Hash表,Hash表查找与上面数组法一样且查找复杂度为O(1).
 */

/**
 * 第三方HashMap实现
 */
struct HashSet {
	/**
	 * 键
	 */
	int key;
	/**
	 * 三方Hash工具
	 */
	UT_hash_handle hh;
};

bool containsDuplicate(int *nums, int numsSize);

int main() {
	int nums[4] = {1, 2, 3, 1};
	bool result = containsDuplicate(nums, sizeof(nums) / sizeof(int));
}

bool containsDuplicate(int *nums, int numsSize) {
	//声明一个键值对均为int型的方法全局HashSet用来存储遍历的数组元素
	struct HashSet *set = NULL;

	/**
	 * 遍历数组元素
	 * 每次遍历时声明一个临时的int型的HashSet
	 * 并以遍历的数组元素作为Key进行查找,如果存在则说明出现了两次,则中断并返回.
	 * 如果不存在则为声明的临时HashSet开辟内存空间存入全局的HashSet中.
	 */
	for (int i = 0; i < numsSize; ++i) {
		struct HashSet *tempSet;
		//HashSet的查找时间复杂度均为O(1)
		HASH_FIND_INT(set, nums + i, tempSet);
		if (tempSet != NULL) {
			return true;
		} else {
			tempSet = malloc(sizeof(*tempSet));
			tempSet->key = nums[i];
			HASH_ADD_INT(set, key, tempSet);
		}
	}

	//释放创建的HashMap内存空间
	HASH_CLEAR(hh, set);
	return false;
}