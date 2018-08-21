#include <stdio.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
int dp[100001][2];

int main() {
	int n;
	scanf("%d", &n);

	int val;
	scanf("%d", &val);
	dp[1][0] = val;
	dp[1][1] = val;

	for (int i = 2; i <= n; i++) {
		int val;
		scanf("%d", &val);
		dp[i][0] = val;
		dp[i][1] = -987654321;

		dp[i][0] = MAX(dp[i][0], dp[i - 1][0]+val);
		if (val < 0) {
			if (dp[i - 1][0] > dp[i - 1][1] + val) {
				dp[i][1] = dp[i - 1][0];
			}
			else {
				dp[i][1] = dp[i - 1][1]+val;
			}
		}
		else {
			dp[i][1] = dp[i - 1][1] + val;
		}
	}
	int max = -987654321;
	for (int i = 1; i <= n; i++) {
		max = MAX(dp[i][0], max);
		max = MAX(dp[i][1], max);
	}
	printf("%d", max);
}