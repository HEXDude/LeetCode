#include "../Library/header.h"

/**
 * @author HEXDude
 * @date 2022-6-2
 * @ref https://leetcode.cn/problems/rotate-array/
 * @breif 给你一个数组,将数组中的元素向右轮转k个位置,其中k是非负数.
 */

void rotate(int *nums, int numsSize, int k);

void reverse(int *nums, int start, int end);

void swap(int *a, int *b);

int main() {
    int nums[7] = {1, 2, 3, 4, 5, 6, 7};
    rotate(nums, 7, 3);
}

void rotate(int *nums, int numsSize, int k) {
    //数组向右转一个数组长度,则数组还是原数组
    //在此基础上可以求偏移量offset
    //即数组是否转动了n倍的数组长度,如果是,取模即可知道每个数字移动的位置
    //将旋转想象成一个圆柱体即可理解
    int offset = k % numsSize;

    //处理边界值
    if (offset == 0) {
        return;
    }

    //先将整个数组反转
    reverse(nums, 0, numsSize - 1);
    //反转高位
    reverse(nums, 0, offset - 1);
    //反转低位
    reverse(nums, offset, numsSize - 1);
}

/**
 * 根据起始点,结束点反转之间的数组元素
 * @param *nums 数组
 * @param start 起始点
 * @param end 结束点
 */
void reverse(int *nums, int start, int end) {
    while (start < end) {
        swap(&nums[start], &nums[end]);
        start += 1;
        end -= 1;
    }
}

/**
 * 交换两个指针指向的变量
 * @param a
 * @param b
 */
void swap(int *a, int *b) {
    int t = *a;
    *a = *b, *b = t;
}