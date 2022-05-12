#include "../../../Library/header.h"

/**
 * @author HEXDude
 * @date 2022/4/29
 * @description 给定一个二叉树,找出其最大深度.
 * @link https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
 * @conclusion 递归,从根节点开始对左右分支进行判断,如果左右节点皆为空,返回.
 */

/**
 * 实现二叉树
 */
struct TreeNode {
	//节点值
	int val;
	//左子节点
	struct TreeNode *left;
	//右子节点
	struct TreeNode *right;
};

int maxDepth(struct TreeNode *root);

int main() {

	struct TreeNode *tree = malloc(sizeof(struct TreeNode));
	tree->val = 3;
	tree->left = malloc(sizeof(struct TreeNode));
	tree->left->val = 9;
	tree->left->left = malloc(sizeof(struct TreeNode));
	tree->left->left->val = 12;
	tree->left->left->left = NULL;
	tree->left->left->right = NULL;
	tree->left->right = NULL;
	tree->right = malloc(sizeof(struct TreeNode));
	tree->right->val = 20;
	tree->right->left = malloc(sizeof(struct TreeNode));
	tree->right->left->val = 15;
	tree->right->left->left = NULL;
	tree->right->left->right = NULL;
	tree->right->right = malloc(sizeof(struct TreeNode));
	tree->right->right->val = 7;
	tree->right->right->left = NULL;
	tree->right->right->right = NULL;

	int result = maxDepth(tree);
	free(tree);
}

int maxDepth(struct TreeNode *root) {
	if (root == NULL) return 0;
	return fmax(maxDepth(root->left), maxDepth(root->right)) + 1;
}
