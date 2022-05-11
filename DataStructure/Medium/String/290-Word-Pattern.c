#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include <C:\Users\HEXDude\WorkSpace\LeetCode\Library\uthash.h>

/**
 * @author HEXDude
 * @date 2022/5/11
 * @description 给定一种规律 pattern和一个字符串s，判断 s是否遵循相同的规律。
 * 这里的遵循指完全匹配，例如，pattern里的每个字母和字符串str中的每个非空单词之间存在着双向连接的对应规律。
 * @link https://leetcode.cn/problems/word-pattern
 * @conclusion
 */

/**
 * UTHash实现
 */
struct HashMap {
	/**
	 * 键
	 */
	char *key;
	/**
	 * 值
	 */
	char *value;
	/**
	 * 三方Hash工具
	 */
	UT_hash_handle hh;
};

/**
 * HashMap
 */
struct HashMap *map = NULL;

bool establish(char *tempPattern, char *tempWord);

bool wordPattern(char *pattern, char *s);

int main() {
	//CLion控制台不输出问题,设置缓冲区
	setbuf(stdout, NULL);
	char *pattern = "abc";
	char *s = "b c a";
	bool result = wordPattern(pattern, s);
}

/**
 * 判断tempPattern与tempWord是否能建立双射关系
 * @param tempPattern pattern元素
 * @param tempWord words元素
 * @return true
 * @return false
 */
bool establish(char *tempPattern, char *tempWord) {
	//pattern到word映射关系查询结果
	struct HashMap *patternWordMapping;
	//word到pattern映射关系查询结果
	struct HashMap *wordPatternMapping;

	HASH_FIND_STR(map, tempPattern, patternWordMapping);
	HASH_FIND_STR(map, tempWord, wordPatternMapping);

	/**
	 * 只需判断两种情况:
	 * 1.都为空,那么说明pattern和word都还未建立映射关系.
	 * 2.都不为空,那么需判断存储的映射关系与参数能否正确成为双射关系.
	 * 其它情况都说明双射关系不成立.
	 */
	if (patternWordMapping == NULL && wordPatternMapping == NULL) {
		patternWordMapping = malloc(sizeof(struct HashMap));
		wordPatternMapping = malloc(sizeof(struct HashMap));
		patternWordMapping->key = tempPattern;
		patternWordMapping->value = tempWord;
		wordPatternMapping->key = tempWord;
		wordPatternMapping->value = tempPattern;
		HASH_ADD_STR(map, key, patternWordMapping);
		HASH_ADD_STR(map, key, wordPatternMapping);
		return true;
	} else if (patternWordMapping != NULL && wordPatternMapping != NULL) {
		if (strcmp(patternWordMapping->key, wordPatternMapping->value) == 0 &&
		    strcmp(patternWordMapping->value, wordPatternMapping->key) == 0) {
			return true;
		}
	}

	return false;
}

/**
 * 建立双指针同步从头到尾遍历pattern和words.
 * pattern自增为每字符,words自增为每单词(以空格活到底字符串结尾).
 * 将pattern元素转换成String可以节省一个HashMap O(2n)的空间.
 */
bool wordPattern(char *pattern, char *s) {
	int patternLength = strlen(pattern);
	int sLength = strlen(s);

	if (patternLength == sLength == 1) {
		return true;
	}

	int pIndex = 0, sIndex = 0;
	//接收pattern元素转换后的字符串
	char tempPattern[2];
	tempPattern[1] = '\0';
	//接收words中的元素
	char *word = malloc(sizeof(char) * 10);

	while (pIndex < patternLength && sIndex < sLength) {
		tempPattern[0] = pattern[pIndex++];

		//取Words中的单词,在遇到空格活字符串最大长度后后停止读取
		int wordCount = 0;
		for (int i = sIndex; i <= sLength; ++i) {
			if (s[i] != ' ' && sIndex < sLength) {
				word[wordCount++] = s[i];
			} else {
				sIndex = i + 1;
				word[wordCount++] = 0;
				break;
			}
		}

		if (establish(tempPattern, word) == false) {
			return false;
		}
	}

	free(word);
	HASH_CLEAR(hh, map);
	return true;
}
