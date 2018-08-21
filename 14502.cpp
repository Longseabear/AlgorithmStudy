#include <stdio.h>
#include <vector>
#include <memory.h>
#include <queue>
#include <algorithm>
using namespace std;

const int max_step = 3;
int map[10][10];
int dp[10][10];

vector<pair<int, int>> v;
vector<pair<int, int>> b;
int candidate_num = 0;

int dx[4] = { 0, 0 ,1,-1 };
int dy[4] = { 1, -1, 0, 0 };

int n, m;

int get_algo(int step, int cur, int cur_map[4]) {
	int sum = 0;
	if (step == max_step) {
		memcpy(dp, map, sizeof(int) * 10 * 10);
		queue <pair<int, int>> q;
		int b_size = b.size();
		for (int i = 0; i < 3; i++) {
			dp[v[cur_map[i]].first][v[cur_map[i]].second] = 1;
		}
		for (int i = 0; i < b_size; i++) {
			q.push(b[i]);
		}
		while (!q.empty()) {
			auto cur = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int next_x = cur.second + dx[i];
				int next_y = cur.first + dy[i];
				if (dp[next_y][next_x] == 0) {
					q.push(pair<int, int>(next_y, next_x));
					dp[next_y][next_x] = 2;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (dp[i][j] == 0) sum += 1;
			}
		}
		return sum;
	}
	else {
		for (int i = cur+1; i < candidate_num; i++) {
			cur_map[step] = i;
			sum = max(get_algo(step + 1, i, cur_map), sum);
		}
	}
	return sum;
}
int main() {
	scanf("%d %d", &n, &m);
	memset(map, -1, sizeof(int) * 10 * 10);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) v.push_back(pair<int, int>(i, j));
			else if (map[i][j] == 2) b.push_back(pair<int, int>(i, j));
		}
	}
	candidate_num = v.size();
	int map[4] = {-1,-1,-1,-1};
	printf("%d", get_algo(0,-1,map));
}