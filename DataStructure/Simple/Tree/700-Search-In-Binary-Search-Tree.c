#include "../../../Library/header.h"

/**
 * @author HEXDude
 * @date 2022/4/30
 * @description 给定二叉搜索树(BST)的根节点root和一个整数值val.你需要在BST中找到节点值等于val的节点,返回以该节点为根的子树.如果节点不存在,则返回null.
 * @link https://leetcode-cn.com/problems/search-in-a-binary-search-tree
 * @conclusion 二叉搜索树的,性质为左子树所有节点小于根节点,右子树所有节点大于根节点,因此每次递归判断当前根节点是否大于目标值,如果大于,则遍历左子树,
 * 否则遍历右子树.
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

struct TreeNode *searchBST(struct TreeNode *root, int val);

int main() {

	struct TreeNode *tree = malloc(sizeof(struct TreeNode));
	tree->val = 4;
	tree->left = malloc(sizeof(struct TreeNode));
	tree->left->val = 2;
	tree->left->left = malloc(sizeof(struct TreeNode));
	tree->left->left->val = 1;
	tree->left->left->left = NULL;
	tree->left->left->right = NULL;
	tree->left->right = malloc(sizeof(struct TreeNode));
	tree->left->right->val = 3;
	tree->left->right->left = NULL;
	tree->left->right->right = NULL;
	tree->right = malloc(sizeof(struct TreeNode));
	tree->right->val = 7;
	tree->right->left = NULL;
	tree->right->right = NULL;
	struct TreeNode *result = searchBST(tree, 2);
	free(tree);
}

struct TreeNode *searchBST(struct TreeNode *root, int val) {
	if (root == NULL) {
		return NULL;
	}
	if (root->val == val) {
		return root;
	}
	return searchBST(val > root->val ? root->right : root->left, val);
}
