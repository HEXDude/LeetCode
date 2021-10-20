/**
 * @author HEXDude
 * @date 2021/10/20
 * @see <a href = "https://leetcode-cn.com/problems/valid-anagram/">Valid anagram</a>
 */
package DATA_STRUCTURE;

import java.util.HashMap;

public class VALID_ANAGRAM {
    public static void main(String[] args) {
        String s = "hello";
        String t = "lloeh";
        boolean x = new Solution_VALID_ANAGRAM().isAnagram(s, t);
        System.out.println(1);
    }
}

class Solution_VALID_ANAGRAM {
    /**
     * 题意是两个字符串的组成字符其实是 一样的，所以可以用一个数组解决问题。 s.charAt(i) - 'a'是将当前字符-去
     * 字符'a'的ASCII码，因为只出现小写字母。 例如，当'a' - 'a' = 0, 'b' - 'a' = 1, 每出现一个使得数组中的数组自增。
     * 再遍历第二个字符串，如有则自减，为0时异常
     * 
     * @param s
     * @param t
     * @return
     */
    public boolean isAnagram(String s, String t) {

        if (s.length() != t.length()) {
            return false;
        }

        int[] hashArray = new int[26];

        for (int i = 0; i < s.length(); i++) {

            hashArray[s.charAt(i) - 'a']++;
        }

        for (int j = 0; j < t.length(); j++) {

            hashArray[t.charAt(j) - 'a']--;
            if (hashArray[t.charAt(j) - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
}