/**
 * @file PARLINDROME_NUMBER.c
 * @author HEXDude
 * @date 2021-10-18
 * @see <a href = "https://leetcode-cn.com/problems/palindrome-number/">Palindrome number</a>
 */

#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x)
{
    if (x>=0 && x<10)
    {
        return true;
    }
    
    if (x%10==0)
    {
        return false;
    }
    
    
    /**
     * @brief 根据官方的思想，回文数一半的前后完全一致，
     * 所以前半部分后半部分一模一样，所有可以只取后半部
     * 分与前半部分比较。
     * 显然需要一个界值来标明运算的中止，因此，界值为取
     * 出的后半部分大于前半部分。
     */
    int midNum = 0;
    while (x > midNum)
    {
        //每次运算后midNum为上一次的值（低权位*10）加上此次取模余数
        midNum = midNum * 10 + x % 10;
        //每次运算后x为x/10（整形后的每次去除低权位数字）
        x = x / 10;
    }

    if (x == midNum || x == midNum/10)
    {
        return true;
    }
    

    return false;
}

int main()
{
    bool x = isPalindrome(12241);
    printf("%d", x);
    return 0;
}