#include "../Library/header.h"

/**
 * @author HEXDude
 * @date 2022-6-7
 * @ref https://leetcode.cn/problems/flood-fill/
 * @breif 给定一个m*n的二进制矩阵表示海与岛,1表示陆地
 * 0表示大海
 * 在水平或垂直方向相邻的陆地为岛屿
 * 如果图中有岛屿,求岛屿的最大面积,没有返回0
 */

int dfs(int **grid, int gridSize, int gridColSize, int x, int y);
int maxAreaOfIsland(int **grid, int gridSize, int *gridColSize);

int main()
{
    int gridSize = 8;
    int gridColSize = 13;
    int grid[8][13] = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                       {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                       {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    int *island[8];
    for (int i = 0; i < gridSize; i++)
    {
        island[i] = grid[i];
    }
    int result = maxAreaOfIsland(island, gridSize, &gridColSize);
}

/**
 * 深度优先计算面积,将已经递归过的元素置为零避免重复遍历
 */
int dfs(int **grid, int gridSize, int gridColSize, int x, int y)
{
    if (0 > x || x >= gridSize || 0 > y || y >= gridColSize || grid[x][y] == 0)
    {
        return 0;
    }

    grid[x][y] = 0;
    int count = 1;
    //上
    count += dfs(grid, gridSize, gridColSize, x - 1, y);
    //下
    count += dfs(grid, gridSize, gridColSize, x + 1, y);
    //左
    count += dfs(grid, gridSize, gridColSize, x, y - 1);
    //右
    count += dfs(grid, gridSize, gridColSize, x, y + 1);
    return count;
}

int maxAreaOfIsland(int **grid, int gridSize, int *gridColSize)
{
    int answer = 0;
    //遍历grid,如果不是海洋就DFS计算面积
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < *gridColSize; j++)
        {
            if (grid[i][j])
            {
                int x = grid[i][j];
                answer = fmax(dfs(grid, gridSize, *gridColSize, i, j), answer);
            }
        }
    }

    return answer;
}
