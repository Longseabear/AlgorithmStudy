#include <stdio.h>

#define MIN(a,b) ((a)<(b)?(a):(b))
long long arr[100001];
int main() {
	int n; long long s;
	scanf("%d %lld", &n, &s);
	for (int i = 1; i <= n; i++) {
		long long val;
		scanf("%lld", &val);
		arr[i] = arr[i - 1] + val;
	}
	int left = 0, right = 1; long long min = 987654321;
	while (left <= n && right < n+1) {
		if (arr[right] - arr[left] >= s) {
			min = MIN(min, right - left);
			left ++;
		}
		else {
			right++;
		}
		while (right <= left) right++;
	}
	if (min == 987654321) {
		printf("0");
	}
	else {
	printf("%lld", min);
	}
}