#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include <C:\Users\HEXDude\WorkSpace\LeetCode\Library\uthash.h>

/**
 * @author HEXDude
 * @date 2022/4/20
 * @description 给你两个整数数组nums1和nums2,请你以数组形式返回两数组的交集.
 * 返回结果中每个元素出现的次数,应与元素在两个数组中都出现的次数一致(如果出现次数不一致，则考虑取较小值).可以不考虑输出结果的顺序。
 * @link https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/submissions/
 * @conclusion 遍历较短元素,将其元素填入HashMap中,值为其在较短数组中的次数,再次遍历较长数组,其遍历元素每在HashMap中出现一次并且
 * value > 0,就将key填入结果数组中,并将Map中的出现次数减一.
 * 减1操作主要是要求按最小次数输出.
 * TODO LeetCode执行堆溢出
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
 * 全局HashMap
 */
struct HashMap *map = NULL;

int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize);

int main() {
	int nums1[3] = {3, 1, 2};
	int nums2[1] = {1};
	int *returnSize;
	intersect(nums1, 3, nums2, 1, returnSize);
}

int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize) {

	/**
	 * 取交集运算先取较短数组的值降低时间复杂度
	 */
	if (nums1Size > nums2Size) {
		return intersect(nums2, nums2Size, nums1, nums1Size, returnSize);
	}

	int *result = malloc(sizeof(int) * nums1Size);
	memset(result, NULL, sizeof(*result));
	int resultIndex = 0;

	for (int i = 0; i < nums1Size; ++i) {
		/**
		 * 查找HashMap是否存在当前遍历的数组元素
		 * 如果存在则使其值加一,否则创建值为0
		 */
		struct HashMap *tempMap;
		HASH_FIND_INT(map, nums1 + i, tempMap);
		if (tempMap == NULL) {
			tempMap = malloc(sizeof(*tempMap));
			tempMap->key = nums1[i];
			tempMap->value = 1;
			HASH_ADD_INT(map, key, tempMap);
		} else {
			tempMap->value += 1;
		}
	}

	for (int i = 0; i < nums2Size; ++i) {
		struct HashMap *tempMap;
		HASH_FIND_INT(map, nums2 + i, tempMap);
		if (tempMap != NULL && tempMap->value > 0) {
			result[resultIndex++] = tempMap->key;
			tempMap->value -= 1;
		}
	}

	for (int i = 0; i < resultIndex; ++i) {
		printf("%d\n", result[i]);
	}

	returnSize = resultIndex;
	HASH_CLEAR(hh, map);
	free(result);
	return result;
}