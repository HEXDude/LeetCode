/**
 * @file VALID_PARENTHESES.c
 * @author HEXDude
 * @date 2021-10-28
 * @see <a href = "https://leetcode-cn.com/problems/valid-parentheses/">Valid Parentheses,有效的括号</a>
 */
#include <stdio.h>
#include <stdbool.h>
#include <strings.h>
#include <string.h>

/**
 * @brief 获取括号的另一半
 * 
 * @param bracket 括号字符
 * @return char 括号另一半字符
 */
char getPairBracket(char bracket)
{
    if (bracket == '(')
    {
        return ')';
    }
    else if (bracket == '{')
    {
        return '}';
    }
    else if (bracket == '[')
    {
        return ']';
    }
    return 0;
}

/**
 * @brief 判断字符串中出现的括号是否有效成对
 * 
 * @param s 待判断的字符串
 * @return bool 有效||无效
 */
bool isValid(char *s)
{

    /**
     * @brief 如果字符串长度为奇数则无效
     * 遍历字符串中的元素,初始化一个数组
     * 表达为栈并初始化栈顶指针为0,如果
     * 遍历元素为左括号,则将其另一半存入
     * 栈中.如果不是左括号,则在栈中取最新
     * 的元素,如果两者不相等则不合法.
     * 
     */

    int strLength = strlen(s);
    if (strLength % 2 == 1)
    {
        return false;
    }

    //字符栈
    char stack[strLength];
    //栈顶指针
    int top = 0;

    for (int i = 0; i < strLength; i++)
    {
        //当前括号的另一半
        char pairBracket = getPairBracket(s[i]);

        //如果另一半不为空则说明是左括号,将另一半存入栈中
        //如果不是左括号且又是第一位,必定为不合法.
        if (pairBracket)
        {
            stack[top++] = pairBracket;
        }
        else if (i == 0 || top == 0)
        {
            return false;
        }
        else if (s[i] == stack[top - 1])
        {
            top--;
        }
        else
        {
            return false;
        }
    }

    if (top != 0)
    {
        return false;
    }

    return true;
}

int main()
{
    char *str = "(){}}{";
    bool x = isValid(str);
    return 0;
}