#include "../Library/header.h"

/**
 * @author HEXDude
 * @date 2022-6-7
 * @ref https://leetcode.cn/problems/flood-fill/
 * @breif 给定一个矩阵表示图画image,一个坐标(sr,sc)以及一个newColor
 * 将坐标上下左右像素值与坐标一致的更新成newColor
 */

void dfs(int **image, int rowSize, int colSize, int x, int y, int newColor, int oldColor);

int **floodFill(int **image, int imageSize, int *imageColSize, int sr, int sc, int newColor, int *returnSize,
                int **returnColumnSizes);

int main() {
    int imageSize = 3;
    int imageColSize = 3;
    int imagePixels[3][3] = {{1, 1, 1},
                             {1, 1, 0},
                             {1, 0, 1}};
    int *image[3] = {imagePixels[0], imagePixels[1], imagePixels[2]};
    int returnSize = 0;
    int *returnColumnSizes[3] = {&returnSize, &returnSize, &returnSize};
    int **result = floodFill(image, imageSize, &imageColSize, 1, 1, 2, &returnSize, returnColumnSizes);
}

/**
 * DFS深度优先解法
 * @param image 图像
 * @param rowSize 图像的行数
 * @param colSize 图像的列数
 * @param x 当前坐标x轴位置
 * @param y 当前坐标y轴位置
 * @param newColor 新像素值
 * @param oldColor 初始坐标像素值
 */
void dfs(int **image, int rowSize, int colSize, int x, int y, int newColor, int oldColor) {

    if (x < 0 || x >= rowSize || y < 0 || y >= colSize) {
        //如果当前递归的坐标超过了矩阵的边界值,则回溯
        return;
    } else if (image[x][y] != oldColor) {
        //如果当前递归的坐标所表示的像素值与初始坐标表示的像素值不一致,则回溯
        return;
    } else {
        //满足以上所有条件后,将当前递归坐标更新成新像素值并递归的计算其
        //上下左右四个方向的坐标
        image[x][y] = newColor;
        //上
        dfs(image, rowSize, colSize, x - 1, y, newColor, oldColor);
        //下
        dfs(image, rowSize, colSize, x + 1, y, newColor, oldColor);
        //左
        dfs(image, rowSize, colSize, x, y - 1, newColor, oldColor);
        //右
        dfs(image, rowSize, colSize, x, y + 1, newColor, oldColor);
    }
}

int **floodFill(int **image, int imageSize, int *imageColSize, int sr, int sc, int newColor, int *returnSize,
                int **returnColumnSizes) {
    //初始坐标的颜色
    int oldColor = image[sr][sc];

    if (oldColor == newColor) {
        return image;
    }

    dfs(image, imageSize, *imageColSize, sr, sc, newColor, oldColor);

    //生成结果
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;
    return image;
}
