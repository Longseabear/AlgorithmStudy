#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
int max_day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int max_day_sum[13] = {};
typedef struct flower{
	int start;
	int end;
	int in(int i) {
		if (start <= i && i < end) {
			return 1;
		}
		return 0;
	}
}Flower;
Flower f[100001];
struct compare_flower {
	bool operator()(const Flower f1, const Flower f2) const {
		if (f1.start < f2.start) {
			return true;
		}
		else {
			return false;
		}
	}
};
int main() {
	// 1岿 31老 -> 31老
	// 2岿 1老 -> 32老
	// 2岿 2老 -> 33老
	// 2岿 28老 -> 59老
	// 3岿 1老 -> 60老
	// 4岿 1老 -> 91老
	for (int i = 2; i < 13; i++) {
		max_day_sum[i] = max_day[i-1] + max_day_sum[i-1];
	}
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int mon, day;
		scanf("%d %d", &mon, &day);
		f[i].start = max_day_sum[mon] + day;
		scanf("%d %d", &mon, &day);
		f[i].end = max_day_sum[mon] + day;
	}
	sort(f, f + n, compare_flower());
	int start_day = max_day_sum[3] + 1;
	int end_day = max_day_sum[11] + 30;
	int index = 0;
	int count = 0;
	while (index < n) {
		vector<int> v;
		while (index < n && f[index].start <= start_day) {
			if (f[index].in(start_day)) {
				v.push_back(index);
			}
			index += 1;
		}
		if (v.size() == 0) {
			printf("0\n");
			return 0;
		}
		int max_index;
		int max = -1;
		for (int idx : v) {
			if (max < f[idx].end) {
				max = f[idx].end;
				max_index = idx;
			}
		}
		count++;
		if (max > end_day) {
			printf("%d\n", count);
			return 0;
		}
		start_day = max;
	}	
	printf("0\n");
	return 0;
}