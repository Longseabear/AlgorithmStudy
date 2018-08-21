#include <stdio.h>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;
vector<vector<int>> node(51);
int esto[2001] = { 1,1,0,0 };

int visit_A[51];
int linked_B[51];
// 0인게 소수
void get_esto() {
	for (int i = 2; i <= 2001; i++) {
		for (int j = i*2; j <= 2001; j+=i) {
			esto[j] = 1;
		}
	}
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
vector<int> even;
vector<int> odd;
int main() {
	int n,val, first_val = 0;
	get_esto();
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &val);
		if (first_val == 0) first_val = val;
		if (val % 2 == first_val % 2)
			odd.push_back(val);
		else
			even.push_back(val);
	}
	if (odd.size() != even.size()) {
		printf("-1\n");
		return 0;
	}
	int data_num = odd.size();
	for (int i = 0; i < data_num; i++) {
		for (int j = 0; j < data_num; j++) {
			if (!esto[odd[i] + even[j]]) node[i+1].push_back(j+1);
		}
	}

	vector<int> res;
	for (int i : node[1]) {
		memset(linked_B, 0, sizeof(int) * 51);
		linked_B[i] = 1;
		int count = 0;
		for (int j = 2; j <= data_num; j++) {
			memset(visit_A, 0, sizeof(int) * 51);
			visit_A[1] = 1;
			if (dfs(j)) count++;
		}
		if (count == (n / 2) - 1)  res.push_back(i);
	}
	sort(res.begin(), res.end(), [](int a, int b) {return even[a - 1] < even[b - 1]; });
	if (res.size() == 0) printf("-1");
	for (int v : res) {
		printf("%d ", even[v - 1]);
	}
	printf("\n");
}