#include "../Library/header.h"

/**
 * @author HEXDude
 * @date 2022-6-9
 * @ref https://leetcode.cn/problems/01-matrix/
 * @breif 给定一个由0和1组成的矩阵mat,请输出一个大小相同的矩阵,其中每一个格子是mat中对应位置元素到最近的0的距离.
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
    struct QNode *front;
    struct QNode *rear;
};

struct Queue *createQueue();

void offer(struct Queue *queue, int x, int y);

struct QNode *poll(struct Queue *queue);

bool isEmpty(struct Queue *queue);

int **updateMatrix(int **mat, int matSize, int *matColSize, int *returnSize, int **returnColumnSizes);

int main() {
    setbuf(stdout, 0);
    int numbers[3][3] = {{0, 0, 0},
                         {0, 1, 0},
                         {1, 1, 1}};
    int *matrix[3] = {numbers[0], numbers[1], numbers[2]};
    int matSize = 3;
    int matColSize[3] = {3, 3, 3};
    int returnSize[3] = {0, 0, 0};
    int returnNumbers[3][3] = {{0, 0, 0},
                               {0, 1, 0},
                               {0, 0, 0}};
    int *returnColumnSizes[3] = {returnNumbers[0], returnNumbers[1], returnNumbers[2]};
    int **result = updateMatrix(matrix, matSize, matColSize, returnSize, returnColumnSizes);
}

/**
 * 创建队列
 */
struct Queue *createQueue() {
    struct Queue *queue = calloc(1, sizeof(struct Queue));
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
}

/**
 * 队列出队并删除front
 * @param queue 待出队元素
 */
struct QNode *poll(struct Queue *queue) {
    if (queue->front) {
        struct QNode *element = queue->front;
        queue->front = queue->front->next;
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

int **updateMatrix(int **mat, int matSize, int *matColSize, int *returnSize, int **returnColumnSizes) {
    //returnSize与returnColumnsSize和源矩阵保持一致即可
    *returnSize = matSize;
    *returnColumnSizes = matColSize;

    //创建size一致的矩阵接收结果,并将所有节点初始化为零
    //因为为0的元素,其更新后还是为0,可以省去更新成本
    int **result = malloc(sizeof(int *) * matSize);
    for (int i = 0; i < matSize; ++i) {
        result[i] = calloc(*matColSize, sizeof(int));
    }

    //创建队列存储BFS源,此时的源即矩阵中为0的元素
    struct Queue *queue = createQueue();
    //存储遍历过的元素,并将其全部初始为0,如果遍历过,更新为1,这样即可直观判断真假
    int seen[matSize][*matColSize];
    memset(seen, 0, sizeof(seen));
    for (int i = 0; i < matSize; ++i) {
        for (int j = 0; j < *matColSize; ++j) {
            if (mat[i][j] == 0) {
                offer(queue, i, j);
                seen[i][j] = 1;
            }
        }
    }

    //BFS上下左右四个方向的元素
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    while (!isEmpty(queue)) {
        struct QNode *position = poll(queue);
        //遍历四个方向
        for (int i = 0; i < 4; ++i) {
            int newX = position->x + dx[i];
            int newY = position->y + dy[i];
            if (newX >= 0 && newX < matSize && newY >= 0 && newY < *matColSize && !seen[newX][newY]) {
                result[newX][newY] = result[position->x][position->y] + 1;
                offer(queue, newX, newY);
                seen[newX][newY] = 1;
            }
        }
    }

    free(returnColumnSizes);
    free(queue);
    return result;
}