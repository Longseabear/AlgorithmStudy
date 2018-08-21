#include <stdio.h>
const int UP = 0;
const int DOWN = 1;
const int value = 2;

int dp[1001][3];
int max(int a, int b) {
	if (a > b) return a;
	return b;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &dp[i][value]);
		dp[i][UP] = 1;
		dp[i][DOWN] = 1;
		for (int j = i; j >= 0; j--) {
			if (dp[j][value] < dp[i][value] && dp[j][UP] + 1 > dp[i][UP]) {
				dp[i][UP] = dp[j][UP] + 1;
			}
			if (dp[j][value] > dp[i][value]) {
				int maxVal = max(dp[j][UP], dp[j][DOWN]);
				if (maxVal + 1 > dp[i][DOWN]) {
					dp[i][DOWN] = maxVal + 1;
				}
			}
		}
	}
	int max_ = 0;
	for (int i = 0; i < n; i++) {
		int maxVal = max(dp[i][UP], dp[i][DOWN]);
		if (maxVal > max_) {
			max_ = maxVal;
		}
	}
	printf("%d", max_);

}