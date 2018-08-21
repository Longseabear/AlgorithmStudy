#include <stdio.h>
#include <memory.h>
int dp[21][10001];
int coin[21];
int main() {
	int testCase;
	scanf("%d", &testCase);
	while (testCase--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &coin[i]);
		}
		int m;
		scanf("%d", &m);
		for (int i = 1; i <= 20; i++) {
			dp[i][0] = 1;
		}
		for (int i = coin[1]; i <= m; i += coin[1]) {
			dp[1][i] = 1;
		}
		for (int c = 2; c <= n; c++) {
			for (int j = 1; j <= m; j++) {
				dp[c][j] = dp[c-1][j];
				if (j - coin[c] >= 0) {
					dp[c][j] += dp[c][j - coin[c]];
				}
			}
		}

		printf("%d\n", dp[n][m]);
		memset(dp, 0, sizeof(int) * 21 * 10001);
	}
}