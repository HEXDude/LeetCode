#include "../Library/header.h"

/**
 * @author HEXDude
 * @date 2022-6-4
 * @ref https://leetcode.cn/problems/reverse-words-in-a-string-iii/
 * @breif 给定一个字符串s,你需要反转字符串中每个单词的字符顺序,同时仍保留空格和单词的初始顺序.
 */

char *reverseWords(char *s);

int main() {
    int strLength = strlen("Let's take LeetCode contest");
    char *str = malloc(sizeof(char) * strLength);
    strcpy(str, "Let's take LeetCode contest");
    char *result = reverseWords(str);
    free(str);
}

/**
 * 可以将字符串中的单词每个都找出来后反转字符串
 * 反转的方法就是用双指针交换即可
 * 那么如何找出每个单词呢?
 * 根据题意可知
 * 1 不包含开头结尾空格
 * 2 所有单词被空格分隔
 * 因此我们可以遍历数组,当遇到空格时停下来,说明刚刚遍历完一个单词
 * 但是,这样会无法获取到最后一个单词,因为最后一个单词的结尾没有空格
 * 因此我们需要多一个判断条件when index == s.len - 1时
 * 稍微修改一下反转字符串的方法
 */
char *reverseWords(char *s) {
    //处理边界值
    if (strlen(s) <= 1) {
        return s;
    }

    int strLength = strlen(s);

    //设置双指针,left记录单词开始的位置,right记录碰到的一个的空格位置
    int left = 0, right = 0;
    while (right < strLength) {
        //如果遍历到的元素为空格,那么说明left->right-1是一个完整的单词,需要反转
        //如果right==strLength - 1,说明left->right必定是一个完整的单词,但是由于
        //最后一个单词结尾没有空格,所以需要处理一下
        if (s[right] == ' ' || right == strLength - 1) {
            //设置反转字符串用的指针,将指针从空格向左移动到有效的字符上
            //判断一下是否已经到达字符串结尾了,如果是,则不左移动,因为没有空格了
            int reverseRight = right == strLength - 1 ? right : right - 1;

            while (left < reverseRight) {
                char temp = s[left];
                s[left++] = s[reverseRight], s[reverseRight--] = temp;
            }
            //反转完一个单词后,将left移动到下一个单词的起始位置,即空格位置+1
            left = right + 1;
        }
        right++;
    }

    return s;
}