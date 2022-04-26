#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include "../../../Library/uthash.h"

/**
 * @author HEXDude
 * @date 2022/4/25
 * @description 给定一个已排序的链表的头head,删除所有重复的元素,使每个元素只出现一次.返回已排序的链表.
 * @link https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
 * @conclusion 有序的数组可以直接比较下一个,如果无需可以考虑用Hash表
 */

/**
 * 实现链表
 */
struct ListNode {
	int val;
	struct ListNode *next;
};

/**
 * 第三方HashSet实现
 */
struct HashSet {
	/**
	 * 键
	 */
	struct ListNode *nodeAddress;
	/**
	 * 三方Hash工具
	 */
	UT_hash_handle hh;
};

struct ListNode *deleteDuplicates(struct ListNode *head);

int main() {
	struct ListNode *head = malloc(sizeof(*head));
	head->val = 1;
	struct ListNode *second = malloc(sizeof(*head));
	head->next = second;
	second->val = 1;
	struct ListNode *third = malloc(sizeof(*head));
	second->next = third;
	third->val = 2;
	third->next = NULL;

	struct ListNode *result = deleteDuplicates(head);

	free(third);
	free(second);
	free(head);

}

struct ListNode *deleteDuplicates(struct ListNode *head) {
	if (!head) {
		return head;
	}
	struct ListNode *myHead = head;
	while (head->next != NULL) {
		if (head->val == head->next->val) {
			head->next = head->next->next;
		} else {
			head = head->next;
		}
	}

	return myHead;
}




