#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include <C:\Users\HEXDude\WorkSpace\LeetCode\Library\uthash.h>

/**
 * @author HEXDude
 * @date 2022/4/23
 * @description 给定两个字符串s和t,编写一个函数来判断t是否是s的字母异位词.
 * @link https://leetcode-cn.com/problems/valid-anagram/
 * @conclusion ASCII统计,O(n)
 */

bool isAnagram(char * s, char * t);

int main() {
	char *s = "rat";
	char *t = "car";
	bool result = isAnagram(s, t);
}

bool isAnagram(char * s, char * t){
	int sLength = strlen(s);
	int tLength = strlen(t);

	if (sLength != tLength) {
		return false;
	}

	int alphabet[123];
	memset(alphabet, 0, sizeof(int) * 123);

	for (int i = 0; i < sLength; ++i) {
		alphabet[s[i]]++;
	}

	for (int i = 0; i < tLength; ++i) {
		int x = alphabet[t[i]];
		if (alphabet[t[i]] < 1) {
			return false;
		}
		alphabet[t[i]]--;
	}

	return true;
}