/**
 * @author HEXDude
 * @date 2021/12/18
 * @description 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组s的形式给出。
 * 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
 * @reference https://leetcode-cn.com/problems/reverse-string/
 * @conclusion 指针似乎有问题
 * TODO HEXDude 待优化
 */

/**
 * Local Part
 */
#include <stdio.h>
void reverseString(char* s, int sSize);

int main() {
    char * s = "HELLO";
    int sSize = 5;
    reverseString(s, sSize);
}


/**
 * Submit part
 */
void reverseString(char* s, int sSize){
    int left = 0, right = sSize - 1;
    while (left < right) {
        char temp = s[left];
        s[left] = &(s[right]);
        s[right] = &temp;
        left++;
        right--;
    }
}