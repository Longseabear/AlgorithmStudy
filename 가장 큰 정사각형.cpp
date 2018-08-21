#include <stdio.h>

int dp[1001][1001];
int n, m;

int isValidedIndex(int i, int j) {
	if (i >= 0 && i<n && j>=0 && j<m) {
		return 1;
	}
	return 0;
}
int MAX(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}
int MIN(int a, int b) {
	if (a > b)
		return b;
	else
		return a;
}
int main() {
	char c;
	scanf("%d %d", &n, &m);
	scanf("%c", &c);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++) {
			scanf("%c", &dp[i][j]);
			dp[i][j] -= '0';
			if (i == 0 || j == 0) continue;
			if (dp[i][j] == 1) {
				if (isValidedIndex(i - 1, j) && isValidedIndex(i, j - 1)) {
					int min = MIN(dp[i - 1][j], dp[i][j - 1]);
					if (min <= 0) {
						continue;
					}
					for (int k = min; k >= 1; k--) {
						if (dp[i - k][j - k] > 0) {
							dp[i][j] += min;
							break;
						}
						min--;
					}
				}
			}
		}
		scanf("%c", &c);
	}
	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			max = MAX(max, dp[i][j]);
		}
	}
	printf("%d\n", max*max);
}