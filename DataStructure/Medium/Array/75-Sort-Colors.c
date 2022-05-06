#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include <C:\Users\HEXDude\WorkSpace\LeetCode\Library\uthash.h>

/**
 * @author HEXDude
 * @date 2022/5/6
 * @description 给定一个包含红色、白色和蓝色、共n 个元素的数组nums，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 * 我们使用整数 0、1 和 2 分别表示红色、白色和蓝色。
 * 必须在不使用库的sort函数的情况下解决这个问题。
 * @link https://leetcode-cn.com/problems/sort-colors
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

void swap(int *a, int *b);

void sortColors(int *nums, int numsSize);

int main() {
	//CLion控制台不输出问题,设置缓冲区
	setbuf(stdout, NULL);
	int nums[6] = {2, 0, 2, 1, 1, 0};
	int numsSize = 6;
	sortColors(nums, numsSize);
}

/**
 * 交换两个数
 */
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b, *b = temp;
}

/**
 * 不可以使用库提供的API,使用原地,即不能开辟新的内存空间进行计算.
 * 看到的瞬间就想到了双指针,但是与官方的不一样,我的想法是快慢,比较大小,想来实现有点困难.
 * 由于只涉及三个固定的不同的数字,那么完全可以只排序其中两个即可,另外一个必定也会排序.
 * 因此,设置两个指针,一个指向0该插入的地方,一个指向1该插入的方向.
 * 交换0的时候,如果p0 < p1,那么必定存在p0后有已经排序好的1了,那么此时交换出去的是1
 * 1被交换出去了,那么对应的应该将其放入到正确的p1指针上
 */
void sortColors(int *nums, int numsSize) {
	int zeroPointer = 0, onePointer = 0;
	for (int i = 0; i < numsSize; ++i) {
		if (nums[i] == 0) {
			swap(&nums[i], &nums[zeroPointer]);
			if (zeroPointer < onePointer) {
				swap(&nums[i], &nums[onePointer]);
			}
			zeroPointer++;
			onePointer++;
		} else if (nums[i] == 1) {
			swap(&nums[i], &nums[onePointer++]);
		}
	}
}

