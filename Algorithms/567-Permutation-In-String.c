/**
 * @author HEXDude
 * @date 2022/1/11
 * @description 给你两个字符串s1和s2 ，写一个函数来判断 s2 是否包含 s1的排列。如果是，返回 true ；否则，返回 false 。换句话说，s1 的排列之一是 s2 的 子串 。
 * @reference https://leetcode-cn.com/problems/permutation-in-string/
 * @conclusion 题目好难理解，翻译一下应该是有s1,s2两个字符串，s2中可能存在一个连续的字串与s1一致，
 * 但是顺序不一样。Hash不适合这种写入，麻烦。可以分别为两个字符串根据ASCII码排序检索，如果出现则累加。
 * 最终在S2中进行滑窗，如果滑窗的区间值与s1的检索值一样，则true。
 */

/*
 * Local part start
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool checkInclusion(char * s1, char * s2);
bool equals(int * nums1, int * nums2);

int main() {
    char * s1 = "adc";
    char * s2 = "dcda";
    checkInclusion(s1, s2);
}
/*
 * Local part end
 */

/*
 * Submit part start
 */
bool checkInclusion(char* s1, char* s2) {
    int n = strlen(s1), m = strlen(s2);
    if (n > m) {
        return false;
    }
    /*
     * 建立对于S1中字符出现次数的统计数组
     */
    int cnt1[26], cnt2[26];
    memset(cnt1, 0, sizeof(cnt1));
    for (int i = 0; i < n; i++) {
        cnt1[s1[i] - 'a']++;
    }

    for (int i = n-1 ; i < m; ++i) {
        memset(cnt2, 0, sizeof(cnt2));
        for (int j = n - 1; j >= 0; j--) {
            char x = s2[i-j];
            cnt2[s2[i-j] - 'a']++;
        }
        if (equals(cnt1, cnt2)) {
            return true;
        }
    }
    return false;
}

bool equals(int * nums1, int * nums2) {
    for (int i = 0; i < 26; i++) {
        if (nums1[i] != nums2[i]) {
            return false;
        }
    }
    return true;
}
/*
 * Submit part end
 */


