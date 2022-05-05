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
	int returnSize[0];
	intersect(nums1, 3, nums2, 1, returnSize);
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {

	//根据题意得出数组中最大的数不超过1000，所以定义一个下标到1001的'Hash'表
	int table[1001];
	//将'Hash'表中所有点置为NULL
	memset(table, NULL, sizeof(table));
	//交集结果必定小于等于任意一个数组长度
	int *answer = (int *)malloc(sizeof (int) * nums1Size);
	//定义循环的遍历Index
	int nums1Index = 0, nums2Index = 0, answerIndex = 0;

	while (nums1Index < nums1Size || nums2Index < nums2Size) {
		if (nums1Index < nums1Size) {
			//将Nums1中出现的所有元素按元素值->下标添加到'Hash'表中
			table[nums1[nums1Index++]] += 1;
		} else if (nums1Index == nums1Size && nums2Index < nums2Size) {
			/*
			 * 遍历Nums2
			 * 题目中的取出现次数较小数，那么此处的小可以理解为，只要交一次，就保存到结果表中
			 * 再遇到时不再添加，而是新创建一个节点储存。
			 */
			if (table[nums2[nums2Index]] > 0) {
				answer[answerIndex++] = nums2[nums2Index];
				table[nums2[nums2Index++]] -= 1;
			} else {
				nums2Index++;
			}
		}
	}

	*returnSize = answerIndex;
	return answer;
}