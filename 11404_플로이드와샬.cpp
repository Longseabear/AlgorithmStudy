#include <stdio.h>

#define MIN(a,b) ((a)<(b)?(a):(b))
int dp[100][100];
int main() {
	int n, b;
	scanf("%d %d", &n, &b);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = 987654321;
		}
	}
	while (b--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		dp[a-1][b-1] = MIN(dp[a-1][b-1], c);
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				dp[i][j] = MIN(dp[i][j], dp[i][k]+dp[k][j]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			if (dp[i][j] == 987654321) printf("0 ");
			else printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
}