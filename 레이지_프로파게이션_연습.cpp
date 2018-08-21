#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <algorithm>

using namespace std;

long long* tree;
long long* lazy;

void prop(int cur, int left, int right) {
	tree[cur] += lazy[cur] * (right - left + 1);
	if (left != right) {
		lazy[cur * 2 + 1] += lazy[cur];
		lazy[cur * 2 + 2] += lazy[cur];
	}
	lazy[cur] = 0;
}
long long seg_get(int cur, int obj_left, int obj_right, int left, int right) {
	if (lazy[cur] != 0) prop(cur, left, right);
	if (obj_left > right || obj_right < left) return 0;

	if (obj_left <= left && right <= obj_right) return tree[cur];

	int mid = (left + right) / 2;
	return seg_get(cur * 2 + 1, obj_left, obj_right, left, mid) +
		seg_get(cur * 2 + 2, obj_left, obj_right, mid + 1, right);
}
void update(int cur, int obj_left, int obj_right, int left, int right, long long val) {
	if (lazy[cur] != 0) prop(cur, left, right);
	if (obj_right < left || right < obj_left) return;

	if (obj_left <= left && right <= obj_right) {
		tree[cur] += val * (right - left + 1);
		if (right != left) {
			lazy[cur * 2 + 1] += val;
			lazy[cur * 2 + 2] += val;
		}
		return;
	}

	int mid = (left + right) / 2;
	update(cur * 2 + 1, obj_left, obj_right, left, mid, val);
	update(cur * 2 + 2, obj_left, obj_right, mid+1, right, val);
	tree[cur] = tree[cur * 2 + 1] + tree[cur * 2 + 2];
}
int main() {
	int n, q1, q2;
	scanf("%d %d %d", &n, &q1, &q2);
	int h = ceil(log2(n));
	int tree_size = (1 << (h + 1));

	tree = new long long[tree_size];
	lazy = new long long[tree_size];

	memset(tree, 0, sizeof(long long)*(tree_size));
	memset(lazy, 0, sizeof(long long)*(tree_size));

	for (int j = 0; j < n; j++) {
		int val;
		scanf("%d", &val);
		update(0, j, j, 0, n - 1, val);
	}
	for (int i = 1; i <= q1 + q2; i++) {
		int op;
		scanf("%d", &op);
		if (op == 2) {
			int a, b;
			scanf("%d %d", &a, &b);
			printf("%lld\n", seg_get(0, a - 1, b - 1, 0, n - 1));
		}
		else {
			int s, e;
			long long l;
			scanf("%d %d %lld", &s, &e, &l);
			update(0, s - 1, e - 1, 0, n - 1, l);
		}
	}
}