#include <stdio.h>
#include <string.h>
#include <stack>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
using namespace std;
char c[26];
char reC[26];
char T[300001];
int tLen, cLen;
typedef struct STACK {
	char val[300001];
	int index;
	 STACK()
	{
		index = 0;
		memset(val, 0, sizeof(char) * 300001);
	}
	int size() {
		return index;
	}
	int empty() {
		return !index;
	}
	void push(char c) {
		val[index++] = c;
	}
	void pop() {
		val[--index] = 0;
	}
	char top() {
		return val[index-1];
	}
	int check(char c[26]) {
		if (index < cLen) return 0;
//		printf("%s/%s", val + index - cLen, c);
		return !strcmp(val+index - cLen, c);
	}
}Stack;

Stack frontS;
Stack backS;
int backCheck() {
	return 0;
}
int frontCheck() {

	return 0;
}
int main() {
	int left, right;
	scanf("%s", c);
	scanf("%s", T);
	cLen = strlen(c);
	tLen = strlen(T);

	for (int i = 0; i < cLen; i++) {
		reC[i] = c[cLen - 1 - i];
	}
	left = 0;
	right = tLen - 1;
	// get index
	int currentTurn = 0;
	while (left <= right) {
		if (currentTurn == 0) {
			//front
			frontS.push(T[left++]);
			if (frontS.check(c)) {
				for (int i = 0; i < cLen; i++) {
					frontS.pop();
				}
				currentTurn = !currentTurn;
			}
		}
		else {
			//back
			backS.push(T[right--]);
			if (backS.check(reC)) {
				for (int i = 0; i < cLen; i++) {
					backS.pop();
				}
				currentTurn = !currentTurn;
			}
		}
	}
	while (!frontS.empty() && !backS.empty()) {
		if (currentTurn == 0) {
			//front
			frontS.push(backS.top());
			backS.pop();
			if (frontS.check(c)) {
				for (int i = 0; i < cLen; i++) {
					frontS.pop();
				}
				currentTurn = !currentTurn;
			}
		}
		else {
			//back
			backS.push(frontS.top());
			frontS.pop();
			if (backS.check(reC)) {
				for (int i = 0; i < cLen; i++) {
					backS.pop();
				}
				currentTurn = !currentTurn;
			}
		}
	}
	vector<char> res;
	if (!frontS.empty()) {
		int frontSize = frontS.size();
		for (int i = 0; i < frontSize; i++) {
			printf("%c", frontS.val[i]);
		}
	}
	if (!backS.empty()) {
		int backNum = backS.size();
		for (int i = backNum - 1; i >= 0; i--) {
			printf("%c", backS.val[i]);
		}
	}
	printf("\n");
}