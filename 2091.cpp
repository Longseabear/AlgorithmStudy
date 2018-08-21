#include <stdio.h>
#include <memory.h>
typedef struct node {
	int c[4];
	int total;
}Node;
Node dp[4][10001];
int coin[4];
int coin_value[4] = { 1,5,10,25 };
int MAX(int a, int b) {
	if (a > b) return a;
	return b;
}
int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < 4; i++) {
		scanf("%d", &coin[i]);
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j].total = -1;
		}
	}
	for (int j = 1; j <= coin[0]; j++) {
		dp[0][j].c[0] = j;
		dp[0][j].total = j;
	}
	for (int i = 1; i < 4; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i - 1][j].total >= 0) {
				dp[i][j].total = dp[i - 1][j].total;
				for (int l = 0; l < 4; l++) {
					dp[i][j].c[l] = dp[i - 1][j].c[l];
				}

			}

			for (int k = 1; k <= coin[i]; k++) {
				if (j - k * coin_value[i] < 0) break;
				if (dp[i - 1][j - k * coin_value[i]].total + k < dp[i][j].total || dp[i-1][j-k*coin_value[i]].total == -1) continue;

				dp[i][j].total = dp[i - 1][j - k * coin_value[i]].total + k;
				for (int l = 0; l < 4; l++) {
					dp[i][j].c[l] = dp[i - 1][j - k * coin_value[i]].c[l];
				}
				dp[i][j].c[i] += k;
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		printf("%d ", dp[3][n].c[i]);
	}
}