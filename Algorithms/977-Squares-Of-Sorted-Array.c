/**
 * @author HEXDude
 * @date 2021/12/18
 * @description 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
 * @reference   https://leetcode-cn.com/problems/squares-of-a-sorted-array/
 * @conclusion 根据题意可知这是一个递增且存在重复数据的数组，需要使用O(n)复杂度的算法，那么肯定不可以暴力解了。
 * 且由于数组可以有负数，可知最大的数肯定出现在最左边的要么最右边。因此，分别在左右两端设置一个指针，迭代数组，
 * 如果左边的平方值大于等于（存在重复）右边的平方值则将值插入结果尾部，并且使左指针递增，否则右指针递减。
 * 怕在LeetCode里无法提交所以没有使用Math.h里的abs函数，否则可以简洁一点。
 * 空间复杂度和时间复杂度均为O(n)
 */

/**
 * Local Part
 */
#include <stdio.h>
#include <malloc.h>
int* sortedSquares(int* nums, int numsSize, int* returnSize);

int main() {
    int nums[5] = {-7,-3,2,3,11};
    int numsSize,returnSize = 5;
    sortedSquares(nums, 5, 5);
}

/**
 * Submit part
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int * result = malloc(sizeof(int)*numsSize);
    int left = 0 , right = numsSize - 1, resultIndex = numsSize - 1;
    returnSize = numsSize;
    while (resultIndex >= 0) {
        if (nums[left]*nums[left] >= nums[right]*nums[right]) {
            result[resultIndex--] = nums[left]*nums[left];
            left++;
        } else {
            result[resultIndex--] = nums[right]*nums[right];
            right--;
        }
    }
    int j = 0;
    while (j<5) {
        printf("%d\n", result[j]);
        j++;
    }
    free(result);
}