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

    //获取第一个字符串的字符长度
    int maxLength = strlen(strs[0]);
    //结果储存数组
    char result[maxLength];

    /*
     * 按照'最长长度'遍历所有字符串的字符，
     * 如果存在i == i+1 则证明为公共头部分.
     * 在i与i+1的判断中不需要中间值做判断，
     * 因为如果任意位置出现不一致则不是公共头。
     */
    for (int i = 0; i < maxLength; i++)
    {   
        result[i] = NULL;
        //临时中间变量
        char commonChar;
        for (int j = 0; j < strsSize; j++)
        {

            if (j == (strsSize - 1))
            {
                break;
            }
            if (strs[j][i] == strs[j + 1][i])
            {
                commonChar = strs[j][i];
            }
            else
            {
                commonChar = NULL;
                break;
            }
        }
        result[i] = commonChar;
    }

    char *s = NULL;
    s = result;

    return s;
}

int main()
{
    char *strs[] = {"flower", "flow", "flight"};
    int strsSize = 3;
    char *p = NULL;
    printf("%p", &p);
    printf("%p", p);
    p = longestCommonPrefix(strs,strsSize);
    printf("%c", *p);
    printf("%c", *p+8);
    return 0;
}