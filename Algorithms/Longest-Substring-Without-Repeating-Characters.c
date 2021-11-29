/**
 * @Author: HEXDude
 * @Date: 2021/11/29
 * @Description: 无重复字符的最长子串
 * @Reference: https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
 * @Conclusion: 官方的滑窗个人感觉其实和暴力解法没有太大区别，滑窗算法主要体现在
 * 时间复杂度上，为O(n^2)，而使用暴力算法不得不使用HashSet或者再加一个循环检测子
 * 字符串是否存在重复，即O(n^3)，如果使用Java等面向对象等语言使用HashSet（O(1)）
 * 可能会大大提高效率，无奈Leetcode编译器不可以提交别的程序，不然可以尝试写一个
 * HashSet。
 * 主要的核显就是将字符串视为一个一维的数组，滑窗的意思则是分别设置两个"指针Left,Right"
 * right的作用就是始终指向下一个元素，而left则是每次在与right之间发生重复时，则将
 * left移动至发生重复的地方，这之间的距离就是视窗，主要还是如何控制视窗的大小，与双指针类似。
 */

/**
 * Local part
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lengthOfLongestSubstring(char * s);

int main() {
    char *str = "abcabcbb";
    lengthOfLongestSubstring(str);
}

/**
 * Submit part
 */
int lengthOfLongestSubstring(char * s){
    if (s == NULL || s[0] == '\0') {
        return 0;
    }
    /*
     * 最终结果大小，发生重复的子字符串大小
     * 滑窗的核心：left为表示滑窗的最左侧，如果发生重复
     * 则将left移动到发生重复的地方，right是一个始终自增
     * 的指针，与会被更改的left之间形成一个窗口，每次发生
     * 重复窗口的大小都被更改。
     */
    int maxSize,currentSize;
    int left = 0, right = 1;
    while (s[right] != '\0') {
        for (int i = left; i < right; i++) {
            if (s[right] == s[i]) {
                currentSize = right - left;
                left = i+1;
                maxSize = maxSize < currentSize ? currentSize : maxSize;
            }
        }
        right++;
    }

    /*
     * 最后还需计算一次
     * 因为上面的运算在right指向'\0'时就结束了，
     * 如果没有发生重复，那么这段的长度不会被更新
     */
    currentSize = right - left;
    maxSize = maxSize < currentSize ? currentSize : maxSize;
    printf("MaxSize is %d\n", maxSize);
    return maxSize;
}



