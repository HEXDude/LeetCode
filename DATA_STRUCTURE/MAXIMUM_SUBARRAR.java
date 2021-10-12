/**
 * @author HEXDude
 * @date 2021/10/12
 * @see <a href = "https://leetcode-cn.com/problems/maximum-subarray/">Contains duplicate</a>
 * @TODO OOM Exception
 */

package DATA_STRUCTURE;

import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;

public class MAXIMUM_SUBARRAR {

    static int[] nums = { -1, 9, 7, -8, 3, 2, 1 };

    /**
     * 自己的方法会导致OOM 双层循环找出每一个元素向后和的最大值的组合
     */
    static int findMaximum(int[] nums) {
        /**
         * 储存双层循环中每一次外层循环最高值与对应的子数组
         */
        HashMap<Integer, int[]> allMax = new HashMap<Integer, int[]>();
        for (int i = 0; i < nums.length; i++) {
            // 循环初始值,即为当前index
            int temp = nums[i];
            // 一个也算
            allMax.put(temp, new int[] { nums[i] });
            for (int j = i + 1; j < nums.length; j++) {
                temp += nums[j];
                // 截取当前子数组
                int[] tempSubArray = Arrays.copyOfRange(nums, i, j);
                allMax.put(temp, tempSubArray);
            }
        }
        return Collections.max(allMax.keySet());
    }

    /**
     * 官方的思路,我的实现
     * 我的理解:
     * 这个问题的解就是求一组元素中连续的最大和
     * 官方的思路是直接遍历元素,创建一个指针以
     * 及临时变量来接收当前遍历时的最大值,如果
     * 前一个和'pre+x'小于当前和则之前丢弃之前
     * 累加和,重新设置临时变量,在此过程中,临时变量
     * 只储存最大值.
     * 不得不佩服!俺一上来就直接暴力解.
     */
    static int findMaximum_OFFICIAL(int[] nums) {

        /**
         * 指针和,每次往下次遍历时,如果指针和与下一个值的和小于下一个值,则直接将下一个值赋值
         * 给指针和
         */
        int preSum = 0;

        /**
         * 最大值,在每次对比中只保存最大值
         */
        int maxValue = nums[0];

        for (int i : nums) {
            preSum = Math.max(preSum + i, i);
            maxValue = Math.max(maxValue, preSum); 
        }
        return maxValue;
    }

    public static void main(String[] args) {
        //System.out.println(findMaximum(nums));
         System.out.println(findMaximum_OFFICIAL(nums));
    }
}