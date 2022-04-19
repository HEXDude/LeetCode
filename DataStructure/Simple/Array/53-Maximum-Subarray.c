/**
 * @author HEXDude
 * @date 2022/4/18
 * @description 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * @reference https://leetcode-cn.com/problems/maximum-subarray/
 * @conclusion 滚动数组进行查询，每次遍历比较之前的值与当前遍历值的大小，取大的作为结果，最佳算法时间复杂度O(n)
 */
int maxSubArray_OlogN(int *nums, int numsSize);
int maxSubArray_On(int* nums, int numsSize);
int compare(int x, int y);

int main() {
    int nums[10] = {-2,1,-3,4,-1,2,1,-5,4};
    int x = maxSubArray_OlogN(nums, 10);
    int y = maxSubArray_On(nums, 10);
}

/**
 * 设置两个临时变量：全局最大值、区域最大值
 * 遍历原始数组，当区域最大值+当前遍历元素>=当前遍历元素时，则说明此段为目前最大连续
 * 否则，将此区域连续最大值与全局连续最大值作比较，如果大于全局最大值则将区域最大值赋
 * 值给全局最大值，并将区域最大值丢弃采用当前遍历元素作为初始值。
 * 此方法时间复杂度略长O(logN)
 * @param nums
 * @param numsSize
 * @return
 */
int maxSubArray_OlogN(int* nums, int numsSize) {
    int globalMaxSum = nums[0];
    int areaMaxSum = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (areaMaxSum + nums[i] >= nums[i]) {
            areaMaxSum += nums[i];
        } else {
            areaMaxSum = nums[i];
        }

        if (areaMaxSum > globalMaxSum) {
            globalMaxSum = areaMaxSum;
        }
    }

    return globalMaxSum;
}

/**
 * 优化了上面O(logN)的算法，基本思路一致但是改为滚动数组，时间复杂度降低。
 * @param nums
 * @param numsSize
 * @return
 */
int maxSubArray_On(int* nums, int numsSize) {
    int tempResult = 0, maxSum = nums[0];
    for (int i = 0; i < numsSize; ++i) {
        tempResult = compare(tempResult + nums[i], nums[i]);
        maxSum = compare(tempResult, maxSum);
    }
    return maxSum;
}

int compare(int x, int y) {
    if (x >= y) {
        return x;
    } else {
        return y;
    }
}