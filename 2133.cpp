#include <stdio.h>

// �������� ��� ǰ.
// 2*3 ���� 2��° �� 2��° ���� ��� ���� ����.
long long dp[31];
int main() {
	int n;
	scanf("%d", &n);
	if (n % 2 == 1) {
		printf("%d\n", 0);
		return 0;
	}
	dp[0] = 1;
	dp[2] = 3;
	for (int i = 4; i <= n; i+=2) {
		dp[i] = dp[i - 2]*3;
		for (int j = i - 4; j >= 0; j -= 2) {
			dp[i] += dp[j] * 2;
		}
	}
	printf("%d\n", dp[n]);
}