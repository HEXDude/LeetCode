/**
 * @author HEXDude
 * @date 2021/10/18
 * @see <a href = "https://leetcode-cn.com/problems/reshape-the-matrix/">Reshape the martix</a>
 * @TODO OOM Exception
 */
package DATA_STRUCTURE;

public class RESHAPE_THE_MARTIX {
    public static void main(String[] args) {
        int[][] x = { { 1, 2 }, { 3, 4 } };
        int[][] p = new Solution_Matrix().matrixReshape(x, 1, 4);
        System.out.println(p);
    }
}

/**
 * 将一个m*n的矩阵按顺序重合整合成一个r*c的矩阵，如果不成立则返回原矩阵
 */
class Solution_Matrix {
    public int[][] matrixReshape(int[][] mat, int r, int c) {

        /**
         * 矩阵的m.n
         */
        int m = mat.length;
        int n = mat[0].length;
        
        /**
         * 不成立返回原矩阵
         */
        if (m * n != r * c) {
            return mat;
        }

        int[][] resharpedMatrix = new int[r][c];

        /**
         * 建立原矩阵的索引，使得时间复杂度降低
         */
        int x = 0;
        int y = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                resharpedMatrix[i][j] = mat[x][y];
                y++;
                if(y==n) {
                    if(x==m) {
                        break;
                    }
                    x++;
                    y=0;
                }
            }
        }
        return resharpedMatrix;
    }
}