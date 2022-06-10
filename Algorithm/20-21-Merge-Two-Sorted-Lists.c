#include "../Library/header.h"

/**
 * @author HEXDude
 * @date 2022-6-10
 * @ref https://leetcode.cn/problems/merge-two-sorted-lists/
 * @breif 合并两个升序链表,并使合并后的链表依然按照升序排序
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2);

int main() {
    struct ListNode *list1 = malloc(sizeof(struct ListNode));
    list1->val = 1;
    list1->next = malloc(sizeof(struct ListNode));
    list1->next->val = 2;
    list1->next->next = malloc(sizeof(struct ListNode));
    list1->next->next->val = 4;
    list1->next->next->next = NULL;

    struct ListNode *list2 = malloc(sizeof(struct ListNode));
    list2->val = 1;
    list2->next = malloc(sizeof(struct ListNode));
    list2->next->val = 3;
    list2->next->next = malloc(sizeof(struct ListNode));
    list2->next->next->val = 4;
    list2->next->next->next = NULL;

    struct ListNode *result = mergeTwoLists(list1, list2);
}

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2) {
    if (!list1) {
        //如果list1为空,因为每个list都已排序,将list2剩余节点作为尾部拼接
        return list2;
    } else if (!list2) {
        //如果list2为空,因为每个list都已排序,将list1剩余节点作为尾部拼接
        return list1;
    } else if (list1->val < list2->val) {
        //如果list1的节点值小于list2的节点值,那么将list1.next + list2作为 list1.next
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    } else {
        //如果list2的节点值小于list1的节点值,那么将list1 + list2.next作为 list2.next
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}