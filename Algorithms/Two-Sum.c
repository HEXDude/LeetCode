//
// Created by HEXDude on 2021/11/27.
// Description: 两数之和
// Reference: https://leetcode-cn.com/problems/two-sum/
// Conclusion: 时间复杂度O(n^2) 双层遍历数组中的每一个元素，如果存在一个二级
// 循环中的元素等于目标元素-一级循环元素，那么此时的一、二级循环中的元素为题解。
//

//Local part start
#include <malloc.h>
#include "stdio.h"
int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main() {
    //声明参数
    int numsSize = 5, target = 16;
    int *returnSize = NULL;
    int *result = NULL;
    //声明一个5位的一维数组
    int nums[5] = {1, 3, 5, 7, 9};
    /*
     * 声明一个整数类型指
     * 并将一维数组的首地址赋值给该指针
     */
    int *numPointer = NULL;
    numPointer = nums;
    result = twoSum(numPointer, numsSize, target, returnSize);
    for (int i = 0; i < 2; ++i) {
        printf("The answer position is %d\n", *(result++));
    }
    free(result);
    return 0;
}
//Local part end

//Submit part start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (target - nums[i] == nums[j]) {
                //因为题目要求在内存中开辟数组返回
                int *result = malloc(sizeof(int) * 2);
                result[0] = i;
                result[1] = j;
                //满足提交通过要求，本地调试注释掉以免异常
                //*returnSize = 2;
                return result;
            }
        }
    }
    return NULL;
}
//Submit part end

