/**
 * @author HEXDude
 * @date 2021/12/16
 * @description 二分查找
 * @reference https://leetcode-cn.com/problems/binary-search/
 * @conclusion 二分查找，每次在数组中间切一刀，如果切的这一刀切点的值大于需要寻找的数
 * 则去切点左边继续寻找，如果小于则去切点右边找，当左右双指针相等或找到值时结束二分。
 * 此解法是利用两个指针分别指向每一次切过后的新数组。在更现代化的编程语言中可以使用递归，
 * C语言递归似乎过不了LeetCode的检测。
 */

/**
* Local part
*/
#include <stdio.h>
int search(int* nums, int numsSize, int target);

int main() {
    int numsSize = 6, target = 0;
    int nums[6] = {-1,0,3,5,9,12};
    search(nums, numsSize, target);
}

/**
* Submit part
*/
int search(int* nums, int numsSize, int target){
    int left = 0, right = numsSize - 1;
    while (left <= right) {
        int middle = (right - left)/2 + left;
        if (nums[middle] == target) {
            return middle;
        } else if (nums[middle] > target) {
            right = middle - 1;
        } else if (nums[middle] < target) {
            left = middle + 1;
        }
    }
    return -1;
}