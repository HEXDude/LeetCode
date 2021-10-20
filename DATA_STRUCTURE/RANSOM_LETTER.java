/**
 * @author HEXDude
 * @date 2021/10/19
 * @see <a href = "https://leetcode-cn.com/problems/ransom-note/">Ransom letter</a>
 */
package DATA_STRUCTURE;

import java.util.HashMap;
import java.util.Map;
import java.util.Random;

public class RANSOM_LETTER {
    public static void main(String[] args) {
        String ransomNote = "bg";
        String magazine = "efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj";
        boolean x = new Solution_RANSOM_LETTER().canConstruct(ransomNote, magazine);
        System.out.println(0);
    }
}

class Solution_RANSOM_LETTER {
    public boolean canConstruct(String ransomNote, String magazine) {

        HashMap<String, Integer> randsomNoteLetters = new HashMap<String, Integer>();
        HashMap<String, Integer> magazineLetters = new HashMap<String, Integer>();

        for (int i = 0; i < ransomNote.length(); i++) {
            String key = String.valueOf(ransomNote.charAt(i));
            if (randsomNoteLetters.containsKey(key)) {
                randsomNoteLetters.replace(key, randsomNoteLetters.get(key) + 1);
            } else {
                randsomNoteLetters.put(key, 1);
            }
        }

        for (int i = 0; i < magazine.length(); i++) {
            String key = String.valueOf(magazine.charAt(i));
            if (magazineLetters.containsKey(key)) {
                magazineLetters.replace(key, magazineLetters.get(key) + 1);
            } else {
                magazineLetters.put(key, 1);
            }
        }

        for (Map.Entry<String, Integer> values : randsomNoteLetters.entrySet()) {
            String key = values.getKey();
            Integer value = values.getValue();
            if (magazineLetters.containsKey(key)) {
                if (magazineLetters.get(key) < value) {
                    return false;
                }
            }

            if (!magazineLetters.containsKey(key)) {
                return false;
            }
        }

        return true;
    }
}