#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

struct Point {
	long long x, y;
};
Point p[500001];

long long getDistance(Point p1, Point p2) {
	return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}
vector<Point> getCand(int left, int right, int mid, int min) {
	vector<Point> l;
	Point* lb = lower_bound(p + left, p + right + 1, p[mid].x-ceil(sqrt(min)), [&](Point& a, const int b) {return a.x < b; });
	Point* ub = upper_bound(p + left, p + right + 1, p[mid].x+ceil(sqrt(min)), [&](const int a, Point& b) {return a < b.x; });
	l.assign(lb, ub);
	return l;
}
long long getSmall(int left, int right) {
	long long min_val = 9999987654321;
	for (int i = left; i <= right; i++) {
		for (int j = i+1; j <= right; j++) {
			min_val = min(min_val,getDistance(p[i], p[j]));
		}
	}
	return min_val;
}
long long dnq(int left, int right) {
	if (right - left + 1 <= 3) {
		return getSmall(left, right);
	}
	int mid = (left + right) / 2;
	long long ret = min(dnq(left, mid), dnq(mid+1, right));
	vector<Point> v = getCand(left, right, mid, ret);
	sort(v.begin(), v.end(), [](Point a, Point b) {return a.y < b.y; });
	int idx_size = v.size();
	for (int i = 0; i<idx_size; i++) {
		for (int j = i+1; j<idx_size && j<=i+7; j++) {
			ret = min(ret, getDistance(v[i], v[j]));
		}
	}
	return ret;
}
int main() {
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &p[i].y, &p[i].x);
	}
	sort(p, p + n, [](Point a, Point b) {return a.x < b.x; });
	printf("%lld", dnq(0, n-1));
}