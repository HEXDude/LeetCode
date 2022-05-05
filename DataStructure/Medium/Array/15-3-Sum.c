#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include <C:\Users\HEXDude\WorkSpace\LeetCode\Library\uthash.h>

/**
 * @author HEXDude
 * @date 2022/5/5
 * @description 给你一个包含n个整数的数组nums判断nums中是否存在三个元素a，b，c ，使得a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
 * 注意：答案中不可以包含重复的三元组。
 * @link https://leetcode-cn.com/problems/3sum
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

int compareInt(const void *x, const void *y);

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes);

int main() {
	//CLion控制台不输出问题,设置缓冲区
	setbuf(stdout, NULL);
	int nums[4] = {1, -1, -1, 0};
	int numsSize = 4;
	int returnSize = 0;
	int *returnSizeP = &returnSize;
	int **returnColumnSizesP = &returnSizeP;
	int **result = threeSum(nums, numsSize, returnSizeP, returnColumnSizesP);
}

/**
 * 快排比较器
 */
int compareInt(const void *x, const void *y) {
	int *a = (int *) x;
	int *b = (int *) y;
	return *a - *b;
}

/**
 * LeetCode第一题,两数之和,和这个差不多,使用双指针(暴力双重遍历)找到对应的数,此处应该也可以.
 * 暴力三重遍历的结果包括了正确结果,但是也不符合题意,产生了重复.
 * 遂翻开官方题解,官方题解对如何去除重复进行了详细的阐述.
 * 在三重遍历中,保证一层循环a<二层循环b<三层循环d,即可保证只出现a<b<c的顺序而不会出现a,c,b这样的顺序.
 * 那么因此应该对数组顺序就应该按照大小排序,这样使得每层遍历的方向和顺序有序可循.
 */
int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
	*returnSize = 0;
	if (numsSize < 3) {
		*returnColumnSizes = 0;
		return NULL;
	}

	//数组快排(递增)
	qsort(nums, numsSize, sizeof(int), compareInt);

	/**
	 * 分配结果响应空间numsSize*numsSize
	 */
	int **answer = (int **) malloc(sizeof(int *) * numsSize * numsSize);
	*returnColumnSizes = (int *) malloc(sizeof(int *) * numsSize * numsSize);

	for (int i = 0; i < numsSize; ++i) {
		//当且仅当第一次循环或者当前元素与前一个元素不相同时才执行
		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}

		int left = i + 1, right = numsSize - 1;
		while (left < right) {
			int sum = nums[i] + nums[left] + nums[right];
			if (sum == 0) {
				answer[*returnSize] = (int *) malloc(sizeof(int) * 3);
				answer[*returnSize][0] = nums[i];
				answer[*returnSize][1] = nums[left];
				answer[*returnSize][2] = nums[right];
				(*returnColumnSizes)[*returnSize] = 3;
				(*returnSize)++;
				while (left < right && nums[left] == nums[++left]);
				while (left < right && nums[right] == nums[--right]);
			} else if (sum < 0) {
				left++;
			} else {
				right--;
			}
		}
	}
	free(answer);
	return answer;
}


