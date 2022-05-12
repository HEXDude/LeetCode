#include "../../../Library/header.h"

/**
 * @author HEXDude
 * @date 2022/4/29
 * @description 给你二叉树的根节点root和一个表示目标和的整数targetSum.
 * 判断该树中是否存在根节点到叶子节点的路径,这条路径上所有节点值相加等于目标和targetSum.如果存在,返回true;否则,返回false.
 * @link https://leetcode-cn.com/problems/path-sum/
 * @conclusion 对于从根节点遍历,那么每次递归传递的都是sum值,那么应该在递归时对传递的sum值减去之前已经遍历
 * 过的节点值,当遍历到值相等的情况下,为true,否则为false
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

bool hasPathSum(struct TreeNode *root, int targetSum);

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

	bool result = hasPathSum(tree, 35);
	free(tree);
}


bool hasPathSum(struct TreeNode *root, int sum) {
	if (root == NULL) {
		return false;
	}

	/**
	 * 此时即为叶子节点
	 * 当叶子节点的值与值传递下来的sum值一致时,则为true,否则false
	 */
	if (root->left == NULL && root->right == NULL) {
		return root->val == sum;
	}
	return hasPathSum(root->left, sum - root->val) ||
	       hasPathSum(root->right, sum - root->val);
}
