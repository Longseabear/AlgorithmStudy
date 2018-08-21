#include <stdio.h>
#include <algorithm>
// parameteric search
// mid의 이동은 move가 없는 쪽으로.

using namespace std;
long long dp[100002];
int n, m;
long long min_money = 0;

bool success(int money) {
	long long current = money;
	long long count = 1;
	if (min_money > money) return false;
	for (int i = 1; i <= n+1; i++) {
		if (current < dp[i]) {
			count++;
			current = money;
		}
		current -= dp[i];
	}
	return count <= m;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &dp[i]);
		min_money = max(min_money, dp[i]);
	}
	long long left = 1;
	long long right = 1000000000;
	while (left < right) {
		long long mid = (left + right) / 2;
		if (success(mid)) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	printf("%lld", right);
}