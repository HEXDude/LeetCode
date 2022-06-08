#include "../Library/header.h"

/**
 * @author HEXDude
 * @date 2022-6-6
 * @ref https://leetcode.cn/problems/permutation-in-string/
 * @breif 给你两个字符串s1和s2,写一个函数来判断s2是否包含s1的排列.如果是,返回true否则,返回 false.
 */

bool equals(int *mappingS1, int *mappingS2);

bool checkInclusion(char *s1, char *s2);

int main() {
    char *s1 = malloc(sizeof(char) * 2);
    char *s2 = malloc(sizeof(char) * 8);
    strcpy(s1, "ab");
    strcpy(s2, "eidbaooo");
    bool result = checkInclusion(s1, s2);
    free(s1);
    free(s2);
}

bool equals(int *mappingS1, int *mappingS2) {
    for (int i = 0; i < 26; i++) {
        if (mappingS1[i] != mappingS2[i]) {
            return false;
        }
    }

    return true;
}

bool checkInclusion(char *s1, char *s2) {
    int s1Length = strlen(s1);
    int s2Length = strlen(s2);
    //边界值处理
    if (s1Length > s2Length) {
        return false;
    }

    //由于题意可知,两个字符串中均只包含字母,因此可以由ASCII码映射代替HashMap
    int mappingS1[26] = {0};
    int mappingS2[26] = {0};

    /**
     * 对于滑动窗口,由于需要模式识别的关键是:排列是否是字串?因此只需关心字符出现次数即可
     * 那么可以固定窗口的大小为s1的长度,这样每次比对s2窗口中
     * 出现的字符次数是否和s1一致即可
     */

    for (int i = 0; i < s1Length; i++) {
        //初始化s1的字符出现次数
        ++(mappingS1[s1[i] - 'a']);
        //初始化s2的字符出现次数
        ++(mappingS2[s2[i] - 'a']);
    }

    if (equals(mappingS1, mappingS2)) {
        return true;
    }

    //固定窗口,每次向右滑动一格,并将左侧非窗口内数据移除
    for (int i = s1Length; i < s2Length; i++) {
        ++(mappingS2[s2[i] - 'a']);
        --(mappingS2[s2[i - s1Length] - 'a']);
        if (equals(mappingS1, mappingS2)) {
            return true;
        }
    }

    return false;
}