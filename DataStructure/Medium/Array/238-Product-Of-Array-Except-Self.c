#include "../../../Library/header.h"

/**
 * @author HEXDude
 * @date 2022/5/9
 * @description 给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
 * @link https://leetcode.cn/problems/product-of-array-except-self/
 * @conclusion
 */

int *productExceptSelf(int *nums, int numsSize, int *returnSize);

int main() {
	//CLion控制台不输出问题,设置缓冲区
	setbuf(stdout, NULL);
	int nums[5] = {1, 2, 3, 4, 5};
	int numsSize = 5;
	int *result = productExceptSelf(nums, numsSize, &numsSize);
}

int *productExceptSelf(int *nums, int numsSize, int *returnSize) {

	int *result = malloc(sizeof(int) * numsSize);
	*returnSize = numsSize;
	/**
	 * 根据题意不可直接使用除法的要求
	 * 那么可以定义两个数组,分别存储从左至右和从右至左的乘积
	 * 那么在寻找nums[i]的答案时即可(left[i -1] * right[i + 1])
	 */
	int *left = malloc(sizeof(int) * numsSize);
	int *right = malloc(sizeof(int) * numsSize);

	for (int i = 0; i < numsSize; ++i) {
		if (i == 0) {
			left[i] = 1 * nums[i];
		} else {
			left[i] = left[i - 1] * nums[i];
		}
	}

	for (int i = numsSize - 1; i >= 0; --i) {
		if (i == numsSize - 1) {
			right[i] = 1 * nums[i];
		} else {
			right[i] = right[i + 1] * nums[i];
		}
	}

	for (int i = 0; i < numsSize; ++i) {
		if (i == 0) {
			result[i] = right[i + 1];
		} else if (i == numsSize - 1) {
			result[i] = left[i - 1];
		} else {
			result[i] = left[i - 1] * right[i + 1];
		}
	}

	for (int i = 0; i < numsSize; ++i) {
		printf("%d\n", result[i]);
	}

	free(left);
	free(right);
	free(result);
	return NULL;
}