#include <stdio.h>

long long n[10][65];
int main() {
	for (int i = 0; i < 10; i++) {
		n[i][1] = 1;
	}
	for (int i = 2; i <= 64; i++) {
		n[0][i] = 1;
		for (int j = 1; j < 10; j++) {
			n[j][i] = n[j][i - 1] + n[j - 1][i];
		}
	}
	int testCase;
	scanf("%d", &testCase);
	while (testCase--) {
		int num;
		scanf("%d", &num);

		long long sum = 0;
		for (int j = 0; j < 10; j++) {
			sum += n[j][num];
		}
		printf("%lld\n", sum);
	}
}