#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include "../../../Library/uthash.h"

/**
 * @author HEXDude
 * @date 2022/4/24
 * @description 给你一个链表的头节点head和一个整数val,请你删除链表中所有满足Node.val==val的节点,并返回新的头节点.
 * @link https://leetcode-cn.com/problems/remove-linked-list-elements/
 * @conclusion 递归下一个节点作为头结点,当头结点为target时返回下一个节点
 */

/**
 * 实现链表
 */
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val);

int main() {
	struct ListNode *list1 = malloc(sizeof(*list1));
	list1->val = 1;
	struct ListNode *list1Secondary = malloc(sizeof(*list1Secondary));
	list1->next = list1Secondary;
	list1Secondary->val = 2;
	struct ListNode *list1Third = malloc(sizeof(*list1Third));
	list1Secondary->next = list1Third;
	list1Third->val = 6;
	struct ListNode *list1Fourth = malloc(sizeof(*list1Fourth));
	list1Third->next = list1Fourth;
	list1Fourth->val = 3;
	struct ListNode *list1Fifth = malloc(sizeof(*list1Fifth));
	list1Fourth->next = list1Fifth;
	list1Fifth->val = 4;
	struct ListNode *list1Sixth = malloc(sizeof(*list1Sixth));
	list1Fifth->next = list1Sixth;
	list1Sixth->val = 5;
	struct ListNode *list1Seventh = malloc(sizeof(*list1Seventh));
	list1Sixth->next = list1Seventh;
	list1Seventh->val = 2;
	struct ListNode *list1Eighth = malloc(sizeof(*list1Eighth));
	list1Seventh->next = list1Eighth;
	list1Eighth->val = 6;
	list1Eighth->next = NULL;

	struct ListNode *result = removeElements(list1, 6);
	free(list1Eighth);
	free(list1Seventh);
	free(list1Sixth);
	free(list1Fifth);
	free(list1Fourth);
	free(list1Third);
	free(list1Secondary);
	free(list1);
}

struct ListNode* removeElements(struct ListNode* head, int val) {
	if (head == NULL) {
		return head;
	}
	head->next = removeElements(head->next, val);
	return head->val == val ? head->next : head;
}
