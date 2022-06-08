#include "../Library/header.h"

/**
 * @author HEXDude
 * @date 2022-6-8
 * @ref https://leetcode.cn/problems/merge-two-binary-trees/
 * @breif 给你两棵二叉树： root1 和 root2 。
 * 合并两个二叉树,如果重叠的部分则相加,不为null的成为新的节点
 */

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *mergeTrees(struct TreeNode *root1, struct TreeNode *root2);

int main()
{
    struct TreeNode *root1 = malloc(sizeof(struct TreeNode));
    root1->val = 1;
    root1->left = malloc(sizeof(struct TreeNode));
    root1->left->val = 3;
    root1->left->left = malloc(sizeof(struct TreeNode));
    root1->left->left->val = 5;
    root1->left->left->left = NULL;
    root1->left->left->right = NULL;
    root1->left->right = NULL;
    root1->right = malloc(sizeof(struct TreeNode));
    root1->right->val = 2;
    root1->right->left = NULL;
    root1->right->right = NULL;

    struct TreeNode *root2 = malloc(sizeof(struct TreeNode));
    root2->val = 2;
    root2->left = malloc(sizeof(struct TreeNode));
    root2->left->val = 1;
    root2->left->left = NULL;
    root2->left->right = malloc(sizeof(struct TreeNode));
    root2->left->right->val = 4;
    root2->left->right->left = NULL;
    root2->left->right->right = NULL;
    root2->right = malloc(sizeof(struct TreeNode));
    root2->right->val = 3;
    root2->right->left = NULL;
    root2->right->right = malloc(sizeof(struct TreeNode));
    root2->right->right->val = 7;
    root2->right->right->left = NULL;
    root2->right->right->right = NULL;
    struct TreeNode *result = mergeTrees(root1, root2);
    free(root1);
    free(root2);
}

/**
 * 对二叉树采用先序遍历 根->左->右的方法递归
 * 递归过程中如果左或右为NULL,则将NULL节点直接返回
 * 作为新节点
 * 递的过程中不断创建新节点,在归的过程中return
 */
struct TreeNode *mergeTrees(struct TreeNode *root1, struct TreeNode *root2)
{
    /**
     * 任意一个节点为空,则返回另一颗树的当前节点
     */
    if (root1 == NULL)
    {
        return root2;
    }

    if (root2 == NULL)
    {
        return root1;
    }

    //创建新节点后对左右节点递归,归的时候return的值作为新节点
    struct TreeNode *merged = malloc(sizeof(struct TreeNode));
    merged->val = root1->val + root2->val;
    merged->left = mergeTrees(root1->left, root2->left);
    merged->right = mergeTrees(root1->right, root2->right);
    return merged;
}