/**
 * @file REMOVE_DUPLICATES_FROM_SORTED_ARRAY.c
 * @author HEXDude
 * @date 2021-11/08
 * @see <a href = "https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/">Remove Duplicates From Sorted Array，删除有序数组中的重复项</a>
 */
#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
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
     * 定义快慢指针从1开始遍历
     * 如果快指针遍历的数不等于前面的数‘
     * 则说明此升序数组已遍历的值不重复
     * 则将慢指针移到快指针位置
     * 如果等于，则说明此处发生了连续，则将
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