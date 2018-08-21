#include <stdio.h>

int dp[10001];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int val;
		scanf("%d", &val);
		dp[i] = dp[i - 1] + val;
	}
	int interval = 1;
	int res = 0;
	while (n >= interval) {
		for (int i = 0; i <= n; i++) {
			if (i + interval > n) break;
			if (dp[i + interval] - dp[i] ==m) {
				res++;
			}
		}
		interval++;
	}
	printf("%d", res);
}