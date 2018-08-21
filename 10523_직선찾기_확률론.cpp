#include <stdio.h>
#include <math.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const double inf = 99999987654321;
vector<int> v;
struct Point {
	int x, y;
};
Point P[100001];
double getGrad(Point p1, Point p2) {
	if (p1.x - p2.x == 0) return inf;
	return ((double)p1.y - (double)p2.y) / ((double)p1.x - (double)p2.x);
}
int main() {
	int n, p;
	int max_val = 0;

	map<double, int> test;
	
	scanf("%d %d", &n, &p);
	for (int i = 0; i < n; i++) scanf("%d %d", &P[i].y, &P[i].x);
	bool check = false;
	for (int i = 0; i < 72; i++) {
		map<double, int> m;

		int idx = rand() % n;
		Point pivot = P[idx];
		for (int j = 0; j < n; j++) {
			if (idx==j) continue;
			double grad = getGrad(pivot, P[j]);
			double alpha = pivot.y - pivot.x*grad;
			m[grad] = m[grad] + 1;
		}
		for (auto i = m.begin(); i != m.end(); ++i) {
			max_val = max(max_val, i->second);
		}
	}
	if ((double)max_val+1 >= 0.01*n*p) {
		printf("possible");
	}
	else {
		printf("impossible");
	}
}