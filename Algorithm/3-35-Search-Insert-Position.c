#include "../Library/header.h"

/**
 * @author HEXDude
 * @date 2022-6-1
 * @ref https://leetcode.cn/problems/search-insert-position/
 * @breif 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 * 请必须使用时间复杂度为 O(log n) 的算法。
 */

int searchInsert(int *nums, int numsSize, int target);

int main()
{
    int nums[4] = {1, 3, 5, 6};
    int result = searchInsert(nums, 4, 5);
}

/**
 * 数组为无重复的升序数组
 * 且要求必须为O(logN)的算法,那么就二分查找了
 */
int searchInsert(int *nums, int numsSize, int target)
{
    //处理边界值
    if (target < *nums)
    {
        return 0;
    }
    else if (target > nums[numsSize - 1])
    {
        return numsSize;
    }

    int left = 0, right = numsSize - 1;
    //插入的目标下标
    int answer = numsSize;

    while (left <= right)
    {
        int middleIndex = left + (right - left) / 2;
        int middleNumber = nums[middleIndex];

        //如果切点的值小于目标值,说明要找的数或待插入的位置在右侧
        if (middleNumber < target)
        {
            left = middleIndex + 1;
        }
        else
        {
            //如果切点的值等于或大于目标值,则将待插入位置更新为切点的值
            //如果递归条件终止,待插入的位置即为切点的值下标+1或者切点的值
            answer = middleIndex;
            right = middleIndex - 1;
        }
    }

    return answer;
}