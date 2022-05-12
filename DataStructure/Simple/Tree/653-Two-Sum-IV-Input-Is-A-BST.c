#include "../../../Library/header.h"

/**
 * @author HEXDude
 * @date 2022/5/1
 * @description 给定一个二叉搜索树root和一个目标结果k,如果BST中存在两个元素且它们的和等于给定的目标结果,则返回 true.
 * @link https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/
 * @conclusion 深度优先搜索递归遍历二叉树所有节点,每当到达一个叶子节点(NULL)为false,否则只有当遍历过程中
 * HashSet中存在被遍历节点的被减数存在.
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

/**
 * 第三方HashSet实现
 */
struct HashSet {
	/**
	 * 键
	 */
	int key;
	/**
	 * 三方Hash工具
	 */
	UT_hash_handle hh;
};

bool findTarget(struct TreeNode *root, int k);

bool recursion(struct HashSet *set, struct TreeNode *root, int target);

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
	bool result = findTarget(tree, 9);
	free(tree);
}

bool findTarget(struct TreeNode *root, int k) {
	struct HashSet *set = NULL;

	return recursion(set, root, k);
}

bool recursion(struct HashSet *set, struct TreeNode *root, int target) {
	if (root == NULL) {
		return false;
	}

	struct HashSet *temp;
	int num = target - root->val;
	HASH_FIND_INT(set, &num, temp);
	if (temp != NULL) {
		return true;
	}
	temp = malloc(sizeof(struct HashSet));
	temp->key = root->val;
	HASH_ADD_INT(set, key, temp);
	return recursion(set, root->left, target) || recursion(set, root->right, target);
}

