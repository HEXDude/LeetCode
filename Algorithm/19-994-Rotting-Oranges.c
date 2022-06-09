#include "../Library/header.h"

/**
 * TODO 待处理
 * @author HEXDude
 * @date 2022-6-9
 * @ref https://leetcode.cn/problems/rotting-oranges/
 * @breif 在给定的m*n的矩阵中,0代表空格子,1代表新鲜橘子,2代表烂橘子.
 * 烂橘子每分钟会腐烂上下左右四个方向的新鲜橘子.
 * 请返回腐烂完所有橘子的最小时间,如果不会腐烂完所有请返回-1.
 */

/**
 * 链表
 */
struct QNode {
    int x;
    int y;
    struct QNode *next;
};

/**
 * 队列
 */
struct Queue {
    int size;
    struct QNode *front;
    struct QNode *rear;
};

struct Queue *createQueue();

void offer(struct Queue *queue, int x, int y);

struct QNode *poll(struct Queue *queue);

bool isEmpty(struct Queue *queue);

int orangesRotting(int **grid, int gridSize, int *gridColSize);

int main() {
    setbuf(stdout, 0);
    int numbers[3][3] = {{2, 1, 1},
                         {1, 1, 0},
                         {1, 1, 0}};
    int *matrix[3] = {numbers[0], numbers[1], numbers[2]};
    int matSize = 3;
    int matColSize[3] = {3, 3, 3};
    int result = orangesRotting(matrix, matSize, matColSize);
}

/**
 * 创建队列
 */
struct Queue *createQueue() {
    struct Queue *queue = calloc(1, sizeof(struct Queue));
    queue->size = 0;
    queue->front = queue->rear = NULL;
    return queue;
}

/**
 * 队列入队
 * @param queue 待入队队列
 * @param x 待入队元素
 * @param y 待入队元素
 */
void offer(struct Queue *queue, int x, int y) {
    //为入队元素创建空间
    struct QNode *newNode = calloc(1, sizeof(struct QNode));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
    //如果队列为空,那么front和rear都同时指向当前入队元素
    if (!queue->front) {
        queue->front = newNode;
        queue->rear = queue->front;
    } else {
        //如果队列不为空,将当前入队元素作为队尾
        queue->rear->next = newNode;
        queue->rear = queue->rear->next;
    }
    queue->size++;
}

/**
 * 队列出队并删除front
 * @param queue 待出队元素
 */
struct QNode *poll(struct Queue *queue) {
    if (queue->front) {
        struct QNode *element = queue->front;
        queue->front = queue->front->next;
        queue->size--;
        return element;
    }
    return NULL;
}

/**
 * 队列是否为空
 * @param queue 待判断队列
 * @return true 为空
 * @return false 不为空
 */
bool isEmpty(struct Queue *queue) {
    if (queue->front) {
        return false;
    }
    return true;
}

int orangesRotting(int **grid, int gridSize, int *gridColSize) {
    struct Queue *queue = createQueue();
    int freshOrangeCount = 0;
    //找出所有烂橘子并将其加入队列中
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < *gridColSize; ++j) {
            if (grid[i][j] == 2) {
                offer(queue, i, j);
                freshOrangeCount++;
            }
        }
    }

    if (freshOrangeCount == 0) {
        return 0;
    }

    //BFS上下左右四个方向的元素
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int minutes = 0;
    while (!isEmpty(queue)) {
        minutes++;
        //将所有烂橘子出列,同时感染,否则时间重复计算
        int queueSize = queue->size;
        for (int j = 0; j < queueSize; ++j) {
            struct QNode *position = poll(queue);
            for (int i = 0; i < 4; ++i) {
                int newX = position->x + dx[i];
                int newY = position->y + dy[i];
                if (newX >= 0 && newX < gridSize && newY >= 0 && newY < *gridColSize && grid[newX][newY] == 1) {
                    grid[newX][newY] = 2;
                    offer(queue, newX, newY);
                    freshOrangeCount--;
                }
            }
        }

    }

    return freshOrangeCount > 0 ? -1 : minutes;
}