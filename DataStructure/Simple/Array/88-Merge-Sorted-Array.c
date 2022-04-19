/**
 * @author HEXDude
 * @date 2022/1/1
 * @description 给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
 * 请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
 * @reference https://leetcode-cn.com/problems/merge-sorted-array/
 * @conclusion 非递减，那么必然递增，可得数组已排序。在最优时间复杂度O(n[m+n])的情况下，应该使用双指针。遍历两个数组，
 * 按大小填入合并后的数组即可。
 */

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);

int main() {
    int nums1[6] = {1,2,3,0,0,0};
    int nums2[3] = {2, 5,6};
    int nums1Size = 6, nums2Size = 3;
    merge(nums1, nums1Size,3, nums2, nums2Size, 3);
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    //数组1指针，数组2指针
    int nums1Pointer = 0, nums2Pointer = 0;
    //合并数组
    int sortedArray[m+n];
    //合并数组Index
    int sortArrayIndex = 0;
    //遍历临时变量
    int temp;

    while (nums1Pointer < m || nums2Pointer < n) {
        if (nums1Pointer == m) {
            temp = nums2[nums2Pointer++];
        } else if (nums2Pointer == n) {
            temp = nums1[nums1Pointer++];
        } else if (nums1[nums1Pointer] <= nums2[nums2Pointer]) {
            temp = nums1[nums1Pointer++];
        } else {
            temp = nums2[nums2Pointer++];
        }

        sortedArray[sortArrayIndex++] = temp;
    }

    for (int i = 0; i < m+n; ++i) {
        nums1[i] = sortedArray[i];
    }
}