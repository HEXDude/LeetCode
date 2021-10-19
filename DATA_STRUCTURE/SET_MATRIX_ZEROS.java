/**
 * @author HEXDude
 * @date 2021/10/19
 * @see <a href = "https://leetcode-cn.com/problems/set-matrix-zeroes/">Valid sudoku</a>
 */
package DATA_STRUCTURE;

public class SET_MATRIX_ZEROS {
    public static void main(String[] args) {
        int[][] matrix = {{1,1,1},{1,0,1},{1,1,1}};
        new Solution_SET_MATRIX_ZEROS().setZeroes(matrix);
    }
}

class Solution_SET_MATRIX_ZEROS {
    public void setZeroes(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        boolean[] row = new boolean[m];
        boolean[] col = new boolean[n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = col[j] = true;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
}
