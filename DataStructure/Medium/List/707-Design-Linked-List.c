#include "../../../Library/header.h"

/**
 * @author HEXDude
 * @date 2022/5/16
 * @description 设计链表
 * @link https://leetcode.cn/problems/design-linked-list/
 * @conclusion
 */

typedef struct MyLinkedList_t {
	int val;
	struct MyLinkedList_t *next;
} MyLinkedList;


MyLinkedList *myLinkedListCreate() {
	MyLinkedList *obj = (MyLinkedList *) malloc(sizeof(MyLinkedList));
	obj->val = 0;
	obj->next = NULL;
	return obj;
}

int myLinkedListGet(MyLinkedList *obj, int index) {
	if (index < 0 || obj->next == NULL) {
		return -1;
	}
	int x = 0;
	MyLinkedList *tmp = obj->next;
	while (x < index) {
		if (tmp == NULL) {
			return -1;
		}
		tmp = tmp->next;
		x++;
	}
	if (tmp != NULL) {
		return tmp->val;
	}
	return -1;
}

void myLinkedListAddAtHead(MyLinkedList *obj, int val) {
	MyLinkedList *node = (MyLinkedList *) malloc(sizeof(MyLinkedList));
	node->val = val;
	node->next = NULL;
	if (obj->next == NULL) {
		obj->next = node;
		return;
	} else {
		node->next = obj->next;
		obj->next = node;
	}
}

void myLinkedListAddAtTail(MyLinkedList *obj, int val) {
	MyLinkedList *node = (MyLinkedList *) malloc(sizeof(MyLinkedList));
	node->val = val;
	node->next = NULL;
	MyLinkedList *tmp = obj;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = node;
}

void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val) {
	if (index <= 0) {
		myLinkedListAddAtHead(obj, val);
		return;
	}
	int x = 0;
	MyLinkedList *tmp = obj;
	while (tmp->next != NULL) {
		if (x == index) {
			break;
		}
		tmp = tmp->next;
		x++;
	}
	if (x != index) {
		return;
	}
	MyLinkedList *node = (MyLinkedList *) malloc(sizeof(MyLinkedList));
	node->val = val;
	node->next = tmp->next;
	tmp->next = node;

}

void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index) {
	if (index < 0 || obj->next == NULL) {
		return;
	}
	if (index == 0) {
		obj->next = obj->next->next;
		return;
	}
	MyLinkedList *tmp = obj->next;
	int x = 0;
	while (tmp->next != NULL) {
		if (x == index - 1) {
			break;
		}
		tmp = tmp->next;
		x++;
	}

	if (x == index - 1 && tmp->next != NULL) {
		tmp->next = tmp->next->next;
	}
}

void myNodeFree(MyLinkedList *Node) {
	if (Node->next != NULL) {
		myNodeFree(Node->next);
		Node->next = NULL;
	}
	free(Node);
}

void myLinkedListFree(MyLinkedList *obj) {
	myNodeFree(obj);
}