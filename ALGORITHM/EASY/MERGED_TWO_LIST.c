/**
 * @file MERGED_TWO_LIST.c
 * @author HEXDude
 * @date 2021-11-2
 * @see <a href = "https://leetcode-cn.com/problems/merge-two-sorted-lists/">MERGED_TWO_LIST,合并两个升序链表</a>
 */
#include <stdio.h>
#include <stdlib.h>

//定义链表结构体
struct ListNode
{
    //数据域
    int val;
    //下一节点
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(l1==NULL)
        return l2;
    if(l2==NULL)
        return l1;
    if(l1->val < l2->val){
        l1->next = mergeTwoLists(l1->next,l2);
        return l1;
    }else{
        l2->next = mergeTwoLists(l1,l2->next);
        return l2;
    }
}

int main()
{
    struct ListNode *node1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *nodeA = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *nodeB = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *nodeC = (struct ListNode *)malloc(sizeof(struct ListNode));
    node1->val = 1;
    node1->next = node2;
    node2->val = 2;
    node2->next = node3;
    node3->val = 4;
    node3->next = NULL;
    nodeA->val = 1;
    nodeA->next = nodeB;
    nodeB->val = 3;
    nodeB->next = nodeC;
    nodeC->val = 4;
    nodeC->next = NULL;
    struct ListNod *result = NULL;
    result = mergeTwoLists(node1, nodeA);
    return 0;
}