package Algorithms;
/**
 * @author HEXDude
 * @description 图像遍历深度优先算法(DFS) Java版本
 */
public class DFS {
    public static void main(String[] args) {
        int[][] image = {{1,0,1,1}, {0,1,1,0}, {1,0,0,1}, {0,1,1,0}};

        int[][] result = new Solution().floodFill(image, 1, 0, 2);
        System.out.println(1);
    }
}

/**
 * 深度优先递归
 * 从起始点开始递归,如果当前入栈的像素点符合要求(stack[x][y] == originalColor)
 * 则将该像素点重新上色(stack[x][y] = newColor),此时栈顶指向该像素点.
 * 接着递归它的邻接像素点,依次递归,如果在递归中已经无法完成要求,则出栈(出栈回溯到上个入栈元素).
 * 在周而复始的按条件运算递归,回溯中所有符合要求的像素点终将被遍历到.
 * DFS是找到所有可行解的,可能效率不如BFS.
 */
class Solution {
    
    /**
     * 全局维护的方向向量分别代表上下左右方向
     */
    int[] directionX = {0, 0, -1, 1};
    int[] directiony = {-1, 1, 0, 0};
    /**
     * 如果起始位置的像素点与新颜色一致,则不执行任何操作.
     * 如果不同,则进行DFS,DFS需要维护起始像素的颜色,作为判断依据.
     * 在递归中,DFS遵循的路径是当前像素点的上下左右四个位置的像素点,
     * 所以应当维护一个方向向量值(上下左右四个方向的递归式).
     * @param image 图的邻接矩阵
     * @param sr 起始像素点x位置
     * @param sc 起始像素点y位置
     * @param newColor 新的颜色
     * @return
     */
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        if (image[sr][sc] != newColor) {
            //起始位置的颜色
            int originalColor = image[sr][sc];
            DFS(image, sr, sc, newColor, originalColor);
        }
        return image; 
    }

    /**
     * DFS算法实现
     * 
     * @param image 图的邻接矩阵(每次递归后的更新图,相当于入栈后的标记)
     * @param x 递归点x位置
     * @param y 递归点y位置
     * @param newColor 新的颜色
     * @param originalColor DFS维护的起始像素点位置
     */
    public void DFS(int[][] image, int x, int y, int newColor, int originalColor) {
        /**
         * 如果起始像素点的颜色与维护的颜色一致则重新上色,并开始DFS
         */
        if (image[x][y] == originalColor) {
            image[x][y] = newColor;
            for (int i = 0; i < directionX.length; i++) {
                //上下左右四个方向的像素点位置
                int nextX = x + directionX[i];
                int nextY = y + directiony[i];
                //当且仅当x,y的坐标落在矩阵区间时才递归,避免runtimeError
                if (nextX >=0 && nextX < image.length && nextY >=0 && nextY < image[0].length) {
                    //递归会在image[x][y] != originalColor处结束并回溯
                    DFS(image, nextX, nextY, newColor, originalColor);
                }
            }
        }
    }
}
