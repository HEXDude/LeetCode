#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include <C:\Users\HEXDude\WorkSpace\LeetCode\Library\uthash.h>

/**
 * @author HEXDude
 * @date 2022/4/23
 * @description 给你两个字符串:ransomNote和magazine,判断ransomNote能不能由magazine里面的字符构成.
 * 如果可以,返回true;否则返回 false.
 * magazine中的每个字符只能在ransomNote中使用一次。
 * @link https://leetcode-cn.com/problems/contains-duplicate/
 * @conclusion 根据字符的ASCII码建立统计表,先统计杂志里的字符,再根据赎金信里的字符使用次数相减,当
 * 需使用但次数为零时,说明无法组成.也算是一中Hash的写法.O(n)
 */
bool canConstruct(char *ransomNote, char *magazine);

int main() {
	char *ransomNote = "aa";
	char *magazine = "aab";
	bool result = canConstruct(ransomNote, magazine);
}

bool canConstruct(char *ransomNote, char *magazine) {
	int ransomNoteLength = strlen(ransomNote);
	int magazineLength = strlen(magazine);
	if (ransomNoteLength > magazineLength) {
		return false;
	}

	int alphabet[123];
	memset(alphabet, 0, sizeof(int) * 123);

	for (int i = 0; i < magazineLength; ++i) {
		alphabet[magazine[i]]++;
	}

	for (int i = 0; i < ransomNoteLength; ++i) {
		if (alphabet[ransomNote[i]] == 0) {
			return false;
		}
		alphabet[ransomNote[i]]--;
	}
	return true;
}