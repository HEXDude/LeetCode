/**
 * @file MERGE_SORTED_ARRAY.C
 * @author HEXDude
 * @date 2021-10-13
 * @see <a href = "https://leetcode-cn.com/problems/merge-sorted-array/">Merge sorted array</a>
 */

#include <stdio.h>

/**
 * @brief 先直接合并两个数组再排序
 */
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    
    for(int i = 0; i < n; i++) {
        nums1[m+i] = nums2[i];
    }

        for (int i = 0; i < nums1Size; i++) {
        printf("%d\n", nums1[i]);
    }
    
    for (int i = 0; i < nums1Size; i++) {
        for(int j = 0; j <nums1Size-i-1; j++) {
            if (nums1[j] > nums1[j+1]){
                int temp = nums1[j+1];
                nums1[j+1] = nums1[j];
                nums1[j] = temp;
            }
        }
    }
    
    for (int i = 0; i < nums1Size; i++) {
        printf("%d", nums1[i]);
    }
}

int main() {
    int nums1[] = {1, 2, 3, 4, 0, 0, 0};
    int nums2[] = {4, 3, 1};
    int nums1Size = 7, nums2Size = 3, m = 4, n = 3;
    merge(nums1, nums1Size, m, nums2, nums1Size, n);
    return 0;
}