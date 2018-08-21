#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int dp[1001];
int arr[1001];
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		dp[i] = arr[i];
		for (int j = i; j >= 0; j--) {
			if (dp[i] < dp[j]+arr[i] && arr[j]<arr[i]) {
				dp[i] = dp[j]+arr[i];
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum = max(sum, dp[i]);
	}
	printf("%d", sum);
}