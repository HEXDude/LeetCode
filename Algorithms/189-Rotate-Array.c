/**
 * @author HEXDude
 * @date 2021/12/18
 * @description 给你一个数组，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
 * @reference https://leetcode-cn.com/problems/rotate-array/
 * @conclusion
 */

/**
 * Local Part
 */
#include <stdio.h>
void rotate(int* nums, int numsSize, int k);

int main() {
    int nums[7] = {1, 2, 3, 4, 5, 6, 7}, numsSize = 7, k = 3;
    rotate(nums, numsSize, k);
}

/**
 * Submit part
 */
void rotate(int* nums, int numsSize, int k){
    int result[numsSize];
    for (int i = 0; i < numsSize; ++i) {
        result[(i+k)%n] = nums[i];
    }
    for (int i = 0; i < numsSize; ++i) {
        printf("%d", result[i])
    }
}
