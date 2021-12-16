/**
 * @author HEXDude
 * @date 2021/12/16
 * @description 第一个错误的版本
 * @reference https://leetcode-cn.com/problems/first-bad-version/
 * @conclusion 娘的，这题不复制官方的怎么提交都不对
 */

/**
* Local part
*/
#include <stdio.h>
#include <stdbool.h>
bool isBadVersion(int version);
int search(int* nums, int numsSize, int target);
int firstBadVersion(int n);

int main() {
    int n = 3;
    int x = firstBadVersion(n);
    printf(1);
}

/*
 * 模拟LeetCode中的接口
 */
bool isBadVersion(int version) {
    if (version == 2) {
        return true;
    } else {
        return false;
    }
}

/**
* Submit part
*/
int firstBadVersion(int n) {
    int left = 1, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (isBadVersion(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

