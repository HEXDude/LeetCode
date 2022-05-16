#include "../../../Library/header.h"

/**
 * @author HEXDude
 * @date 2022/5/16
 * @description 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
 * @link https://leetcode.cn/problems/swap-nodes-in-pairs/
 * @conclusion
 */

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *swapPairs(struct ListNode *head);

int main() {
	//CLion控制台不输出问题,设置缓冲区
	setbuf(stdout, NULL);
	struct ListNode *head = malloc(sizeof(struct ListNode));
	head->val = 1;
	head->next = malloc(sizeof(struct ListNode));
	head->next->val = 2;
	head->next->next = malloc(sizeof(struct ListNode));
	head->next->next->val = 3;
	head->next->next->next = malloc(sizeof(struct ListNode));
	head->next->next->next->val = 4;
	head->next->next->next->next = NULL;
	struct ListNode *result = swapPairs(head);
	free(head);
}

/**
 * 递归求解
 */
struct ListNode *swapPairs(struct ListNode *head) {
	//节点为空或者节点的子节点不满足22交换时,结束递归
	if (head == NULL || head->next == NULL) {
		return head;
	} else {
		//建立中间变量交换两个节点的值
		struct ListNode *temp;
		temp = head->next;
		//递归下去,返回两两交换后的节点,temp.next即head.next.next
		head->next = swapPairs(temp->next);
		temp->next = head;
		return temp;
	}
}

