#include "../Library/header.h"

/**
 * @author HEXDude
 * @date 2022-6-1
 * @ref https://leetcode.cn/problems/first-bad-version/
 * @breif 在版本号数组中以尽量小的调用次数找到错误的版本
 */

int isBadVersion(int version);

int firstBadVersion(int n);

int main() {
    int result = firstBadVersion(5);
}

/**
 * 是否是错误的版本号
 * @param version 版本号
 * @return true
 * @return false
 */
int isBadVersion(int version) {
    if (version == 4) {
        return true;
    } else {
        return false;
    }
}

/**
 * 基于题干和现实,可得知
 * 1.版本号从1开始
 * 2.版本号必定是升序的
 * 3.且必定存在一个错误的版本
 * 4.正确的版本之后都是正确的
 * 那么可以将该数抽象成一个数组并使用二分查找的方法来解决
 * 二分查找的时间复杂度为O(logN),暴力枚举的时间复杂度为O(n)
 * 二分查找解决该题的基本思想
 * 如果切点的值调用isBadVersion返回true,联系第4点,说明错误的版本在左侧
 * 如果返回false,则说明该点可能是第一个错误的版本,也可能不是,因此需要继续去右侧查找是否存在
 * 错误的版本,如果不存在,说明该点就是第一个错误的版本
 */
int firstBadVersion(int n) {
    int left = 1, right = n;
    //递归的终止条件为起点大于终点
    while (left < right) {
        //中间的版本号,也是index
        int middle = left + (right - left) / 2;
        if (isBadVersion(middle)) {
            //如果中间的版本号是正确的,说明错误的版本在切点左侧
            //注意,题干描述为正确的版本之后皆为正确
            right = middle;
        } else {
            //如果是错误的,说明错误之前可能还有更早的错误的版本
            left = middle + 1;
        }
    }
    return left;
}