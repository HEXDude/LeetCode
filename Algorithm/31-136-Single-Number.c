#include "../Library/header.h"

/**
 * @author HEXDude
 * @date 2022-6-14
 * @ref https://leetcode.cn/problems/single-number/
 * @breif 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素
 */

int singleNumber(int *nums, int numsSize);

int main()
{
    int nums[3] = {2, 2, 1};
    int numsSize = 3;
    int result = singleNumber(nums, numsSize);
}

/**
 * 如果需要找出那一个只出现一次的数,必定要遍历整个数组才可以确定.
 * 那么至少需要遍历一次数组,时间复杂度O(n),
 * 解法很多,但是空间复杂度都需要O(n)以上,
 * 官方解法提供了最优解,即无需额外空间的解法.
 * 异或:a^b^a = a^a^b = 0^b = b
 * 那么根据题意里的每个数字都出现两次,只有一个数出现一次,
 * 那么可以将数组转换为一个公式:
 * a^a^b^b^c^c^d = 0^0^0^d = d
 * 我只能说,真的是天才
 */
int singleNumber(int *nums, int numsSize)
{

    int result = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        result = result ^ nums[i];
    }
    return result;
}