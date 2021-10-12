/**
 * @author HEXDude
 * @date 2021/10/12
 * @see <a href="https://leetcode-cn.com/problems/two-sum/">Two Sum,两数之和</a>
 */
package EASY;

import java.util.HashMap;

public class TwoSum {

    static int[] RESULT = new int[2];

    /* 跟随数组的元素个数N浮动,空间复杂度为O(n) */
    static final int[] nums = { 3, 2, 4 };
    static final int tartget = 6;

    /**
     * 使用双重循环解决,但是效率不够高 时间复杂度由数组元素决定->O(n^2)
     */
    public static int[] doubleTraverse(int[] nums, int target) {

        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] + nums[j] == target) {
                    RESULT[0] = i;
                    RESULT[1] = j;
                    return RESULT;
                }
            }
        }

        return null;
    }

    /**
     * 利用HashTable的原理来检索非自身的"target-x" 可以达到时间复杂度O(n)
     */
    public static int[] hashTable(int[] nums, int target) {
        // Key可以为NULL,用包装类型
        HashMap<Integer, Integer> hashTable = new HashMap<>(nums.length);
        /**
         * 如果HashMap里存在'target-x'的key则获取其Value,Value为在数组中的index
         */
        for (int i = 0; i < nums.length; i++) {
            if (hashTable.containsKey(tartget - nums[i])) {
                RESULT[0] = i;
                RESULT[1] = hashTable.get(target - nums[i]);
                return RESULT;
            }
            hashTable.put(nums[i], i);
        }
        return null;
    }

    public static void main(String[] args) {
        hashTable(nums, tartget);
    }

}