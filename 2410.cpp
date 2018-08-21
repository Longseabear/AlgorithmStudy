#include <stdio.h>
int dp[20][1000001];
int main() {
	const long long m = 1e9;
	int n;
	scanf("%d", &n);
	dp[0][0] = 1;
	for (int j = 1; j <= n; j++) {
		dp[0][j] = 1;
	}

	int i;
	for (i = 1; i < 21; i++) {
		long long val = (1 << i);
		if (val > n) {
			break;
		}
		for (int j = 0; j <= n; j++) {
			dp[i][j] = (dp[i][j]+(long long)dp[i-1][j])%m;
			if (j - val >= 0) {
				dp[i][j] = (dp[i][j] + (long long)dp[i][j - val])%m;
			}
		}
	}
	printf("%d\n", dp[--i][n]%m);
}