/**
 * @author HEXDude
 * @date 2021/12/28
 * @description 给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
 * @reference https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/
 * @conclusion Same as the 344
 * TODO HEXDude Need fix
 */
//Local Part Start
//Local Part End
#include <string.h>

//Submit Part start
char* reverseWords(char* s) {
    int length = strlen(s);
    int i = 0;
    while (i < length) {
        int start = i;
        while (i < length && s[i] != ' ') {
            i++;
        }

        int left = start, right = i - 1;
        while (left < right) {
            char tmp = s[left];
            s[left] = s[right], s[right] = tmp;
            left++;
            right--;
        }
        while (i < length && s[i] == ' ') {
            i++;
        }
    }
    return s;
}
//Submit Part End

