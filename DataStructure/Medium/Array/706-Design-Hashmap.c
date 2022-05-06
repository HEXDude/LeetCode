#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include <C:\Users\HEXDude\WorkSpace\LeetCode\Library\uthash.h>
#include <limits.h>

/**
 * @author HEXDude
 * @date 2022/5/6
 * @description 不使用任何内建的哈希表库设计一个哈希映射（HashMap）。
 * @link https://leetcode-cn.com/problems/design-hashmap/
 * @conclusion 数组的随机访问是O(1),不知道为何Leetcode测试用例会超时,插入也是根据下标访问的,按理说应该很快,只有空间复杂度是O(n)
 */

/**
 * 使用一个int型数组作为键值对的存储
 * int型的key即为下标
 * 下标对应的元素即为value
 */
typedef struct {
	/**
	 * 存储键值对
	 */
	int *map;
} MyHashMap;

/**
 * 开辟一个结构体的空间并将内部存储结构全部设置为-1
 */
MyHashMap *myHashMapCreate() {
	MyHashMap *myHashMap = malloc(sizeof(MyHashMap));
	myHashMap->map = malloc(sizeof(int) * 10000000);
	memset(myHashMap->map, -1, sizeof(int) * 10000000);
	return myHashMap;
}

void myHashMapPut(MyHashMap *obj, int key, int value) {
	obj->map[key] = value;
}

int myHashMapGet(MyHashMap *obj, int key) {
	return obj->map[key];
}

void myHashMapRemove(MyHashMap *obj, int key) {
	obj->map[key] = -1;
}

void myHashMapFree(MyHashMap *obj) {
	free(obj);
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);

 * int param_2 = myHashMapGet(obj, key);

 * myHashMapRemove(obj, key);

 * myHashMapFree(obj);
*/

int main() {
	//CLion控制台不输出问题,设置缓冲区
	setbuf(stdout, NULL);
	struct MyHashMap *myHashMap = myHashMapCreate();
	myHashMapPut(myHashMap, 1, 2);
	int result = myHashMapGet(myHashMap, 1);
	myHashMapFree(myHashMap);
	return 0;
}

