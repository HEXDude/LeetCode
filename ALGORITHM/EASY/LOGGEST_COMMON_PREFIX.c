/**
 * @file LOGGEST_COMMON_PREFIX.c
 * @author HEXDude
 * @date 2021-10-26
 * @see <a href = "https://leetcode-cn.com/problems/longest-common-prefix/">Loggest Common Prefix,最长共同前缀</a>
 */
#include <stdio.h>
#include <string.h>
#include <math.h>

/**
 * @brief 选取传入的字符串数组中长度最短的一个对所有字符串进行遍历,
 * 每次遍历时如果三个下表地址指向的是同一个字符,则说明是公共的前缀.
 * 如果最短的直到遍历结束也没有出现不同,那么说明最短的就是公共的前缀.
 * 否则只要出现不同,就将当前遍历过的字符串返回.
 * 
 * @param strs 字符数组 
 * @param strsSize 字符数组长度
 * @return char* 共同前缀字符
 */
char *longestCommonPrefix(char **strs, int strsSize)
{

    //定义最长字符
    int maxLength = 0;
    fmax(0,1);

    for (int i = 0; i < strsSize; i++)
    {
        char *p = NULL;
        p = *strs++;
        int tempLength = strlen(p);
        if (tempLength >= maxLength)
        {
            maxLength = tempLength;
        }
    }

    for (int i = 0; i < strsSize; i++)
    {
        for (size_t i = 0; i < maxLength; i++)
        {
            /* code */
        }
        
    }

    printf("%d", maxLength);
    return "1";
}

int main()
{
    char *strs[] = {"f", "flow", "flight"};
    int strsSize = 3;
    longestCommonPrefix(strs, strsSize);
    return 0;
}