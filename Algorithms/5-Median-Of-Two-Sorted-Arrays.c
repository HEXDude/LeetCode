/**
 * @Author: HEXDude
 * @Date: 2021/11/30
 * @Description: 寻找两个正序数组的中位数
 * @Reference: https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
 * @Conclusion: 这题的解法不知道有没有达到要求的O(log(m+n))，但是应该达到了O(m+n)，先
 * 归并排序两个升序数组后获取中位数
 */

/**
* Local part
*/
#include <stdio.h>
#include <malloc.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size);

int main() {
    int nums1[0] = {};
    int nums2[1] = {1};
    double x = findMedianSortedArrays(nums1, 2, nums2, 2);
}

/**
* Submit part
*/
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    /*
     * mergedIndex为合并后的数组迭代指示器
     * maxLength为合并后的数组长度
     */
    int mergedIndex = 0, maxLength = nums1Size + nums2Size;
    /*
     * 申请一块长度为两个数组的和的int类型地址来储存排序后的元素
     */
    double mergedArray[maxLength];

    /*
     * 存在任意数组不为空的情况下进行循环
     * 根据从大到小将元素插入合并数组（排序的方式不影响题目）
     * 如果在任意一个数组为空且另外一个数组不为空，则将
     * 另外一个数组按序插入合并数组，因为是倒序且规定两个
     * 升序的数组，所以不影响
     */
    nums1Size-=1,nums2Size-=1;
    while (nums1Size >= 0 || nums2Size >= 0) {
        if (nums1Size < 0) {
            mergedArray[mergedIndex++] = (double )nums2[nums2Size--];
            continue;
        } else if (nums2Size < 0) {
            mergedArray[mergedIndex++] = (double )nums1[nums1Size--];
            continue;
        }
        if (nums1[nums1Size] >= nums2[nums2Size]) {
            mergedArray[mergedIndex++] = (double )nums1[nums1Size--];
        } else {
            mergedArray[mergedIndex++] = (double )nums2[nums2Size--];
        }
    }

    /*
     * 如果两个数组的长度为偶数，则中间数即为arr[(m+n)/2-1]与arr[(m+n)/2+1]的平均数
     * 奇数则为中间那个数
     */
    if (maxLength%2==0) {
        double result = (mergedArray[maxLength/2-1] + mergedArray[maxLength/2])/2.0000;
        return result;
    } else {
        double result = (double )mergedArray[maxLength/2];
        return result;
    }
}