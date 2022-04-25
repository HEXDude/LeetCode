#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include <C:\Users\HEXDude\WorkSpace\LeetCode\Library\uthash.h>

/**
 * @author HEXDude
 * @date 2022/4/25
 * @description 给你单链表的头节点head,请你反转链表,并返回反转后的链表.
 * @link https://leetcode-cn.com/problems/reverse-linked-list/
 * @conclusion
 */

/**
 * 实现链表
 */
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head);

int main() {
	struct ListNode *list1 = malloc(sizeof(*list1));
	list1->val = 1;
	struct ListNode *list1Secondary = malloc(sizeof(*list1Secondary));
	list1->next = list1Secondary;
	list1Secondary->val = 2;
	struct ListNode *list1Third = malloc(sizeof(*list1Third));
	list1Secondary->next = list1Third;
	list1Third->val = 3;
	list1Third->next = NULL;

	int result = reverseList(list1);
	free(list1Third);
	free(list1Secondary);
	free(list1);
}

struct ListNode* reverseList(struct ListNode* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	struct ListNode* newHead = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;
	return newHead;
}