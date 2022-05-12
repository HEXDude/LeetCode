#include "../../../Library/header.h"

/**
 * @author HEXDude
 * @date 2022/4/29
 * @description 给你一个二叉树的根节点root,检查它是否轴对称.
 * @link https://leetcode-cn.com/problems/symmetric-tree/
 * @conclusion 递归,从根节点开始对左右分支进行判断,判断左右节点是否一致
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

bool isSymmetric(struct TreeNode *root);

bool symmetrical(struct TreeNode *left, struct TreeNode *right);

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

	bool result = isSymmetric(tree);
	free(tree);
}

bool symmetrical(struct TreeNode *left, struct TreeNode *right) {
	if (left == NULL && right == NULL)
		return true;
	if (left == NULL || right == NULL)
		return false;
	if (left->val != right->val)
		return false;

	return symmetrical(left->left, right->right) && symmetrical(left->right, right->left);
}

bool isSymmetric(struct TreeNode *root) {
	if (root == NULL) {
		return true;
	}

	return symmetrical(root->left, root->right);
}
