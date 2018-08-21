#include <stdio.h>
#include <algorithm>

using namespace std;
long long N[10001];

int n; long long obj;
long long low = 0, high = 987654321;

long long binary(int low, int high, long long val) {
	if (low >= high) return 0;

	int mid = (low + high) / 2;
	long long mid_val = N[mid]/val;

	long long* index_low = upper_bound(N + low, N + high, mid_val*val - 1);
	long long* index_high = lower_bound(N + low, N + high, (mid_val+1)*val);
	
	long long res = (index_high - index_low) * mid_val;
	res += binary(low, index_low - N, val);
	res += binary(index_high - N, high, val);
	return res;
}
long long getVal(long long val) {
	/*long long frequency = 0;
	for (int i = 0; i < n; i++) {
		frequency += N[i] / val;
	}*/
	if (val == 0) return 987654321;
	return binary(0,n,val);
}
int main() {
	scanf("%d %lld", &n, &obj);
	for (int i = 0; i < n; i++) {
		long long val;
		scanf("%lld", &val);
		N[i] = val;
		high = max(high, val);
	}
	sort(N, N + n);
	while (low < high) {
		long long mid = (low+high+1)/2;
		long long val = getVal(mid);
		if (val < obj) high = mid - 1;
		else low = mid;
	}
	printf("%lld", low);
}