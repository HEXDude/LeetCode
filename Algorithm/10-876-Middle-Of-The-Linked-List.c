#include "../Library/header.h"

/**
 * @author HEXDude
 * @date 2022-6-5
 * @ref https://leetcode.cn/problems/middle-of-the-linked-list/
 * @breif 给定一个头结点为 head 的非空单链表，返回链表的中间结点。
 * 如果有两个中间结点，则返回第二个中间结点。
 */

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *middleNode(struct ListNode *head);

int main()
{
    int linkedListLength = 5;
    struct ListNode *header = malloc(sizeof(struct ListNode));
    struct ListNode *headPosition = header;
    for (int i = 0; i < linkedListLength; i++)
    {
        header->val = i + 1;
        if (i == linkedListLength - 1)
        {
            header->next = NULL;
        }
        else
        {
            header->next = malloc(sizeof(struct ListNode));
        }
        header = header->next;
    }
    struct ListNode *result = middleNode(headPosition);
    free(header);
}

/**
 * 可以使用空间换时间的解法,即创建一个数组
 * 再遍历链表,记录将每个index对应的值映射到数组中
 * 最后求数组的中间节点并将中间节点以后生成为链表返回.
 * 也可以使用双指针解法,快慢指针都从头节点开发
 * 慢指针每次走一步,而快指针每次走两步,以此遍历链表,
 * 根据链表的特性,当快指针到达尾节点的时候,满指针一定在
 * 链表的中间部位
 * 直接返回即可
 */
struct ListNode *middleNode(struct ListNode *head)
{
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}