#include <stdio.h>
#include <algorithm>

using namespace std;

int crain[51];
int *crain_pointer[51];
int M[10001];

struct Sort {
	inline bool operator()(const int & x, const int &y) {
		return x > y;
	}
};
int main() {
	int n, m;
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &crain[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &M[i]);
	}
	sort(crain, crain + n, Sort());
	sort(M, M + m);
	for (int i = 0; i < n; i++) {
		crain_pointer[i] = upper_bound(M, M + m, crain[i]);
	}
	if (crain_pointer[0] != M + m) {
		printf("-1");
		return 0;
	}
	int i;
	for (i = 0; i < 10000; i++) {
		int check = true;
		for (int j = 0; j < n; j++) {
			int idx = crain_pointer[j] - M - 1;
			while (idx >= 0 && idx < m && M[idx]==-1) {
				idx--;
			}
			if (idx >= 0 && idx < m) {
				M[idx] = -1;
				crain_pointer[j] = M + idx;
				check = false;
			}
		}
		if (check) break;
	}
	printf("%d", i);
}