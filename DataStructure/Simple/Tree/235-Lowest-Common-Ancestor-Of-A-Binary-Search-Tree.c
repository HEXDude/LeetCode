#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include "../../../Library/uthash.h"
#include <limits.h>

/**
 * @author HEXDude
 * @date 2022/5/1
 * @description 给定一个二叉搜索树,找到该树中两个指定节点的最近公共祖先.
 * @link https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 * @conclusion
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


struct TreeNode *lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q);

int main() {
	struct TreeNode *tree = malloc(sizeof(struct TreeNode));
	tree->val = 5;
	tree->left = malloc(sizeof(struct TreeNode));
	tree->left->val = 3;
	tree->left->left = malloc(sizeof(struct TreeNode));
	tree->left->left->val = 2;
	tree->left->left->left = NULL;
	tree->left->left->right = NULL;
	tree->left->right = malloc(sizeof(struct TreeNode));
	tree->left->right->val = 4;
	tree->left->right->left = NULL;
	tree->left->right->right = NULL;
	tree->right = malloc(sizeof(struct TreeNode));
	tree->right->val = 6;
	tree->right->left = NULL;
	tree->right->right = malloc(sizeof(struct TreeNode));
	tree->right->right->val = 7;
	tree->right->right->left = NULL;
	tree->right->right->right = NULL;
	struct TreeNode *result = lowestCommonAncestor(tree, tree->left, tree->right);
	free(tree);
}


struct TreeNode *lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q) {
	struct TreeNode *ancestor = root;
	while (true) {
		if (p->val < ancestor->val && q->val < ancestor->val) {
			ancestor = ancestor->left;
		} else if (p->val > ancestor->val && q->val > ancestor->val) {
			ancestor = ancestor->right;
		} else {
			break;
		}
	}
	return ancestor;
}

}

