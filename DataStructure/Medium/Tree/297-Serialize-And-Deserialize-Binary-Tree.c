#include "../../../Library/header.h"

/**
 * @author HEXDude
 * @date 2022/5/22
 * @description 序列化与反序列化二叉树
 * @link https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/
 * @conclusion
 */

void preOrder(struct TreeNode *root, char *res) {            //前序遍历
	if (root == NULL) {
		strcat(res, "#");                                //空结点则为“#”
		strcat(res, ",");                                //每个结点元素间用“，”间隔
		return;
	}
	char temp[10] = "";                                    //临时储存遍历结点元素的值
	sprintf(temp, "%d", root->val);                        //转换为字符
	strcat(res, temp);                                    //添加到序列之后
	strcat(res, ",");
	preOrder(root->left, res);                            //递归将左子树序列化
	preOrder(root->right, res);                            //递归将右子树序列化
}

char *serialize(struct TreeNode *root) {
	char *res = (char *) malloc(sizeof(char) * 50000);
	memset(res, '\0', sizeof(char) * 50000);                //初始化结果
	preOrder(root, res);
	return res;
}

/** Decodes your encoded data to tree. */
struct TreeNode *buildTree(char *data, int *index) {
	if (data[*index] == '#') {                                //空结点
		(*index) += 2;                                    //跳过“#”和“，”
		return NULL;
	}
	struct TreeNode *root = (struct TreeNode *) malloc(sizeof(struct TreeNode));
	char temp[10] = "";                                    //临时储存该结点的序列
	for (int i = 0; data[*index] != ','; ++i, ++(*index))    //遍历该结点的序列
		temp[i] = data[*index];
	++(*index);
	root->val = atoi(temp);                                //转化为整型
	root->left = buildTree(data, index);                    //递归生成左子树
	root->right = buildTree(data, index);                //递归生成右子树
	return root;
}

struct TreeNode *deserialize(char *data) {
	int index = 0;
	return buildTree(data, &index);
}