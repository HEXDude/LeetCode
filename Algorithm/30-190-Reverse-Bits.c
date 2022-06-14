#include "../Library/header.h"

/**
 * @author HEXDude
 * @date 2022-6-14
 * @ref https://leetcode.cn/problems/reverse-bits/
 * @breif 颠倒给定的 32 位无符号整数的二进制位。
 */

uint32_t reverseBits(uint32_t n);

int main()
{
    uint32_t result = reverseBits(00000010100101000001111010011100);
}

/**
 * 按位反转,每反转一次右移一位
 */
uint32_t reverseBits(uint32_t n)
{
    uint32_t res = 0;
    for (int i = 0; i < 32 && n > 0; i++)
    {
        res |= (n & 1) << (32 - i);
        n >>= 1;
    }
    return res;
}