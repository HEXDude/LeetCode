#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include <C:\Users\HEXDude\WorkSpace\LeetCode\Library\uthash.h>

/**
 * @author HEXDude
 * @date 2022/5/10
 * @description 给定一个包含大写字母和小写字母的字符串s，返回通过这些字母构造成的最长的回文串。
 * 在构造过程中，请注意 区分大小写 。比如"Aa"不能当做一个回文字符串。
 * @link https://leetcode.cn/problems/longest-palindrome
 * @conclusion
 */

int longestPalindrome(char * s);

int main() {
	//CLion控制台不输出问题,设置缓冲区
	setbuf(stdout, NULL);
	char *s = "ccc";
	int result = longestPalindrome(s);
}

/**
 * 是通过给定的字符串构造出最长的回文串,不是其中的回文子串
 * 那么首先取出字符串中的所有字符,如果每一个字符均出现两个,那么直接取出的size
 * 如何取,通过ASCII和数组,建立简单的HashMap
 */
int longestPalindrome(char * s){
	int length = strlen(s);
	if (length == 1) {
		return 1;
	}

	int ascii[128] = {0};

	for (int i = 0; i < length; ++i) {
		ascii[s[i]]++;
	}

	/**
	 * 如果任意字符出现了偶数次,那么构造的长度就加上此字符出现的次数
	 * 如果任意字符出现了奇数次,那么将奇数-1得到其偶数次数,并将奇数标识修正为出现
	 * 注意 1 % 2 == 1, 1 - 1 = 0;
	 */
	int result = 0;
	int odd = 0;
	for (int i = 0; i < 128; ++i) {
		if (ascii[i] != 0) {
			if (ascii[i] % 2 == 0) {
				result += ascii[i];
			} else {
				result += ascii[i]- 1;
				odd = 1;
			}
		}
	}

	return result + odd;
}