#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int list[300001];
pair<int, int> X[300001];
int idx_list[300008];
int color_start_idx[300008];
int main() {
	int n, c;
	scanf("%d %d", &n, &c);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &list[i]);
		X[i] = { list[i], i };
	}
	stable_sort(X + 1, X + 1 + n);
	for (int i = 1, l=0; i <= n; i++) {
		idx_list[i] = X[i].second;
		while (X[i].first > l) color_start_idx[++l] = i;
	}
	color_start_idx[c + 1] = n + 1;
	int q;
	scanf("%d", &q);
	while (q--) {
		int s, e;
		scanf("%d %d", &s, &e);
		bool check = false;
		for (int choice = 0; choice < 72; choice++) {
			int choice_idx = rand() % (e - s + 1) + s;
			int choice_color = list[choice_idx];
			const int ret = upper_bound(idx_list + color_start_idx[choice_color],
				idx_list + color_start_idx[choice_color + 1], e)-
				lower_bound(idx_list + color_start_idx[choice_color],
					idx_list + color_start_idx[choice_color + 1], s);
			if (ret * 2 > e - s + 1) {
				check = true;
				printf("yes %d\n", choice_color);
				break;
			}
		}
		if (!check) printf("no\n");
	}
}