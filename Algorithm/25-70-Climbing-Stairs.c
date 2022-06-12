#include "../Library/header.h"

/**
 * @author HEXDude
 * @date 2022-6-12
 * @ref https://leetcode.cn/problems/climbing-stairs/
 * @breif 假设你正在爬楼梯,需要n阶你才能到达楼顶
 * 每次你可以爬1或2个台阶.你有多少种不同的方法可以爬到楼顶呢?
 */

//动态规划缓存
int * map = NULL;
int recursion(int n);
int climbStairs(int n);

int main()
{
    int result = climbStairs(3);
}

/**
 * 前提:每次只能爬一级或者两级楼梯
 * 假设有n级阶梯,如果先爬1级,那么接下来还有
 * n-1级台阶怎么爬
 * 假设有n级阶梯,如果先爬2级,那么接下来还有
 * n-2级台阶怎么爬
 * 抽象成函数既是:f(n) = f(n-1) + f(n-2)
 */
int recursion(int n) {
    if (n == 1)
    {
        return 1;
    }

    if (n == 2)
    {
        return 2;
    }

    if (map[n] != 0)
    {
        return map[n];
    }
    
    int sum = recursion(n-1) + recursion(n-2);
    map[n] = sum;
    return sum;
}

int climbStairs(int n)
{
    map = calloc(n + 1, sizeof(int));
    return recursion(n);
}
