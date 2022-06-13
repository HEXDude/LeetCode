#include "../Library/header.h"

/**
 * @author HEXDude
 * @date 2022-6-13
 * @ref https://leetcode.cn/problems/power-of-two/
 * @breif 给定一个整数,用位运算判断该数是否是2的冥次方
 */

bool isPowerOfTwo(int n);

int main()
{
    int result = isPowerOfTwo(1);
}

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}