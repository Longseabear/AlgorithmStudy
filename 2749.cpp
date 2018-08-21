#include <stdio.h>

int dp[5000000];
int check_idx = 0;
int fibo[5000000];
int main() {
	// 0 1 1 2 3 5
	int a = 0;
	int b = 1;
	dp[0] = 0;
	dp[1] = 1;
	bool check = false;
	for (int i = 2; i <= 1500000*2; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2])% 1000000;
	}
	long long n;
	scanf("%lld", &n);
	printf("%d", dp[n % 1500000ll]);
}