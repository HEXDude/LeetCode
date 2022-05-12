#include "../../../Library/header.h"

/**
 * @author HEXDude
 * @date 2022/4/29
 * @description 给你一棵二叉树的根节点root,翻转这棵二叉树,并返回其根节点.
 * @link https://leetcode-cn.com/problems/invert-binary-tree/
 * @conclusion 根节点后的左右节点分别递归下去,每次递归交换左右节点
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

struct TreeNode *invertTree(struct TreeNode *root);

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

	struct TreeNode *result = invertTree(tree);
	free(tree);
}

struct TreeNode *invertTree(struct TreeNode *root) {
	if (root == NULL) {
		return NULL;
	}

	/**
	 * 根节点后的左右节点分别递归下去
	 * 每次递归交换左右节点
	 */
	struct TreeNode *left = invertTree(root->left);
	struct TreeNode *right = invertTree(root->right);
	root->left = right;
	root->right = left;
	return root;
}
