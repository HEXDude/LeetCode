#include "../../../Library/header.h"

/**
 * @author HEXDude
 * @date 2022/4/24
 * @description 将两个升序链表合并为一个新的升序链表并返回,新链表是通过拼接给定的两个链表的所有节点组成的.
 * @link https://leetcode-cn.com/problems/merge-two-sorted-lists/
 * @conclusion 递归,一看就会,一写就废!
 */

/**
 * 实现链表
 */
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2);

int main() {
	struct ListNode *list1 = malloc(sizeof(*list1));
	list1->val = 1;
	struct ListNode *list1Secondary = malloc(sizeof(*list1Secondary));
	list1->next = list1Secondary;
	list1Secondary->val = 2;
	struct ListNode *list1Third = malloc(sizeof(*list1Third));
	list1Secondary->next = list1Third;
	list1Third->val = 4;
	list1Third->next = NULL;

	struct ListNode *list2 = malloc(sizeof(*list2));
	list2->val = 1;
	struct ListNode *list2Secondary = malloc(sizeof(*list2Secondary));
	list2->next = list2Secondary;
	list2Secondary->val = 3;
	struct ListNode *list2Third = malloc(sizeof(*list2Third));
	list2Secondary->next = list2Third;
	list2Third->val = 4;
	list2Third->next = NULL;

	mergeTwoLists(list1, list2);
	free(list2Third);
	free(list2Secondary);
	free(list2);
	free(list1Third);
	free(list1Secondary);
	free(list1);

}

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2) {
	if (list1 == NULL) {
		return list2;
	} else if (list2 == NULL) {
		return list1;
	} else if (list1->val < list2->val) {
		list1->next = mergeTwoLists(list1->next, list2);
		return list1;
	} else {
		list2->next = mergeTwoLists(list1, list2->next);
		return list2;
	}
}