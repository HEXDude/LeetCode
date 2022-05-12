#include "../../../Library/header.h"

/**
 * @author HEXDude
 * @date 2022/4/28
 * @description 二叉树的层序遍历,即逐层地,从左到右访问所有节点.
 * @link https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
 * @conclusion 根据栈的特性,将每层的所有节点按从左到右的顺序装入栈中,遍历下一个节点时,出栈上一节点值
 * TODO 不知道怎么拼返回值
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

int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes);

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

	levelOrder(tree, NULL, NULL);
	free(tree);
}

int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {
	if (root == NULL) {
		*returnSize = 0;
		**returnColumnSizes = 0;
		return returnColumnSizes;
	}

	/**
	 * 用数组建立一个队列,队头和队尾分别置为0
	 * 每当入队后,队尾自增
	 * 出队后,对头自增
	 */
	struct TreeNode *queue[2000];
	int front = 0, rear = 0;
	//将根节点添加到队列中
	queue[rear++] = root;

	while (front != rear) {
		/**
		 * tF,tR为了截取待出队的元素
		 * 每存在一个待出队的元素,至多可能存在两个子节点,如果存在,则入队,并出队该元素
		 */
		int tF = front, tR = rear;
		for (int i = tF; i < tR; ++i) {
			struct TreeNode *tempTree = queue[i];
			printf("%d\r", tempTree->val);
			if (tempTree->left != NULL) {
				queue[rear++] = tempTree->left;
			}
			if (tempTree->right != NULL) {
				queue[rear++] = tempTree->right;
			}
			front++;
		}
	}
	return NULL;
}
