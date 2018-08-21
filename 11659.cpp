#include <stdio.h>

int map[100001];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &map[i]);
		map[i] += map[i - 1];
	}
	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", map[b] - map[a - 1]);
	}
}