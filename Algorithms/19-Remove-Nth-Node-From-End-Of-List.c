/**
 * @author HEXDude
 * @date 12/29/21
 * @description 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 * @reference https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
 * @conclusion 主要难点在于链表你位置长度，所以需要先获取长度后再找到要删除的节点后，截再将被删除节点的父节点指向
 * 被删除节点的子节点。
 */

//Local Part Start
#include <stdio.h>
#include <malloc.h>

struct ListNode* removeNthFromEnd(struct ListNode* head, int n);
struct ListNode {
    int val;
    struct ListNode *next;
};

int main() {

}
//Local Part End

//Submit Part Start
int getLength(struct ListNode* head) {
    int length = 0;
    while (head) {
        ++length;
        head = head->next;
    }
    return length;
}
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->val = 0, dummy->next = head;
    int length = getLength(head);
    struct ListNode* cur = dummy;
    for (int i = 1; i < length - n + 1; ++i) {
        cur = cur->next;
    }
    cur->next = cur->next->next;
    struct ListNode* ans = dummy->next;
    free(dummy);
    return ans;
}
//Submit Part ENd

