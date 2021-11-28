//
// Created by HEXDude on 2021/11/28.
// Description: 两数相加
// Reference: https://leetcode-cn.com/problems/add-two-numbers/
// Conclusion: 因为两个链表为逆序，所以可以在遍历的过程中按位相加并设置一个中间值接收
// 进位的值。如果存在一个链表的下一个节点为空，则此节点不再参与下次运算。在遍历结束后，
// 如果存在进位不为零的情况，则需新增一个子节点且子节点的值为进位值（题目限制每个数字不会超过9）
//

//Local part start
#include <stdlib.h>
#include <stdio.h>
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
struct ListNode* generateSingleList(int nodeLength);

/**
 * 创建一个单链表结构体
 * 本地调试注意main方法是否能access本结构体
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

int main() {
    struct ListNode *result = addTwoNumbers(generateSingleList(5), generateSingleList(6));
    printf("1");
}
//Local part end

//Submit part start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {\
    //创建两个单链表指针分别为指向头结点与下一个节点
    struct ListNode *head = NULL, *tail = NULL;
    //进位值
    int carry = 0;
    //l1与l2中任意节点不为空
    while (l1 || l2) {
        //如果节点为NULL则取0值
        int n1 = l1 ? l1->val : 0;
        int n2 = l2 ? l2->val : 0;
        int sum = n1 + n2 + carry;
        /**
         * 如果头结点还没有创建，则新开辟一个节点地址
         * 并使得下一个节点与头结点地址一致
         * 如果以及创建了，则只操作下一个节点
         * 依然是新开辟一个节点并将下一节点指向新开辟的地址
         * 使得地址链表连续新增
         * 我自己的写法在Leetcode上无法成功，索性就Copy过来了
         * ---------------我自己的写法-----------------
         * ListNode *tempNode = malloc(sizeof(struct ListNode));
         * tempNode.val = sum%10;
         * tempNode.next = NULL;
         * tail.next = tempNode;
         * tail = tempNode;
         * .....省略其他逻辑
         * return head.next;
         */
        if (!head) {
            head = tail = malloc(sizeof(struct ListNode));
            tail->val = sum % 10;
            tail->next = NULL;
        } else {
            tail->next = malloc(sizeof(struct ListNode));
            tail->next->val = sum % 10;
            tail = tail->next;
            tail->next = NULL;
        }
        carry = sum / 10;
        if (l1) {
            l1 = l1->next;
        }
        if (l2) {
            l2 = l2->next;
        }
    }
    if (carry > 0) {
        tail->next = malloc(sizeof(struct ListNode));
        tail->next->val = carry;
        tail->next->next = NULL;
    }
    return head;
}
//Submit part end

//Local part start
/**
 * 生成一个单链表，链表数据域为1~9的随机数
 */
struct ListNode* generateSingleList(int nodeLength) {
    //创建链表头
    struct ListNode *node = (struct ListNode *) malloc(sizeof(struct ListNode));
    node->val = rand() % 10;
    //创建链表头指针来做新增节点运算
    struct ListNode *temp = node;
    for (int i = 0; i < nodeLength - 1; i++) {
        struct ListNode *tempNode = (struct ListNode *) malloc(sizeof(struct ListNode));
        tempNode->val = rand() % 10;
        tempNode->next = NULL;
        temp->next = tempNode;
        temp = temp->next;
    }
    return node;
}
//Local part end


