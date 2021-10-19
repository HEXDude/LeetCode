/**
 * @author HEXDude
 * @date 2021/10/19
 * @see <a href = "https://leetcode-cn.com/problems/pascals-triangle/">Pascal's triangle</a>
 */
package DATA_STRUCTURE;

import java.util.ArrayList;
import java.util.List;

public class PASCALS_TRIANGLE {
    public static void main(String[] args) {
        List<List<Integer>> triangle = new Solution_PASCALS_TRIANGLE().generate(5);
        System.out.println(triangle);
    }

}

class Solution_PASCALS_TRIANGLE {
    public List<List<Integer>> generate(int numRows) {
        
        /**
         * 转换成矩阵思考
         * 每行开头和结尾都是1，即j==0||j==i时就是1
         * 每行的未知数x对应上一级的[j]+[j-1]
         */
        List<List<Integer>> allList = new ArrayList<>();
        for (int i = 1; i <= numRows; i++) {
            List<Integer> tempList = new ArrayList<Integer>();
            for (int j = 1; j <= i; j++) {
                if (j == 1 || j == i) {
                    tempList.add(1);
                } else {
                    int x = allList.get(i - 1 - 1).get(j - 1) + allList.get(i - 1 - 1).get(j - 1 - 1);
                    tempList.add(x);
                }
            }
            allList.add(tempList);
        }
        return allList;
    }
}
