#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
int dp[100001];
const int MAX_NUM = 100001;
int main() {
	int n;
	scanf("%d", &n);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = MAX_NUM;
		for (int j = 1; j <= (int)sqrt(i); j++) {
			dp[i] = min(dp[i], dp[i - j * j]+1);
		}
	}
	printf("%d", dp[n]);
}