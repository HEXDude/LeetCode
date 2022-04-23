#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include <C:\Users\HEXDude\WorkSpace\LeetCode\Library\uthash.h>

/**
 * @author HEXDude
 * @date 2022/4/23
 * @description 给定一个字符串s,找到它的第一个不重复的字符,并返回它的索引.如果不存在,则返回-1。
 * @link https://leetcode-cn.com/problems/contains-duplicate/
 * @conclusion Hash查找,O(n)
 */

/**
 * 第三方HashMap实现
 */
struct HashMap {
	/**
	 * 键
	 */
	int key;
	/**
	 * 值
	 */
	int value;
	/**
	 * 三方Hash工具
	 */
	UT_hash_handle hh;
};

struct HashMap *map;

int firstUniqChar(char *s);

int main() {
	char *s = "bd";
	int result = firstUniqChar(s);
}

int firstUniqChar(char *s) {
	for (int i = 0; i < strlen(s); ++i) {
		int flag = s[i];
		struct HashMap *temp;
		HASH_FIND_INT(map, &flag, temp);
		if (temp != NULL) {
			temp->value += 1;
		} else {
			temp = malloc(sizeof(*temp));
			temp->key = flag;
			temp->value = 1;
			HASH_ADD_INT(map, key, temp);
		}
	}

	for (int i = 0; i < strlen(s); ++i) {
		int flag = s[i];
		struct HashMap *temp;
		HASH_FIND_INT(map, &flag, temp);
		if (temp != NULL && temp->value == 1) {
			return i;
		}
	}

	HASH_CLEAR(hh, map);
	return -1;
}