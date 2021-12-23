/**
 * @author HEXDude
 * @date 2021/12/18
 * @description 给定一个已按照非递减顺序排序的整数数组numbers ，请你从数组中找出两个数满足相加之和等于目标数 target 。
 * 函数应该以长度为 2 的整数数组的形式返回这两个数的下标值。numbers 的下标 从 1 开始计数 ，所以答案数组应当满足 1 <= answer[0] < answer[1] <= numbers.length 。
 * 你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用相同的元素。
 * @reference https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted
 * @conclusion 经典老番双指针，不多说了
 * TODO HEXDude LeetCode提交超出时间限制
 */

/**
 * Local Part
 */
#include <stdio.h>
#include <malloc.h>

int *twoSum(int *numbers, int numbersSize, int target, int *returnSize);

int main() {
    int numberSize = 4, target = 8;
    int numbers[8] = {1,2,3,4,4,9,56,90};
    int *result = twoSum(numbers, numberSize, target, 2);
    printf("%d\t%d", result[0], result[1]);
}

/**
 * Submit part
 * The return array must be malloced and assume its calls called free.
 */
int *twoSum(int *numbers, int numbersSize, int target, int *returnSize) {
    int left = 0, right = 1;
    int *result = (int *) malloc(sizeof(int) * 2);
    //妥协LeetCode规范
    while (left < numbersSize - 1) {
        if (right == numbersSize) {
            left++;
            right = left+1;
            continue;
        }
        if (numbers[left] + numbers[right] == target) {
            result[0] = left + 1;
            result[1] = right + 1;
            return result;
        } else {
            right++;
        }
    }

    result[0] = -1;
    result[1] = -1;
    return result;
}