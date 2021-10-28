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
 * @brief 选择第一个字符串的长度作为标准值进行遍历，
 * 根据获得的长度遍历每一个字符串的每一个字符，如果
 * 第i个字符==第i+1个字符，则将其存入结果中返回。
 * 
 * @param strs 字符数组 
 * @param strsSize 字符数组长度
 * @return char* 共同前缀字符
 */
char *longestCommonPrefix(char **strs, int strsSize)
{
    /**
     * 判断字符串数组是否只有一个，是则返回唯一一个字符串
     */
    if (strsSize == 1)
    {
        return strs[0];
    }

    /**
     * 获取字符串数组中长度最短的字符串的长度值
     * 作为遍历游标
     */
    int shortestLength = 0;
    for (int i = 0; i < strsSize; i++)
    {
        if (strlen(strs[i]) == 0)
        {
            return "";
        }

        if (i == 0)
        {
            shortestLength = strlen(strs[i]);
        }
        else
        {
            if (shortestLength >= strlen(strs[i]))
            {
                shortestLength = strlen(strs[i]);
            }
        }
    }

    //申请一块连续的char类型存储空间，大小为最短字符长度，用来存储结果
    // char *result = (char *)malloc(sizeof(char) * shortestLength);
    char *result = calloc(shortestLength + 1, sizeof(char));

    for (int i = 0; i < shortestLength ; i++)
    {
        char commonChar = '\0';
        for (int j = 0; j < strsSize - 1; j++)
        {
            if (strs[j][i] == strs[j + 1][i])
            {
                commonChar = strs[j + 1][i];
            }
            else
            {
                commonChar = '\0';
                break;
            }
        }
        result[i] = commonChar;
    }
    return result;
}

int main()
{
    char *strs[] = {"ab", "a"};
    int strsSize = 2;
    char *p = NULL;
    p = longestCommonPrefix(strs, strsSize);
    printf("%s\n", p);
    return 0;
}