#include "../Library/header.h"

/**
 * @author HEXDude
 * @date 2022-6-3
 * @ref https://leetcode.cn/problems/move-zeroes/
 * @breif 给定一个数组 nums,编写一个函数将所有 0 移动到数组的末尾,同时保持非零元素的相对顺序.
 * 请注意 ,必须在不复制数组的情况下原地对数组进行操作.
 */

void moveZeroes(int *nums, int numsSize);

int main() {
    int nums[5] = {0, 1, 0, 3, 12};
    moveZeroes(nums, 5);
}

/**
 * 题目要求必须在原地完成操作
 * 那么可以使用双指针解法
 * 在数组其起始位置设置两个指针 left,right
 * 从right位置开始遍历数组
 * 当right指向的元素非零时,就将其与left指针指向的元素交换并使left指向下一个地址
 * 这么做是将所有非零元素按序排到数组前部
 * 那么对于零如何移动到后部呢
 * 如果left指针并未到达数组长度上限,那么剩余的部分left~numsSize之间的元素
 * 补零即可,因为第一步中是将所有非零元素移动到前部,如果left!=numsSize,说明还有
 * numsSize-left个零
 * 对于题目而言,没有要求地址之类的,所以直接补零就好
 */
void moveZeroes(int *numss, int numsSize) {
    //处理边界值
    if (numsSize <= 1) {
        return;
    }

    int nums[5] = {0, 1, 0, 3, 12};
    int left = 0, right = 0;
    while (right < numsSize) {
        if (nums[right]) {
            nums[left] = nums[right];
            left++;
        }
        right++;
    }

    while (left < numsSize) {
        nums[left++] = 0;
    }
}