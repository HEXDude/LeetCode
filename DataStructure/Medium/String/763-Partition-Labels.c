#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include <C:\Users\HEXDude\WorkSpace\LeetCode\Library\uthash.h>

/**
 * @author HEXDude
 * @date 2022/5/11
 * @description 字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。返回一个表示每个字符串片段的长度的列表。
 * @link https://leetcode.cn/problems/partition-labels/
 * @conclusion
 */

int *partitionLabels(char *s, int *returnSize);

int main() {
	//CLion控制台不输出问题,设置缓冲区
	setbuf(stdout, NULL);
	char *s = "ababcbacadefegdehijhklij";
	int returnSize = 3;
	int *result = partitionLabels(s, &returnSize);
}

/**
 * 题目的意思是将给定的一个字符串分割,每个字符串中出现的字符不能在其它字符串出现
 * 并且给定的字符串中只有26个小写字母,那么根据ASCII码可以构建一个26位的数组作为Hash映射存储
 * 每个字符最后一次出现的下标.
 */
int *partitionLabels(char *s, int *returnSize) {
	int length = strlen(s);
	int hash[26] = {-1};
	for (int i = 0; i < length; ++i) {
		hash[s[i] - 'a'] = i;
	}
	int *partition = malloc(sizeof(int) * length);
	int start = 0, end = 0;
	*returnSize = 0;
	for (int i = 0; i < length; i++) {
		end = fmax(end, hash[s[i] - 'a']);
		if (i == end) {
			partition[(*returnSize)++] = end - start + 1;
			start = end + 1;
		}
	}
	return partition;
}