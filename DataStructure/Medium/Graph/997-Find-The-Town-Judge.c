#include "../../../Library/header.h"

/**
 * @author HEXDude
 * @date 2022/5/23
 * @description 小镇里有 n 个人，按从 1 到 n 的顺序编号。传言称，这些人中有一个暗地里是小镇法官。
 * 如果小镇法官真的存在，那么：
 * 小镇法官不会信任任何人。
 * 每个人（除了小镇法官）都信任这位小镇法官。
 * 只有一个人同时满足属性 1 和属性 2 。
 * 给你一个数组 trust ，其中 trust[i] = [ai, bi] 表示编号为 ai 的人信任编号为 bi 的人。
 * 如果小镇法官存在并且可以确定他的身份，请返回该法官的编号；否则，返回 -1 。
 * @link https://leetcode.cn/problems/find-the-town-judge
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

int findJudge(int n, int **trust, int trustSize, int *trustColSize);

int main() {
	//CLion控制台不输出问题,设置缓冲区
	setbuf(stdout, NULL);
	int trustSize = 2;
	int trustColSize = 2;
	int **trust = malloc(sizeof(int *) * trustSize);
	for (int i = 0; i < trustSize; ++i) {
		trust[i] = malloc(sizeof(int) * trustColSize);
	}
	trust[0][0] = 1;
	trust[0][1] = 3;
	trust[1][0] = 2;
	trust[1][1] = 3;
	int result = findJudge(3, trust, trustSize, &trustColSize);
	free(trust);
}

int findJudge(int n, int **trust, int trustSize, int *trustColSize) {
	//入度
	int *inDegrees = (int *) malloc(sizeof(int) * (n + 1));
	//出度
	int *outDegrees = (int *) malloc(sizeof(int) * (n + 1));
	memset(inDegrees, 0, sizeof(int) * (n + 1));
	memset(outDegrees, 0, sizeof(int) * (n + 1));
	for (int i = 0; i < trustSize; ++i) {
		int x = trust[i][0], y = trust[i][1];
		++inDegrees[y];
		++outDegrees[x];
	}
	for (int i = 1; i <= n; ++i) {
		if (inDegrees[i] == n - 1 && outDegrees[i] == 0) {
			return i;
		}
	}
	return -1;
}
