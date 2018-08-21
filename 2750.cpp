#include <stdio.h>

int a[3000];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int val;
		scanf("%d", &val);
		a[val + 1500] = 1;
	}
	for (int i = 0; i < 3000; i++) {
		if (a[i]) {
			printf("%d\n", i - 1500);
		}
	}
}