#include "../Library/header.h"

/**
 * @author HEXDude
 * @date 2022-6-11
 * @ref https://leetcode.cn/problems/combinations/
 * @breif 给定两个数字n,k,求[1,n]之间所有n个数的组合
 * 例如4,2返回1,2|1,3|1,4|2,3...
 */

int **combine(int n, int k, int *returnSize, int **returnColumnSizes);

int main()
{
    int returnSize = 0;
    int **returnColumnSizes = malloc(sizeof(int *));
    *returnColumnSizes = &returnSize;
    int **result = combine(1, 1, &returnSize, returnColumnSizes);
}

/**
 * @param n 数字
 * @param k 组合的大小
 * @param start 数字回溯的起始位置
 * @param depth 当前回溯路径的深度
 * @param path 当前回溯的路径
 * @param returnSize 结果大小
 * @param returnColumnSizes 结果每列大小
 * @param result 结果
 */
void backTracking(int n, int k, int start, int depth, int *path, int *returnSize, int **returnColumnSizes, int **result)
{
    if (depth == k)
    {
        result[(*returnSize)] = (int *)calloc(k, sizeof(int));
        returnColumnSizes[(*returnSize)] = (int *)calloc(k, sizeof(int));
        memcpy(result[(*returnSize)], path, sizeof(int) * k);
        (*returnSize)++;
        return;
    }

    for (int i = start; i <= n; i++)
    {
        path[depth++] = i;
        backTracking(n, k, i + 1, depth, path, returnSize, returnColumnSizes, result);
    }
}

int **combine(int n, int k, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;
    returnColumnSizes = calloc(10000, sizeof(int *));
    int **result = calloc(10000, sizeof(int *));

    int *path = (int *)calloc(k + 1, sizeof(int));
    backTracking(n, k, 1, 0, path, returnSize, returnColumnSizes, result);

    return result;
}