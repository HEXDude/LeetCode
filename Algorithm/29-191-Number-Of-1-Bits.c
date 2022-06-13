#include "../Library/header.h"

/**
 * @author HEXDude
 * @date 2022-6-13
 * @ref https://leetcode.cn/problems/number-of-1-bits/
 * @breif 编写一个函数,输入是一个无符号整数(以二进制串的形式),
 * 返回其二进制表达式中数字位数为 '1' 的个数(被称为汉明重量)
 */

int hammingWeight(uint32_t n);

int main()
{
    int result = hammingWeight(00000000000000000000000000001011);
}

int hammingWeight(uint32_t n) {
    int ret = 0;
    for (int i = 0; i < 32; i++) {
        if (n & (1u << i)) {
            ret++;
        }
    }
    return ret;
}