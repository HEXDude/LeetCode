#include "../../../Library/header.h"

/**
 * @author HEXDude
 * @date 2022/5/1
 * @description 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
 * @link https://leetcode-cn.com/problems/validate-binary-search-tree/
 * @conclusion 递归
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

bool isValidBST(struct TreeNode *root);

bool validate(struct TreeNode *root, long lower, long upper);

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

	bool result = isValidBST(tree);
	free(tree);
}


bool isValidBST(struct TreeNode *root) {

	return validate(root, LONG_MIN, LONG_MAX);
}
/**
 * 遍历根节点的左子树,右子树.并在根节点时设置上界下界为long型的最大最小值(防止溢出).
 * 开始递归左右子树的子节点,如果是左节点,那么将上一个根节点的值设为上界,由于递归下来,上一个根节点一定也满足val < root.val,
 * 如果左节点小于上界或为空,则true,右子树相反.
 */
bool validate(struct TreeNode *root, long lower, long upper) {
	if (root == NULL) { return true; }
	if (root->val <= lower || root->val >= upper) { return false; }
	return validate(root->left, lower, root->val) && validate(root->right, root->val, upper);
}
