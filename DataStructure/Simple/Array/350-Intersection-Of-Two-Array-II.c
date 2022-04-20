/**
 * @author HEXDude
 * @date ${date}
 * @description 给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，
 * 应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。
 * @reference https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/
 * @conclusion
 */
#include <stdlib.h>
#include <malloc.h>
#include <C:\Users\HEXDude\WorkSpace\LeetCode\Library\uthash.h>
#include <stdio.h>
#include <mem.h>
#define MAX 1000;

/**
 * 第三方HashMap实现
 */
struct HashMap {
    //键
    int key;
    //值
    int value;
    //三方HASH工具
    UT_hash_handle hh;
};

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);

int main() {
    int nums1[3] = {4, 9, 5};
    int nums2[5] = {9, 4, 9, 8, 4};
    int nums1Size = 3, nums2Size = 5;
    intersect(nums1, nums1Size, nums2, nums2Size, NULL);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
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
			 * 题目中的取出现次数较小数，那么此处的小可以捅过num1与nums2结果的运算的到
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