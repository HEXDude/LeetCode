#include "../Library/header.h"

/**
 * @author HEXDude
 * @date 2022-6-10
 * @ref https://leetcode.cn/problems/reverse-linked-list/
 * @breif 反转链表
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head);

int main() {
    struct ListNode *list1 = malloc(sizeof(struct ListNode));
    list1->val = 1;
    list1->next = malloc(sizeof(struct ListNode));
    list1->next->val = 2;
    list1->next->next = malloc(sizeof(struct ListNode));
    list1->next->next->val = 4;
    list1->next->next->next = NULL;
    struct ListNode *result = reverseList(list1);
}

struct ListNode *reverseList(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode *newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}