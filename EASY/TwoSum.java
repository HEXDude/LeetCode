/**
 * @author HEXDude
 * @date 2021/10/12
 * @see <a href="https://leetcode-cn.com/problems/two-sum/">Two Sum,两数之和</a>
 */
package EASY;
 public class TwoSum {
     public static void main(String[] args) {
         final int[] nums = {2,5,5,11};
         final int target = 10;
         /**
          * 双层循环过于缓慢
          */
         for (int i = 0; i < nums.length; i++) { 
             for (int j = i + 1; j < nums.length; j++) {
                 if (nums[i] + nums[j] == target) {
                     System.out.println(i);
                     System.out.println(j);
                 }
             }
        }
    }
 }