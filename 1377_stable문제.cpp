#include <stdio.h>
#include <algorithm>
#include <memory.h>
struct map {
	int val;
	int idx;
};
using namespace std;
map m[500001];
// stable sort를 사용하여야만 한다.
int main() {
	int N;
	scanf("%d", &N);
	for(int i=0;i<N;i++){
		scanf("%d", &m[i].val);
		m[i].idx = i;
	}
	stable_sort(m, m + N, [](map a, map b) {return a.val < b.val; });
	int max_val = 0;
	for (int i = 0; i < N; i++) {
		max_val = max(max_val, m[i].idx - i);
	}
	printf("%d", max_val + 1);
}