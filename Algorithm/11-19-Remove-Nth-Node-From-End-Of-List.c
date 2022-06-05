#include "../Library/header.h"

/**
 * @author HEXDude
 * @date 2022-6-5
 * @ref https://leetcode.cn/problems/middle-of-the-linked-list/
 * @breif 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 */

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n);

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
    struct ListNode *result = removeNthFromEnd(headPosition, 2);
    free(header);
}

/**
 * 双指针的变种-快慢指针
 * 存在边界值的情况即只有一个元素,还需删除的时候
 * 因此需要为链表设置一个头节点top
 * 在top出设置slow,fast指针
 * fast先行移动n + 1步,因为设置了top
 * 然后slow,fast同步移动,届时,slow指向的就是要删除的
 * 倒数第n个元素
 */
struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    struct ListNode *top = malloc(sizeof(struct ListNode));
    top->val = NULL;
    top->next = head;

    struct ListNode *slow = top;
    struct ListNode *fast = top;

    //初始化快指针的位置
    for (int i = 0; i <= n; i++)
    {
        fast = fast->next;
    }

    //同步移动快慢指针,直到快指针指向结束
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    //此时慢指针指向的节点即为待删除的节点
    slow->next = slow->next->next;

    //返回结果中需移除top
    return top->next;
}