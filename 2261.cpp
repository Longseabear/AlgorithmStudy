#include <stdio.h>
#include <algorithm>

using namespace std;
typedef struct POINT {
	long long x;
	long long y;
}Point;

Point p[100011];
Point tmp[100011];
struct baseX {
	bool operator()(Point a, Point b) const {
		return a.x < b.x;
	}
};
struct baseY {
	bool operator()(Point a, Point b) const {
		return a.y < b.y;
	}
};

long long pow(long long x) {
	return x * x;
}
long long distance(Point a, Point b) {
	return pow(a.x - b.x) + pow(a.y - b.y);
}
long long MIN(long long a, long long b) {
	if (a > b)
		return b;
	return a;
}
long long algo(int left, int right) {
	int section_num = right - left;
	int mid = left + (right - left) / 2;
	long long min = 1987654321;
	if (left > right) {
		return min;
	}
	if (section_num <= 3) {
		for (int i = left; i < right; i++) {
			for (int j = left; j < right; j++) {
				if (i == j) continue;
				min = MIN(min, distance(p[i], p[j]));
			}
		}
	}
	else {
		min = algo(left, mid); // left
		min = MIN(min, algo(mid, right)); // right

		long long candidateLeft = p[mid].x - min + 1;
		long long candidateRight = p[mid].x + min - 1;
		Point cLeft, cRight;
		cLeft.x = candidateLeft;
		cRight.x = candidateRight;
		int band_left = lower_bound(p + left, p + mid + 1, cLeft, baseX()) - p;
		int band_last = upper_bound(p + mid, p + right, cRight, baseX()) - p;
		int band_num = band_last - band_left;
		if (band_left < band_last) {
			copy(p + band_left, p + band_last, tmp);
			sort(tmp, tmp + band_num, baseY());
			for (int i = 0; i < band_num; i++) {
				for (int j = 1; j <= 6 && i + j < band_num; j++) {
					min = MIN(min, distance(tmp[i], tmp[i + j]));
				}
			}
		}
	}
	return min;
}
int main() {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &p[i].x, &p[i].y);
	}
	sort(p, p + n, baseX());
	printf("%lld\n", algo(0, n));
}