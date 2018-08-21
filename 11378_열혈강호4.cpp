#include <stdio.h>
#include <vector>
#include <memory.h>

using namespace std;
const int MAX_NUM = 1001;
int visit_A[MAX_NUM];
int linked_B[MAX_NUM];
vector<vector<int>> node(MAX_NUM);

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
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
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
		memset(visit_A, 0, sizeof(int) * MAX_NUM);
		if (dfs(i)) count++;
	}
	while (k>0) {
		bool changed = false;
		for (int i = 1; i <= n && k>0; i++) {
			memset(visit_A, 0, sizeof(int) * MAX_NUM);
			if (dfs(i)) {
				count++;
				k--;
				changed = true;
			}
		}
		if (!changed) break;
	}
	printf("%d", count);
}