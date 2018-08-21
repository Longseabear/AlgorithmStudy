#include <stdio.h>
#include <vector>
#include <memory.h>

using namespace std;

int visit_A[51];
int linked_B[51];

struct status {
	int x;
	int y;
	int z;
};
vector<vector<int>> node(51);
status shark[51];

int compare_shark(int idx1, int idx2) {
	if (shark[idx1].x == shark[idx2].x &&
		shark[idx1].y == shark[idx2].y &&
		shark[idx1].z == shark[idx2].z) return 2;
	if (shark[idx1].x >= shark[idx2].x &&
		shark[idx1].y >= shark[idx2].y &&
		shark[idx1].z >= shark[idx2].z) return -1;
	if (shark[idx1].x <= shark[idx2].x &&
		shark[idx1].y <= shark[idx2].y &&
		shark[idx1].z <= shark[idx2].z) return 1;
	return 0;
}
int dfs(int cur_a) {
	if (visit_A[cur_a]) return 0;
	visit_A[cur_a] = 1;
	for (int obj_b : node[cur_a]) {
		if (!linked_B[obj_b] || dfs(linked_B[obj_b])) {
			linked_B[obj_b] = cur_a;
			return 1;
		}
	}
	return 0;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &shark[i].x, &shark[i].y, &shark[i].z);
		for (int j = 1; j < i; j++) {
			int strong_shark = compare_shark(i, j);
			if (strong_shark == 1) node[j].push_back(i);
			else if (strong_shark == -1) node[i].push_back(j);
			else if (strong_shark == 2) node[i].push_back(j);
		}
	}

	int count = 0;
	for (int i = 0; i < n*2; i++) {
		memset(visit_A, 0, sizeof(int) * 51);
		if (dfs(i/2+1)) count++;
	}
	printf("%d", n - count);
}