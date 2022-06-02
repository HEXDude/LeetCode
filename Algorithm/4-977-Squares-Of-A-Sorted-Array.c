#include "../Library/header.h"

/**
 * @author HEXDude
 * @date 2022-6-2
 * @ref https://leetcode.cn/problems/squares-of-a-sorted-array/
 * @breif 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
 */

int *sortedSquares(int *nums, int numsSize, int *returnSize);

int main()
{
    int nums[5] = {-4, -1, 0, 3, 10};
    int returnSize = 0;
    int *result = sortedSquares(nums, 5, &returnSize);
    free(result);
}

/**
 * 题目规定数组非递减,那么必定是递增的,但是可能包含重复元素
 * 且使用双指针或者时间复杂度为O(n)的算法解决.
 * 那么可以有两种解法:利用类库的快排对平方后的数组直接排序,时间复杂度为O(n)
 * 利用双指针排序:
 * 既然数组中可能存在负数,并且我们要得到的是所有数组元素的绝对值的平方值
 * 那么可以找到数组中绝对值最小的那个数将其填入结果数组中的第一位.
 * 并且在绝对值最小的左右两侧各设置一个指针,遍历绝对值最小元素的两侧并比较它们
 * 如果左边指针指向的值小于右边的,则将左边的填入结果中并使左边指针向左移动
 * 反之亦然
 */
int *sortedSquares(int *nums, int numsSize, int *returnSize)
{
    //找出数组中绝对值最小的那个数的位置,初始为数组的第一个元素
    int lowest = abs(nums[0]), lowestIndex = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (abs(nums[i]) <= lowest)
        {
            lowest = abs(nums[i]);
            lowestIndex = i;
        }
    }

    //创建结果数组,Leetcode需要将malloc的元素的size确定,
    //因此我们可以将returnSize赋值为0,用于遍历结果数组并且确定结果数组的大小
    int *result = malloc(sizeof(int) * numsSize);
    *returnSize = 0;

    //因为确定了最小值,可以直接将其填入结果数组的第一位
    result[(*returnSize)++] = lowest * lowest;

    //在最小绝对值两侧设置指针,边界值为0和数组大小
    int toLower = lowestIndex - 1, toBigger = lowestIndex + 1;

    while (toLower >= 0 || toBigger <= numsSize - 1)
    {
        int square;
        //当左边遍历结束时,但右边任然存在元素,并联系数组的性质
        //可以将右边的数组元素平方后按序填入结果中
        if (toLower < 0 && toBigger <= numsSize - 1)
        {
            square = nums[toBigger] * nums[toBigger];
            toBigger++;
        }
        else if (toLower >= 0 && toBigger > numsSize - 1)
        {
            square = nums[toLower] * nums[toLower];
            toLower--;
        }
        else if (toLower >= 0 && toBigger <= numsSize - 1)
        {
            //如果左边指针指向的值小于右边的,则将左边的填入结果中并使左边指针向左移动
            //反之亦然
            int leftSquare = nums[toLower] * nums[toLower];
            int rightSquare = nums[toBigger] * nums[toBigger];
            if (leftSquare < rightSquare)
            {
                square = leftSquare;
                toLower--;
            }
            else
            {
                square = rightSquare;
                toBigger++;
            }
        }

        result[(*returnSize)++] = square;
    }

    return result;
}