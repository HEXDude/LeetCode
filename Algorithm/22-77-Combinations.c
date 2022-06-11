#include "../Library/header.h"

/**
 * @author HEXDude
 * @date 2022-6-11
 * @ref https://leetcode.cn/problems/combinations/
 * @breif 给定两个数字n,k,求[1,n]之间所有n个数的组合
 * 例如4,2返回1,2|1,3|1,4|2,3...
 */

int** combine(int n, int k, int* returnSize, int** returnColumnSizes);

int main() {
    int ** result = combine(4, 2, NULL, NULL);
}

int recursion(int n, int k) {
    if (n == 0 || k == 0) {
        return 0;
    }
    int x = recursion(n-1, k-1);
    x = k;
    return x;
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    recursion(n, k);
    return NULL;
}