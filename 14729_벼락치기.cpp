#include <stdio.h>
#include <algorithm>

using namespace std;
typedef struct Node {
	int time;
	int score;
}Node;

Node N[101];
int dp[101][10001];
struct time_score_sort {
	inline bool operator()(const Node& x, const Node& y) const{
		if (x.time == y.time) {
			return x.score > y.score;
		}
		else {
			return x.time > y.time;
		}
	}
};
int main() {
	int n, t;
	scanf("%d %d", &n, &t);
	
	for (int i = 0; i < n; i++) scanf("%d %d", &N[i + 1].time, &N[i + 1].score);
	sort(N + 1, N + n+1, time_score_sort());
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= t; x++) {
			if (N[y].time <= x) {
				dp[y][x] = max(dp[y-1][x - N[y].time] + N[y].score, dp[y-1][x]);
			}
			else {
				dp[y][x] = dp[y - 1][x];
			}
		}
	}
	int max_val = 0;
	for (int i = 1; i <= t; i++) {
		max_val = max(dp[n][i], max_val);
	}
	printf("%d", max_val);
}