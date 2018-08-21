#include <stdio.h>

int dp[126][126];
int main() {
	int testCase;
	scanf("%d", &testCase);
	while (testCase--) {
		int cost,n;
		scanf("%d", &cost);
		scanf("%d", &n);
		for (int i = 0; i != n; i++) {
			int num, val;
			scanf("%d %d", &num, &val);
			cost += num * val;
		}

		printf("%d\n", cost);
	}
}