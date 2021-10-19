/**
 * @author HEXDude
 * @date 2021/10/19
 * @see <a href = "https://leetcode-cn.com/problems/first-unique-character-in-a-string/">First character in String</a>
 */
package DATA_STRUCTURE;

import java.util.HashSet;
import java.util.LinkedHashMap;

/**
 * FIRST_UNIQUE_CHARACTER_IN_STRING
 */
public class FIRST_UNIQUE_CHARACTER_IN_STRING {
    public static void main(String[] args) {
        String s = "HHHWTF!";
        int x = new Solution_FIRST_UNIQUE_CHARACTER_IN_STRING().firstUniqChar(s);
        System.out.println(0);
    }
}

class Solution_FIRST_UNIQUE_CHARACTER_IN_STRING {
    public int firstUniqChar(String s) {

        for (int i = 0; i < s.length(); i++) {
            if (s.indexOf(s.charAt(i)) == s.lastIndexOf(s.charAt(i))) {
                return s.indexOf(s.charAt(i));
            }
        }

        return -1;
    }
}