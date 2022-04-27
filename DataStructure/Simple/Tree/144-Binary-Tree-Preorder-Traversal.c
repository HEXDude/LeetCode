#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include "../../../Library/uthash.h"

/**
 * @author HEXDude
 * @date 2022/4/27
 * @description 二叉树的前序遍历
 * @link https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
 * @conclusion	前序遍历就是根->左->右
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

int *preorderTraversal(struct TreeNode *root, int *returnSize);

int main() {

	struct TreeNode *tree = malloc(sizeof(struct TreeNode));
	tree->val = 1;
	tree->left = NULL;
	tree->right = malloc(sizeof(struct TreeNode));
	tree->right->val = 2;
	tree->right->right = NULL;
	tree->right->left = malloc(sizeof(struct TreeNode));
	tree->right->left->val = 3;
	tree->right->left->left = NULL;
	tree->right->left->right = NULL;
	int resSize[3];
	int *result = preorderTraversal(tree, resSize);
	for (int i = 0; i < 1000; ++i) {
		printf("%d\r", result[i]);
	}
	free(tree);
}

void preorder(struct TreeNode *root, int *res, int *resSize) {
	if (root == NULL) {
		return;
	}
	res[(*resSize)++] = root->val;
	preorder(root->left, res, resSize);
	preorder(root->right, res, resSize);
}

int *preorderTraversal(struct TreeNode *root, int *returnSize) {
	int *res = malloc(sizeof(int) * 2000);
	*returnSize = 0;
	preorder(root, res, returnSize);
	return res;
}