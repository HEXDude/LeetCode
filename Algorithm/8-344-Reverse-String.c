#include "../Library/header.h"

/**
 * @author HEXDude
 * @date 2022-6-4
 * @ref https://leetcode.cn/problems/reverse-string/
 * @breif 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
 * 必须使用原地算法
 */

void reverseString(char *s, int sSize);

int main()
{
    char *str = malloc(sizeof(char) * 5);
    strcpy(str, "hello");
    reverseString(str, strlen(str));
    free(str);
}

/**
 * 所谓反转字符串,其实就是将对应位置的字符交换即可
 * 例如str[0]<->str[sSize]
 * 这样就可以满足题目要求的原地交换了
 * 使用双指针实现,在字符串开头和结尾设置分别设置两个指针
 * left,right
 * 遍历字符串,当left > right时终止遍历
 * 最终执行运算的次数最少为n/2,故此,时间复杂度为O(n)
 */
void reverseString(char *s, int sSize)
{
    //处理边界值
    if (sSize <= 1)
    {
        return;
    }

    int left = 0, right = sSize - 1;

    while (left < right)
    {
        char leftChar = s[left];
        char rightChar = s[right];
        char temp = s[left];
        s[left++] = s[right], s[right--] = temp;
    }

    printf("%s", s);
}