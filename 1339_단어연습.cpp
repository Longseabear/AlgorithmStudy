#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int mapping[26];
char c[11][10];
int main() {
	int n, idx=0, sum=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {		
		scanf("%s", c[i]);
		int len = strlen(c[i]), digit = 1;
		for (int j = len - 1; j >= 0; j--, digit*=10) mapping[c[i][j] - 'A'] += digit;
	}
	sort(mapping, mapping + 26, [](int a, int b){return a > b;});
	while (mapping[idx]) {
		sum += mapping[idx] * (9 - idx);
		++idx;
	}
	printf("%d", sum);
}