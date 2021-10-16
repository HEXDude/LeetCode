package DATA_STRUCTURE;

import java.util.ArrayList;
import java.util.HashMap;

/**
 * INTERSECTIO_OF_TWO_ARRAYS
 */
public class INTERSECTIO_OF_TWO_ARRAYS {
    public static void main(String[] args) {
        int[] nums1 = { 1, 2, 2, 1 };
        int[] nums2 = { 2, 2 };
        Solution solution = new Solution();
        solution.intersect(nums1, nums2);
    }
}

class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {

        HashMap<Integer, Integer> nums1ElementsAndSequenceMap = new HashMap<Integer, Integer>();
        HashMap<Integer, Integer> nums2ElementsAndSequenceMap = new HashMap<Integer, Integer>();
        for (int nums1Element : nums1) {
            if (nums1ElementsAndSequenceMap.containsKey(nums1Element)) {
                nums1ElementsAndSequenceMap.replace(nums1Element, nums1ElementsAndSequenceMap.get(nums1Element) + 1);
            } else {
                nums1ElementsAndSequenceMap.put(nums1Element, 1);
            }

        }

        for (int nums2Element : nums2) {
            if (nums2ElementsAndSequenceMap.containsKey(nums2Element)) {
                nums2ElementsAndSequenceMap.replace(nums2Element, nums2ElementsAndSequenceMap.get(nums2Element) + 1);
            } else {
                nums2ElementsAndSequenceMap.put(nums2Element, 1);
            }

        }

        ArrayList<Integer> interSectionList = new ArrayList<Integer>();
        for (HashMap.Entry<Integer, Integer> nums1MapEntry : nums1ElementsAndSequenceMap.entrySet()) {
            if (nums2ElementsAndSequenceMap.containsKey(nums1MapEntry.getKey())) {
                int index = nums1MapEntry.getValue() > nums2ElementsAndSequenceMap.get(nums1MapEntry.getKey())
                        ? nums2ElementsAndSequenceMap.get(nums1MapEntry.getKey())
                        : nums1MapEntry.getValue();
                for (int i = 0; i < index; i++) {
                    interSectionList.add(nums1MapEntry.getKey());
                }
            }
        }

        int[] result = new int[interSectionList.size()];
        for (int i = 0; i < interSectionList.size(); i++) {
            result[i] = interSectionList.get(i);
        }

        return result;
    }
}
