/**
 * @author HEXDude
 * @date 2021/10/19
 * @see <a href = "https://leetcode-cn.com/problems/valid-sudoku/">Valid sudoku</a>
 */
package DATA_STRUCTURE;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;

public class VALID_SODOKU {
    public static void main(String[] args) {
        char[][] board = { { '.', '.', '.', '.', '.', '.', '5', '.', '.' },
                { '.', '.', '.', '.', '.', '.', '.', '.', '.' }, { '.', '.', '.', '.', '.', '.', '.', '.', '.' },
                { '9', '3', '.', '.', '2', '.', '4', '.', '.' }, { '.', '.', '7', '.', '.', '.', '3', '.', '.' },
                { '.', '.', '.', '.', '.', '.', '.', '.', '.' }, { '.', '.', '.', '3', '4', '.', '.', '.', '.' },
                { '.', '.', '.', '.', '.', '3', '.', '.', '.' }, { '.', '.', '.', '.', '.', '5', '2', '.', '.' } };
        Boolean x = new Solution_Valid_Sudoku().isValidSudoku(board);

        System.out.println(1);
    }
}

class Solution_Valid_Sudoku {
    public boolean isValidSudoku(char[][] board) {

        /* 数独的横轴竖轴长度 */
        int m = board.length;
        int n = board[0].length;

        /*
         * 每个3*3的区域的HashMap Key为J0,J1,J2，分别表示每三行的3*3区域 在每遍历三行后如数据无重复则清空Map，如有则在运行时reture
         * false。
         */
        HashMap<String, Set<String>> sectioMap = new HashMap<>();
        /* 每列的HashSet，在遍历每一列时对元素装载，如果存在重复则return false */
        HashMap<String, Set<String>> colMap = new HashMap<>();

        for (int i = 0; i < m; i++) {

            /* 每行的HashSet，在遍历每一行时对元素装载，如果存在重复则return false */
            Set<String> rowSet = new HashSet<String>();

            /**
             * 每遍历三行清空一个3*3HashMap
             */
            if (i % 3 == 0 && i != 0) {
                sectioMap.clear();
            }

            for (int j = 0; j < n; j++) {

                // 当前元素的String变量
                String x = String.valueOf(board[i][j]);

                /*
                 * 行校验
                 */
                if (rowSet.contains(x) && !x.equals(".")) {
                    return false;
                } else {
                    rowSet.add(x);
                }

                String stage = "J0";

                if (3 <= j && j < 6) {
                    stage = "J1";

                }

                if (6 <= j && j < 9) {
                    stage = "J2";

                }

                if (sectioMap.containsKey(stage)) {
                    Set<String> tempBlock = sectioMap.get(stage);
                    if (tempBlock.contains(x) && !x.equals(".")) {
                        return false;
                    } else {
                        tempBlock.add(x);
                    }
                } else {
                    Set<String> tempBlock = new HashSet<String>();
                    tempBlock.add(x);
                    sectioMap.put(stage, tempBlock);
                }

                /**
                 * 列校验
                 */
                String colStage = "I" + j;
                if (colMap.containsKey(colStage)) {
                    Set<String> tempBlock = colMap.get(colStage);
                    if (tempBlock.contains(x) && !x.equals(".")) {
                        return false;
                    } else {
                        tempBlock.add(x);
                    }
                } else {
                    Set<String> tempBlock = new HashSet<String>();
                    tempBlock.add(x);
                    colMap.put(colStage, tempBlock);
                }
            }
        }

        return true;
    }
}
