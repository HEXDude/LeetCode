#include "../Library/header.h"

/**
 * @author HEXDude
 * @date 2022-6-3
 * @ref https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/
 * @breif 在下标从1开始的非递减数组中,找到满足nums1+num2=target的元素地址并
 * 将其返回,且nums1.index < nums2.index
 * 算法要满足只是用O(n)的空间复杂度
 */

int *twoSum(int *numbers, int numbersSize, int target, int *returnSize);

int main() {
    int nums[4] = {2, 7, 11, 15};
    int returnSize = 0;
    int *result = twoSum(nums, 4, 9, &returnSize);
    free(result);
}

int *twoSum(int *numbers, int numbersSize, int target, int *returnSize) {

    //每个数组必定有答案,且答案为长度为2的数组
    int *result = malloc(sizeof(int) * 2);
    *returnSize = 0;

    int left = 0, right = numbersSize - 1;

    while (left < right) {
        int sum = numbers[left] + numbers[right];

        //如果两个指针指向的元素相加==tareget说明找到了解
        if (sum == target) {
            result[(*returnSize)++] = left + 1;
            result[(*returnSize)++] = right + 1;
            break;
        }
            //如果和小于target,说明左指针指向的值比较小,应当适度的增大
            //由于数组是非递减性质,那么向右移动做指针即可
        else if (sum < target) {
            left++;
        }
            //如果和大于target,说明右指针指向的值比较大,应当适度的减小
            //由于数组是非递减性质,那么向左移动做指针即可
        else {
            right--;
        }
    }

    return result;
}