#include <stdio.h>
#include <math.h>
int dp[501][501];
int MAX(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}
int MIN(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		dp[1][i] = i;
	}
	for (int i = 2; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			int current_max = 987654321;
			for (int k = 1; k <= j; k++) {
				current_max = MIN(current_max,MAX(dp[i-1][k - 1] + 1, dp[i][j - k] + 1));
			}
			dp[i][j] = current_max;
		}
	}
	printf("%d", dp[k][n]);
}