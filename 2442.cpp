#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int a = 1;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			printf(" ");
		}
		for (int j = 0; j < a; j++) {
			printf("*");
		}
		a += 2;
		printf("\n");
	}
}