#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include "../../../Library/uthash.h"

/**
 * @author HEXDude
 * @date 2022/4/26
 * @description 给定一个只包括'('，')','{'，'}','['，']'的字符串s,判断字符串是否有效.
 * @link https://leetcode-cn.com/problems/valid-parentheses/
 * @conclusion 利用栈先进后出的规则,如果是左括号直接入栈,如果是右括号,则与栈顶元素进行配对,如果配对成功则出栈.O(m)
 */

bool isValid(char *s);

char pairs(char leftParentheses);

int main() {
	char *s = "()";
	bool result = isValid(s);
}

char pairs(char a) {
	if (a == '}') return '{';
	if (a == ']') return '[';
	if (a == ')') return '(';
	return 0;
}

bool isValid(char *s) {
	int n = strlen(s);
	if (n % 2 == 1) {
		return false;
	}
	int stk[n + 1], top = 0;
	for (int i = 0; i < n; i++) {
		char ch = pairs(s[i]);
		if (ch) {
			if (top == 0 || stk[top - 1] != ch) {
				return false;
			}
			top--;
		} else {
			stk[top++] = s[i];
		}
	}
	return top == 0;
}