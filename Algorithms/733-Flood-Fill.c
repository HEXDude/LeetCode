/**
 * @author HEXDude
 * @date 2022/1/1
 * @description 在一个无向图的邻接矩阵中，每一个值代表该像素的颜色，给定一个坐标(sr,sc)，请
 * 将(sr,sc)与的上下左右四个方向的与(sr, sc)颜色一致的像素染成新颜色,在上下左右像素的周围符合条件的也重新上色。
 * @reference https://leetcode-cn.com/problems/flood-fill/
 * @conclusion 深度优先搜素，在给定的起点沿着四个方向递归，递归过程中将符合条件的重新上色，在达到边界值时回溯，
 * 直到某个方向无法回溯，说明该方向已经DFS结束了。
 */

/*
 * Local part start
 */
#include <stdio.h>

int **floodFill(int **image, int imageSize, int *imageColSize, int sr, int sc, int newColor, int *returnSize,
                int **returnColumnSizes);

void DFS(int **image, int x, int y, int originalColor, int newColor, int imageSize, int *imageColSize);

int main() {
    //TDOO HEXDude 本地测试用例
}

/*
 * Local part end
 */

/*
 * Submit part start
 */
int **floodFill(int **image, int imageSize, int *imageColSize, int sr, int sc, int newColor, int *returnSize,
                int **returnColumnSizes) {
    //如果测试用例中出现新的颜色与起始点颜色一样则不执行任何操作
    if (image[sr][sc] != newColor) {
        DFS(image, sr, sc, image[sr][sc], newColor, imageSize, imageColSize);
    }
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;
    return image;
}

void DFS(int **image, int x, int y, int originalColor, int newColor, int imageSize, int *imageColSize) {
    /**
     * 如果x,y落在了邻接矩阵以外的范围则停止递归,回溯
     */
    if (x < 0 || x >= imageSize || y < 0 || y >= imageColSize[0]) {
        return;
    }

    /**
     * 如果当前入栈的像素点的颜色符合要求,则将它染色
     * 避免下次再次遍历此节点.然后再遍历此像素点的
     * 邻居(上下左右,分别用x+1,x-1...代替).
     */
    if (image[x][y] == originalColor) {
        image[x][y] = newColor;
        DFS(image, x - 1, y, originalColor, newColor, imageSize, imageColSize);
        DFS(image, x + 1, y, originalColor, newColor, imageSize, imageColSize);
        DFS(image, x, y - 1, originalColor, newColor, imageSize, imageColSize);
        DFS(image, x, y + 1, originalColor, newColor, imageSize, imageColSize);
    }
}
/*
 * Submit part end
 */