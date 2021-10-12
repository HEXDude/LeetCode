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

    static int[] nums = {-1, 9, 7, -8, 3, 2, 1};

    /**
     * 双层循环找出每一个元素向后和的最大值的组合
     */
    static int findMaximum(int[] nums) {
        /** 储存双层循环中每一次外层循环最高值与对应的子数组
         */
        HashMap<Integer, int[]> allMax = new HashMap<Integer, int[]>();
        for(int i = 0; i < nums.length; i++) {
            //循环初始值,即为当前index
            int temp = nums[i];
            //一个也算
            allMax.put(temp, new int[]{nums[i]});
            for(int j = i + 1; j < nums.length; j++) {
                temp+=nums[j];
                //截取当前子数组
                int[] tempSubArray = Arrays.copyOfRange(nums, i, j);
                allMax.put(temp, tempSubArray);
            }
        }
        return Collections.max(allMax.keySet());
    }

   public static void main(String[] args) {
       System.out.println(findMaximum(nums));
   } 
}