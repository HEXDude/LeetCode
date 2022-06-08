#include "../Library/header.h"

/**
 * @author HEXDude
 * @date 2022-6-6
 * @ref https://leetcode.cn/problems/longest-substring-without-repeating-characters/
 * @breif 给定一个字符串 s ,请你找出其中不含有重复字符的 最长子串 的长度
 */
int lengthOfLongestSubstring(char *s);

int main() {
    char *s = malloc(sizeof(char) * 4);
    strcpy(s, "dvdf");
    int result = lengthOfLongestSubstring(s);
    free(s);
}

int lengthOfLongestSubstring(char *s) {
    int stringLength = strlen(s);
    //由题意可得出,字符串由空格,字母和数字组成,那么可以由ASCII码表代替散列表
    int mapping[128] = {0};
    //最优解,初始化为0
    int result = 0;

    //窗口的左边界与右边界
    int left = 0, right = 0;

    while (right < stringLength) {
        //如果当前右边界遍历到的元素不是重复的,则将其坐标记录到mapping中
        if (mapping[s[right]] == 0) {
            mapping[s[right++]] = 1;
            //维护最优解,当前窗口的解即左边界与右边界区间长度[left,right]
            result = fmax(right - left, result);
        }
            //如果当前右边界遍历到的元素存在在mapping中
        else {
            //则从左边界缩小窗口,直到窗口内不再重复位置
            //如果left->right之间还有重复,则会继续移除
            mapping[s[left++]] = 0;
        }
    }

    return result;
}