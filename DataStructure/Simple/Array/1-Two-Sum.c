#include "../../../Library/header.h"

/**
 * @author HEXDude
 * @date 2022/4/19
 * @description 给定一个整数数组nums和一个整数目标值target,请你在该数组中找出和为目标值target的那两个整数,并返回它们的数组下标.
 * @link https://leetcode-cn.com/problems/two-sum/
 * @conclusion 建立HashMap并遍历数组元素,如果HashMap中存在target-nums[i],则说明此数组存在两数之和解,不存在则将nums[i]的值
 * 作为key,i作为值存入HashMap中.
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

/**
 * 定义全局HashMap
 */
struct HashMap *map = NULL;

struct HashMap *findByKey(int key);

void addOrReplace(int key, int value);

int *twoSum(int *nums, int numsSize, int target, int *returnSize);

int main() {
	int nums[4] = {2, 7, 11, 15};
	int *resultSize = malloc(sizeof(int) * 2);
	memset(resultSize, 0, sizeof(*resultSize));
	twoSum(nums, sizeof(nums) / sizeof(int), 9, resultSize);
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
	for (int i = 0; i < numsSize; ++i) {
		struct HashMap *tempMap = findByKey(target - nums[i]);
		if (tempMap == NULL) {
			addOrReplace(nums[i], i);
		} else {
			int *result = malloc(sizeof(int) * 2);
			result[0] = i;
			result[1] = tempMap->value;
			*returnSize = 2;
			return result;
		}
	}

	HASH_CLEAR(hh, map);
	*returnSize = 0;
	return NULL;
}

/**
 * 根据Key查询HashMap
 */
struct HashMap *findByKey(int key) {
	struct HashMap *tmp;
	HASH_FIND_INT(map, &key, tmp);
	return tmp;
}

/**
 * 根据key添加键值对
 * 如果key已存在则修改value
 */
void addOrReplace(int key, int value) {
	struct HashMap *query = findByKey(key);
	if (query == NULL) {
		struct HashMap *tmp = malloc(sizeof(struct HashMap));
		tmp->key = key;
		tmp->value = value;
		HASH_ADD_INT(map, key, tmp);
	} else {
		query->value = value;
	}
}
