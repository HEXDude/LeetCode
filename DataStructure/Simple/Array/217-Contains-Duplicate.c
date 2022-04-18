/**
 * @author HEXDude
 * @date 2022/1/1
 * @description 给你一个整数数组 nums 。如果任一值在数组中出现 至少两次 ，返回 true ；如果数组中每个元素互不相同，返回 false 。
 * @reference https://leetcode-cn.com/problems/contains-duplicate/
 * @conclusion 最基础的就是双层循环遍历，但是Leetcode会超时，因此必须需要时间复杂度在O(logN)之下的算法。
 * 可想到的有创建一个额外的数组对遍历数据插入，如果同一个位置插入多次，则存在重复。C语言不会实现...
 * TODO O(logN) -> O(n) 使用Hash算法或者动态创建数组插入
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool containsDuplicate_On2(int *nums, int numsSize);
bool containsDuplicate_OlogN(int *nums, int numsSize);
int compare(const void* _a, const void* _b);

int main() {
    int nums[4] = {1,2,3,1};
    bool resultOn2 = containsDuplicate_On2(nums, 4);
    bool resultOn = containsDuplicate_OlogN(nums, 4);
    printf("%d", resultOn2);
    printf("%d", resultOn);
}

/**
 * 双层循环遍历复杂度为O(n^2)
 * @param nums
 * @param numsSize
 * @return bool
 */
bool containsDuplicate_On2(int *nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        for (int j = i+1; j < numsSize; j++) {
            if (nums[i] == nums[j]) {
                return true;
            }
        }
    }
    return false;
}

/**
 * 对数组按从大到小排序，可得任意位置如果下一个相邻节点与之相同，则数组存在重复元素，复杂度为O(logN)
 * @param nums
 * @param numsSize
 * @return bool
 */
bool containsDuplicate_OlogN(int *nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i+1]) {
            return true;
        }
    }
    return false;
}

/**
 * 快排比较器
 * @param _a
 * @param _b
 * @return int
 */
int compare(const void* _a, const void* _b) {
    int a = *(int*)_a, b = *(int*)_b;
    return a - b;
}