/**
 * @author HEXDude
 * @date 2022/1/1
 * @description 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
 * 你可以按任意顺序返回答案。
 * @reference https://leetcode-cn.com/problems/two-sum/
 * @conclusion 抄的，手写Hash表太麻烦了
 * TODO 使用高级语言建立HASH表重新实现
 */
#include <malloc.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main() {
    int nums[4] = {2,7,11,15};
    int numsSize = 4, target = 9;
    int *returnSize = NULL;
    int *result = NULL;

    result = twoSum(nums, numsSize, target, returnSize);
    for (int i = 0; i < 2; ++i) {
        printf("The answer position is %d\n", *(result++));
    }
    free(result);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for (int i = 0; i < numsSize; ++i) {
        for (int j = i + 1; j < numsSize; ++j) {
            if (nums[i] + nums[j] == target) {
                int* ret = malloc(sizeof(int) * 2);
                ret[0] = i, ret[1] = j;
                *returnSize = 2;
                return ret;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}
