#include <stdio.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
int main() {
	int max = 0;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int c[3];
		for (int i = 0; i < 3; i++) {
			scanf("%d", &c[i]);
		}
		if (c[0] == c[1] && c[1] == c[2]) {
			max = MAX(max, 10000 + c[0] * 1000);
		}
		else if (c[0] == c[1] || c[0] == c[2]) {
			max = MAX(max, 1000 + c[0] * 100);
		}
		else if (c[1] == c[2]) {
			max = MAX(max, 1000 + c[1] * 100);
		}
		else {
			int maxNoon = MAX(c[0], c[1]);
			maxNoon = MAX(maxNoon, c[2]);
			max = MAX(max, maxNoon * 100);
		}
	}
	printf("%d", max);
}