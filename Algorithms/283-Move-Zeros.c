/**
 * @author HEXDude
 * @date 2021/12/18
 * @description 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 * @reference https://leetcode-cn.com/problems/move-zeroes/
 * @conclusion 还是双指针，左指针永远指向数组中第一个出现的0的交换后的位置，而右指针始终迭代向下，
 * 如果遇到非零元素，则将其与左指针元素交换并更新左指针位置。时间复杂度O(n)，空间复杂度O(1)=>数组长度
 */

/**
 * Local Part
 */
#include <stdio.h>
void moveZeroes(int* nums, int numsSize);
void swap(int * nums, int left, int right);

int main() {
    int nums[5] = {1};
    int numsSize = 1;
    moveZeroes(nums, numsSize);
}

/**
 * Submit part
 */
void moveZeroes(int* nums, int numsSize){
    int left, right = 0;
    while (right < numsSize) {
        if (nums[right] != 0) {
            swap(nums, left , right);
            left++;
        }
        right++;
    }
}

void swap(int * nums, int left, int right) {
    int temp = nums[right];
    nums[right] = nums[left];
    nums[left] = temp;
}

/**
 * Official version
 * @param a
 * @param b
 */
//void swap(int *a, int *b) {
//    int t = *a;
//    *a = *b, *b = t;
//}