#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include <C:\Users\HEXDude\WorkSpace\LeetCode\Library\uthash.h>

/**
 * @author HEXDude
 * @date 2022/4/24
 * @description 给你一个链表的头节点 head ，判断链表中是否有环。
 * @link https://leetcode-cn.com/problems/linked-list-cycle/
 * @conclusion 刚开始准备用递归回溯,但是找不到状态转移方程.因此使用Hash表来存储链表地址.
 * TODO 优化算法
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

bool hasCycle(struct ListNode *head);

int main() {
	struct ListNode *head = malloc(sizeof(*head));
	head->val = 3;
	struct ListNode *second = malloc(sizeof(*head));
	head->next = second;
	second->val = 2;
	struct ListNode *third = malloc(sizeof(*head));
	second->next = third;
	third->val = 0;
	struct ListNode *fourth = malloc(sizeof(*head));
	third->next = fourth;
	fourth->val = -4;
	fourth->next = head;

	bool result = hasCycle(head);
	free(fourth);
	free(third);
	free(second);
	free(head);

}

bool hasCycle(struct ListNode *head) {
	if (head == NULL || head->next == NULL) {
		return false;
	}

	struct HashSet *set = NULL;
	while (head != NULL) {
		struct HashSet *traverseSet;
		HASH_FIND_PTR(set, &head, traverseSet);
		if (traverseSet != NULL) {
			return true;
		} else {
			traverseSet = malloc(sizeof(*traverseSet));
			traverseSet->nodeAddress = head;
			HASH_ADD_PTR(set, nodeAddress, traverseSet);
		}
		head = head->next;
	}
	return false;
}




