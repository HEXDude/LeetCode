#include "../../../Library/header.h"

/**
 * @author HEXDude
 * @date 2022/4/26
 * @description 用栈实现队列
 * @link https://leetcode-cn.com/problems/implement-queue-using-stacks/
 * @conclusion 根据题意和栈及队列的特性,对两个栈进行反转以得到队列的特性
 */

/**
 * 队列结构体
 */
typedef struct {
	int top0;
	int stack0[1001];
	int top1;
	int stack1[1001];
} MyQueue;

/**
 * 创建队列
 * 在内存中开辟队列,即两个栈,栈顶指针皆初始为-1(空栈)
 * @return MyQueue
 */
MyQueue *myQueueCreate() {
	MyQueue *newQueue = malloc(sizeof(MyQueue));
	newQueue->top0 = -1;
	newQueue->top1 = -1;
	return newQueue;
}

/**
 * 入队
 * 当队列需要入队时,将stack0中的元素(即queue中的元素)全部有序弹出到stack1中.
 * 再将需要入队的元素入栈到stack0中,最后将stack1中的所有元素按序弹出到stack0中.
 * @param obj 入队目标队列
 * @param x 入队值
 */
void myQueuePush(MyQueue *obj, int x) {
	if (obj->top0 != -1) {
		while (obj->top0 > -1) {
			obj->stack1[++obj->top1] = obj->stack0[obj->top0--];
		}
		obj->stack0[++obj->top0] = x;
		while (obj->top1 > -1) {
			obj->stack0[++obj->top0] = obj->stack1[obj->top1--];
		}
	} else {
		obj->stack0[++obj->top0] = x;
	}
}

/**
 * 出队
 * 直接弹出stack0中的栈顶元素
 * @param obj 出队目标队列
 * @return int
 */
int myQueuePop(MyQueue *obj) {
	return obj->stack0[obj->top0--];
}

/**
 * 获取队列头元素
 * 获取stack0的栈顶
 * @param obj peek目标队列
 * @return int
 */
int myQueuePeek(MyQueue *obj) {
	return obj->stack0[obj->top0];
}

bool myQueueEmpty(MyQueue *obj) {
	return obj->top0 == -1;
}

void myQueueFree(MyQueue *obj) {
	free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/

int main() {
	struct MyQueue *queue = myQueueCreate();
	myQueuePush(queue, 1);
	myQueuePush(queue, 2);
	myQueueFree(queue);
}