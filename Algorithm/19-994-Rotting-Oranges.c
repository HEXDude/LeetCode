#include "../Library/header.h"

/**
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

/**
 * 找出所有烂橘子与新鲜橘子
 * 将所有烂橘子入队
 * 将队列中所有烂橘子取出来,感染上下左右四个方向的新鲜橘子
 * 并将已感染的新鲜橘子加入队列
 * 直到队列中不存在烂橘子位置腐烂结束
 * 如果此时还有新鲜橘子,那么返回-1,否则返回感染时间
 */
int orangesRotting(int **grid, int gridSize, int *gridColSize) {
    //创建队列存放烂橘子
    struct Queue *queue = createQueue();
    //新鲜橘子数量
    int freshOrangeCount = 0;
    //遍历矩阵,找出所有的烂橘子和新鲜橘子
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < *gridColSize; ++j) {
            if (grid[i][j] == 2) {
                //将烂橘子入队
                offer(queue, i, j);
            } else if (grid[i][j] == 1) {
                //计数新鲜橘子
                freshOrangeCount++;
            }
        }
    }

    //如果没有新鲜橘子可以被感染
    if (freshOrangeCount == 0) {
        return 0;
    }

    /*
     * 将队列中的所有烂橘子拿出同时感染四个方向
     * 如果感染过程中感染了新鲜橘子
     * 就将新鲜橘子更新为2,表示已感染,并入队
     * 同时新鲜橘子数-1
     */
    int minute = 0;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    while (!isEmpty(queue) && queue->size > 0) {
        minute++;
        //队列中的烂橘子数量,同时感染,否则重复计算时间
        int queueSize = queue->size;
        for (int i = 0; i < queueSize; ++i) {
            struct QNode *position = poll(queue);
            for (int j = 0; j < 4; ++j) {
                //感染的下一个方向
                int x = position->x + dx[j];
                int y = position->y + dy[j];
                if (x >= 0 && x < gridSize && y >= 0 && y < *gridColSize && grid[x][y] == 1) {
                    //将被感染的橘子入队
                    offer(queue, x, y);
                    grid[x][y] = 2;
                    freshOrangeCount--;
                }
            }
        }
    }

    //第一次感染不计时,例如只存在单行
    return freshOrangeCount > 0 ? -1 : --minute;
}