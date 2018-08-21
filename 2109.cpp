#include <stdio.h>
#include <algorithm>

using namespace std;
struct Node {
	int time;
	int coin;
};
Node N[10001];
int dp[2][10001];
struct less_than{
	inline bool operator()(const Node& x, const Node& y){
		return x.time < y.time;
	}
};
#define MAX(a,b) ((a)>(b)?(a):(b))
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &N[i].coin, &N[i].time);
	}
	// sort d 기준으로 솔팅
	sort(N+1, N + n+1, less_than());
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= N[i].time; j++) {
			dp[i%2][j] = MAX(dp[(i+1)%2][j], dp[(i+1)%2][j - 1] + N[i].coin);
		}
	}
	int max = 0;
	for (int i = 1; i <= 10000; i++) {
		max = MAX(max, dp[(n)%2][i]);
	}
	printf("%d", max);
}