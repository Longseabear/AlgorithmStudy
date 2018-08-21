#include <stdio.h>
#include <algorithm>
using namespace std;
int map[26];
int main() {
	int n;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		char c;
		scanf("%c", &c);
		map[c - 'a']++;
	}
	auto t = max_element(map, map + 26);
	printf("%c %d",t-map+'a', *t);
}
