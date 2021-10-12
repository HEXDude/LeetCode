/**
 * @author HEXDude
 * @date 2021/10/12
 * @see <a href = "https://leetcode-cn.com/problems/contains-duplicate/">Contains duplicate</a>
 */

package DATA_STRUCTURE;

import java.util.HashSet;
import java.util.Set;

public class CONTAINS_DUPLICATE {

    static int[] nums = { 3, 3, 1, 5, 7 };

    static Boolean duplicateCheck(int[] nums) {
        /**
         * 利用Set集合的特性减少复杂度运算
         * 并利用Api减少资源开销大大减少了空间复杂度
         */
        Set<Integer> containner = new HashSet<Integer>();
        for (int i = 0; i < nums.length; i++) {
            if (!containner.add(nums[i])) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        System.out.println(duplicateCheck(nums));
    }

}