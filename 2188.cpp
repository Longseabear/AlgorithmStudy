#include <stdio.h>
#include <memory.h>
#include <vector>

using namespace std;

vector<vector<int>> node(1001);
int visit_A[1001];
int linked_B[1001];
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
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int room_num;
		scanf("%d", &room_num);
		while (room_num--) {
			int room;
			scanf("%d", &room);
			node[i].push_back(room);
		}
	}
	int count = 0;
	for (int i = 1; i <= n; i++) {
		memset(visit_A, 0, sizeof(int) * 1001);
		if (dfs(i)) count++;
		memset(visit_A, 0, sizeof(int) * 1001);
		if (dfs(i)) count++;
	}
	printf("%d", count);
}