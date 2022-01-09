/**
 * @author HEXDude
 * @date 12/28/21
 * @description 给定一个头结点为 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点。
 * @reference https://leetcode-cn.com/problems/middle-of-the-linked-list/
 * @conclusion 双指针（快慢指针）， 快指针每次走两步而慢指针每次走一步，这样在快指针到达尽头时，慢指针一定是在中间位置的。
 * TODO HEXDude Need fix
 */

//Local Part Start
#include <stdio.h>
#include <malloc.h>

struct ListNode* middleNode(struct ListNode* head);
struct ListNode {
 int val;
 struct ListNode *next;
 };

int main() {
    struct ListNode * head = malloc(sizeof(struct ListNode));
    head->val = 1;
    struct ListNode * level2 = malloc(sizeof(struct ListNode));;
    level2->val = 2;
    struct ListNode * level3 = malloc(sizeof(struct ListNode));;
    level3->val = 3;
    struct ListNode * level4 = malloc(sizeof(struct ListNode));;
    level4->val = 4;
    head->next = level2;
    level2->next = level3;
    level3->next = level4;
    level4->next = NULL;
    middleNode(head);
}
//Local Part end

//Submit Part Start
struct ListNode* middleNode(struct ListNode* head) {
    /**
     * 因为结构体定义的单链表,不能简单的通过下标来寻找了
     * 可以定义快慢指针来解决,快指针每次走两个节点,而慢
     * 指针每次都一个节点,这样,当快指针走到尽头时,慢指针一定是停在中间位置的
     */
    struct ListNode * slow = head;
    struct ListNode * fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
//Submit Part End

