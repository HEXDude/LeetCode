/**
 * @file REMOVE_DUPLICATES_FROM_SORTED_ARRAY.c
 * @author HEXDude
 * @date 2021-11/08
 * @see <a href = "https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/">Remove Duplicates From Sorted Array，删除有序数组中的重复项</a>
 */
#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){

    if (numsSize == 0)
    {
        return 0;
    }

    if (numsSize == 1)
    {
        return 1;
    }

    int init = -1;
    int numsSizeCopy = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > init)
        {
            init = nums[i];
            continue;
        }
        if (nums[i] = init)
        {
            numsSizeCopy++;
        }
    }
    return numsSize-numsSizeCopy;
}

int removeDuplicatesPoniter(int* nums, int numsSize){
    if (numsSize == 0)
    {
        return 0;
    }

    if (numsSize == 1)
    {
        return 1;
    }
    
    //定义快慢指针
    int faster = 1, slower = 1;
    
    /**
     * 快慢指针
     * 如果不发生连续，慢指针的值为当前快指针指向的值
     * 该步比较重要，因为如果快慢指针的值相等时进行
     * 交换无所谓。但是快指针经历了一连串连续的值后
     * 可以对慢指针指向的值进行更新
     */
    while (faster < numsSize)
    {
        if (nums[faster] != nums[faster-1])
        {
            nums[slower] = nums[faster];
            slower++;
        }
        faster++;
    }
    return slower;
}

int main() {
    int array[5] = {0,1,2,3,3};
    int size = removeDuplicatesPoniter(array, 5);
}