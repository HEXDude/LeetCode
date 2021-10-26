/**
 * @author HEXDude
 * @date 2021/10/26
 * @see <a href="https://leetcode-cn.com/problems/roman-to-integer/">罗马数字转阿拉伯数字</a>
 */
package ALGORITHM.EASY;

import java.util.HashMap;

public class ROMAN_TO_INTEGER {
    public static void main(String[] args) {
        int number = new Solution_ROMAN_TO_INTEGER().romanToInt(new String("III"));
        System.out.println(number);
    }
}

class Solution_ROMAN_TO_INTEGER {

    /**
     * 罗马数字转阿拉伯数字 因为罗马数字为大的在左, 小的在右,除了特殊情况外, 可以直接对字符串从左至右 累加.
     */
    public int romanToInt(String s) {
        /**
         * 建立HashMap来映射罗马数字与阿拉伯数字的关系
         */
        HashMap<String, Integer> romanRelArab = new HashMap<String, Integer>();
        romanRelArab.put("I", 1);
        romanRelArab.put("V", 5);
        romanRelArab.put("X", 10);
        romanRelArab.put("L", 50);
        romanRelArab.put("C", 100);
        romanRelArab.put("D", 500);
        romanRelArab.put("M", 1000);

        int arabNumber = 0;

        for (int i = 0; i < s.length(); i++) {

            int tempNumber = 0;
            String key = String.valueOf(s.charAt(i));

            /**
             * 为了防止越界,在不是最后一个字符时始终判断下一个字符 如果存在[4,9,40,90]
             */
            if (i < s.length() - 1) {
                String nextKey = String.valueOf(s.charAt(i + 1));
                if ((key.equals("I") && nextKey.equals("X")) || (key.equals("X") && nextKey.equals("C"))
                        || (key.equals("C") && nextKey.equals("M")) || (key.equals("I") && nextKey.equals("V"))
                        || (key.equals("X") && nextKey.equals("L")) || (key.equals("C") && nextKey.equals("D"))) {
                    int nextKeyValue = romanRelArab.get(nextKey);
                    int keyValue = romanRelArab.get(key);
                    tempNumber = nextKeyValue - keyValue;
                    i += 1;
                } else {
                    tempNumber = romanRelArab.get(key);
                }
            } else {
                tempNumber = romanRelArab.get(key);
            }
            arabNumber+=tempNumber;
        }
        return arabNumber;
    }
}
