#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include "../../../Library/uthash.h"

/**
 * @author HEXDude
 * @date 2022/4/30
 * @description 给定二叉搜索树(BST)的根节点root和要插入树中的值value,将值插入二叉搜索树.
 * 返回插入后二叉搜索树的根节点.输入数据保证,新值和原始二叉搜索树中的任意节点值都不同.
 * @link https://leetcode-cn.com/problems/insert-into-a-binary-search-tree
 * @conclusion 比较Val与当前根节点的值,当val大于根节点时,遍历其右子树,直至递归到叶子节点(即root == NULL)时,
 * 创建一个新节点添加到右树,反之亦然.
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

struct TreeNode *insertIntoBST(struct TreeNode *root, int val);

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
	struct TreeNode *result = insertIntoBST(tree, 10);
	free(tree);
}

struct TreeNode *insertIntoBST(struct TreeNode *root, int val) {

	/**
	 * 按大小顺序一路遍历下来,碰到NULL说明已经到达叶子节点
	 * 可以新建一个叶子节点,插入到书中,return回溯到对应的左右子树
	 */
	if (root == NULL) {
		struct TreeNode *insertPoint = malloc(sizeof(struct TreeNode));
		insertPoint->val = val;
		insertPoint->left = NULL;
		insertPoint->right = NULL;
		return insertPoint;
	}

	/**
	 * 根据val的大小递归根的左右子树
	 */
	if (val < root->val) {
		root->left = insertIntoBST(root->left, val);
	} else {
		root->right = insertIntoBST(root->right, val);
	}

	return root;
}
