/**
 * @file REVERSE_INTEGER.c
 * @author HEXDude
 * @date 2021-10-13
 * @see <a href = "https://leetcode-cn.com/problems/reverse-integer/">Reverse integer</a>
 */

#include <stdio.h>

#define MAX_SIGNED_INTEGER_NEGATIVE -2147483647
#define MAX_SIGNED_INTEGER_POSITIVE 2147483647

int main() {
    int former = 123;
    int reverse = 0;
    while (former !=0)
    {

        //在进入下一次循环前如果大于或者小于有符号整型最大范围则return 0
        if(reverse < MAX_SIGNED_INTEGER_NEGATIVE/10 || reverse > MAX_SIGNED_INTEGER_POSITIVE/10 ) {
            return 0;
        }
        int tempR = former%10;
        former = former/10;
        printf("TempR is %d \n", tempR);
        printf("Former is%d \n", former%10);
        reverse = reverse*10 + tempR;
        printf("Reverse is %d \n", reverse);
    }
    
    return reverse;
}