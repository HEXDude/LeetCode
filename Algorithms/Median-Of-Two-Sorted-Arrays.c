/**
 * @Author: HEXDude
 * @Date: 2021/11/30
 * @Description: 寻找两个正序数组的中位数
 * @Reference: https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
 * @Conclusion:
 * TODO 未完成
 */

/**
* Local part
*/
#include <stdio.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size);

int main() {
    int nums1[5] = {1, 3, 5, 7, 9};
    int nums2[4] = {2, 4, 6, 8};
    findMedianSortedArrays(nums1, 5, nums2, 4);
}

/**
* Submit part
*/
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){

    int mergedArray[nums1Size+nums2Size];

    for (int i = 0; i < nums1Size+nums2Size; ++i) {
        if (i == nums1Size) {
            break;
        }
        for (int j = 0; j < nums1Size+nums2Size; ++j) {
            if(j == nums2Size) {
                break;
            }
            if(nums2[j] < nums1[i]) {
                mergedArray[j]
            }
        }
    }
    return 0;
}