#include <stdio.h>
#include <vector>
#include <memory.h>
using namespace std;

int visit_A[1001];
int linked_B[1001];
vector<vector<int>> node(1001);
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
		int work_num;
		scanf("%d", &work_num);
		while (work_num--) {
			int work;
			scanf("%d", &work);
			node[i].push_back(work);
		}
	}

	int count = 0;
	for (int i = 1; i <= n; i++) {
		memset(visit_A, 0, sizeof(int) * 1001);
		if (dfs(i)) count++;
	}
	printf("%d", count);
}