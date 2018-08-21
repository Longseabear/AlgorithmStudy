#include <stdio.h>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
int friendship[5600][5600];
int friendNum[5600];
//2 5 8 11 14 17 20 3n+2
int K, N, F;
vector<int> getCandidate(int step, int cur, int map[64]) {
	vector<int> candidate_vector;
	for (int i = cur + 1; i <= N; i++) {
		if (!friendship[cur][i] || friendNum[i] + 1 < K) continue;
		bool check = true;
		for (int j = 0; j < step; j++) {
			if (!friendship[map[j]][i]) {
				check = false;
				break;
			}
		}
		if (check) candidate_vector.push_back(i);
	}
	return candidate_vector;
}
int backtraking(int step, int cur, int map[64]) {
	if (K==step) {
		for (int i = 0; i < step; i++) {
			printf("%d\n", map[i]);
		}
		return 1;
	}
	else {
		vector<int> candi = getCandidate(step, cur, map);
		for (int candi_idx : candi) {
			map[step] = candi_idx;
			if (backtraking(step+1, candi_idx, map)) {
				return 1;
			}
		}
	}
	return 0;
}
int main() {
	scanf("%d %d %d", &K, &N, &F);
	for (int i = 0; i < F; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		friendship[a][b] = 1;
		friendship[b][a] = 1;
		friendNum[a]++;
		friendNum[b]++;
	}
	
	for (int i = 1; i <= N; i++) {
		if (friendNum[i] + 1 < K) continue;
		int m[64] = {0};

		m[0] = i;
		if (backtraking(1, i, m)) {
			return 0;
		}
	}
	printf("-1");
}