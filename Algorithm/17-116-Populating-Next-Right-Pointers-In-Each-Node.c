#include "../Library/header.h"

/**
 * @author HEXDude
 * @date 2022-6-8
 * @ref https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/
 * @breif 将二叉树的每个节点的NEXT指向它同层的右边的第一个节点
 * 定义的二叉树的为完美二叉树
 * 即所有叶子节点都在同一层，每个父节点都有两个子节点
 * 初始状态NEXT均为NULL;
 */

struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};

struct Node *connect(struct Node *root);

int main()
{
    struct Node *root = malloc(sizeof(struct Node));
    root->val = 1;
    root->next = NULL;
    root->left = malloc(sizeof(struct Node));
    root->left->next = NULL;
    root->left->val = 2;
    root->left->left = malloc(sizeof(struct Node));
    root->left->left->next = NULL;
    root->left->left->val = 4;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->right = malloc(sizeof(struct Node));
    root->left->right->next = NULL;
    root->left->right->val = 5;
    root->left->right->left = NULL;
    root->left->right->right = NULL;

    root->right = malloc(sizeof(struct Node));
    root->right->next = NULL;
    root->right->val = 3;
    root->right->left = malloc(sizeof(struct Node));
    root->right->left->next = NULL;
    root->right->left->val = 6;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = malloc(sizeof(struct Node));
    root->right->right->next = NULL;
    root->right->right->val = 7;
    root->right->right->left = NULL;
    root->right->right->right = NULL;
    struct Node *result = connect(root);
    free(root);
    free(result);
}

struct Node *connect(struct Node *root)
{
    if (!root)
    {
        return NULL;
    }

    //前序递归树
    //将同一父节点下的两个叶子节点关联
    if (root->left && root->right)
    {
        root->left->next = root->right;
    }

    //如果当前节点父节点存在有意义的NEXT
    //那么将右子节点的NEXT指向父节点的NEXT指向的左子节点
    if (root->next && root->right)
    {
        root->right->next = root->next->left;
    }

    connect(root->left);
    connect(root->right);

    return root;
}