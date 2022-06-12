#include "../Library/header.h"

/**
 * @author HEXDude
 * @date 2022-6-12
 * @ref https://leetcode.cn/problems/house-robber/
 * @breif 给定一个数组表示一堆房子和房子里的金额,如果连偷两个
 * 会触发报警,找出你能偷到最大的金额并不触发警报
 */

int rob(int *nums, int numsSize);

int main()
{
    int nums[4] = {1, 2, 3, 1};
    int result = rob(nums, 4);
}

/**
 * 假设只有一间房子，那就偷这间
 * 如果有两间房子，那么偷最大金额那间
 * 但是后面只能间隔一间再偷了
 */
int rob(int *nums, int numsSize)
{
    if (numsSize == 1)
    {
        return nums[0];
    }

    if (numsSize == 2)
    {
        return fmax(nums[0], nums[1]);
    }

    int *dp = calloc(numsSize + 1, sizeof(int));
    //保存每个房子可能偷到的最大金额
    dp[0] = nums[0];
    dp[1] = fmax(nums[0], nums[1]);

    for (int i = 2; i < numsSize; i++)
    {
        //如果当前房子的偷盗金额加上之前间隔一间的房子大于上一间所能
        //偷到的，则取当前房子加间隔
        dp[i] = fmax(dp[i - 2] + nums[i], dp[i - 1]);
    }

    return dp[numsSize - 1];
}