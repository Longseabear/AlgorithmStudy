#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <memory.h>
#define POW2(x) ((x)*(x))
using namespace std;
pair<double, double> mouse[101];
int visit_A[101];
int linked_B[101];
vector<vector<int>> map(101);
int dfs(int cur_a) {
	if (visit_A[cur_a]) return 0;
	visit_A[cur_a] = 1;

	for (int i : map[cur_a]) {
		if (!linked_B[i] || dfs(linked_B[i])) {
			linked_B[i] = cur_a;
			return 1;
		}
	}
	return 0;
}
double l2_norm(pair<double ,double> m, pair<double, double> s) {
	return sqrt(POW2(m.first - s.first) + POW2(m.second - s.second));
}
int main() {
	int N, M;
	double S, V;
	scanf("%d %d %lf %lf", &N, &M, &S, &V);
	for (int i = 1; i <= N; i++) {
		scanf("%lf %lf", &mouse[i].first, &mouse[i].second);
	}
	for (int i = 1; i <= M; i++) {
		double sX, sY;
		scanf("%lf %lf", &sY, &sX);
		for (int j = 1; j <= N; j++) {
			double dist = l2_norm(mouse[j], pair<double, double>(sY, sX));
			if (dist / V <= S) map[j].push_back(i);
		}

	}
	int hide_num = 0;
	for (int i = 1; i <= N; i++) {
		memset(visit_A, 0, sizeof(int) * 101);
		if (dfs(i)) hide_num++;
	}
	printf("%d", N - hide_num);
}