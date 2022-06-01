#include "../Library/header.h"

/**
 * @author HEXDude
 * @date 2022-6-1
 * @ref https://leetcode.cn/problems/binary-search/
 * @breif 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
 */

int search(int *nums, int numsSize, int target);
int recursion(int *nums, int left, int right, int target);

int main()
{
    int nums[6] = {-1, 0, 3, 5, 9, 12};
    int result = search(nums, 6, 9);
}

/**
 * 题意要求使用二分查找解决
 * 二分查找的主要思想为:在一个升序的数组中,取数组中间作为切点
 * 取切点的值与目标值比大小,如果大于目标值,说明目标在切点左侧
 * 反之在右侧
 * 本题用递归+二分查找
 */
int search(int *nums, int numsSize, int target)
{
    return recursion(nums, 0, numsSize - 1, target);
}

/**
 * 递归函数体
 * 终止递归的条件为起点大于终点
 * 递归的状态转移方程为每次比较后的数组与新的起点和终点
 * @param nums 数组
 * @param left 数组起点
 * @param right 数组终点
 * @param target 目标值
 */
int recursion(int *nums, int left, int right, int target)
{

    if (left > right)
    {
        return -1;
    }

    //切点的位置
    int middleIndex = (left + right) / 2;
    //切点的值
    int middleNumber = nums[middleIndex];

    if (middleNumber == target)
    {
        //如果切点的值为目标值,则直接返回
        return middleIndex;
    }
    else if (middleNumber > target)
    {
        //如果切点的值大于目标值,则将切点位置作为数组终点递归
        //数组起点不变
        return recursion(nums, left, middleIndex - 1, target);
    }
    else
    {
        //如果切点的值小于目标值,则将切点位置作为数组起点递归
        //数组终点不变
        return recursion(nums, middleIndex + 1, right, target);
    }
}