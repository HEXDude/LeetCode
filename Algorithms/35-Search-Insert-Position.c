/**
 * @author HEXDude
 * @date 2021/12/16
 * @description 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 * @reference https://leetcode-cn.com/problems/search-insert-position/
 * @conclusion 升序数组且不重复，则直接遍历数组，遇到相同的或是大于目标的位置即为目标位置或
 * 插入位置，如果遍历结束也没有找到则返回数组长度，即为插入的位置。算法时间复杂度O(n)，虽不符合
 * 题目要求的O(logN)，但是直观、简洁。
 */

/**
* Local part
*/
#include <stdio.h>
int searchInsert(int* nums, int numsSize, int target);
int searchInsertBinarySearch(int* nums, int numsSize, int target);

int main() {
    int target = 7,numsSize = 4;
    int nums[4] = {1,3,5,6};
    int x = searchInsert(nums, numsSize, target);
    int y = searchInsertBinarySearch(nums, numsSize, target);
    printf("%d", x);
    printf("%d", y);
}

/**
* Submit part
*/
int searchInsert(int* nums, int numsSize, int target){
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] >= target) {
            return i;
        }
    }
    return numsSize;
}

int searchInsertBinarySearch(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1, ans = numsSize;
    while (left <= right) {
        int mid = ((right - left) >> 1) + left;
        if (target <= nums[mid]) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}
