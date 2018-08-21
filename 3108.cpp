#include <stdio.h>
#include <math.h>
#include <queue>
typedef struct square {
	int x1; int x2;
	int y1; int y2;

	double midX, midY;
}Square;

using namespace std;

double disparity(double x, double x2) {
	return fabs(x - x2);
}
int check(Square s1, Square s2) {
	if (disparity(s1.midX, s2.midX) <= (disparity(s1.x1, s1.x2)+disparity(s2.x1,s2.x2)) / 2.0) {
		if (disparity(s1.midY, s2.midY) <= (disparity(s1.y1, s1.y2) + disparity(s2.y1, s2.y2)) / 2.0) {
			if(!(s1.x1 < s2.x1 && s1.y1 < s2.y1 && s1.y2 > s2.y2 && s1.x2 > s2.x2) &&
				!(s1.x1 > s2.x1 && s1.y1 > s2.y1 && s1.y2 < s2.y2 && s1.x2 < s2.x2))
				return 1;
		}
	}
	return 0;
}
Square s[1001];
int memo[1001];
int main() {
	int n;
	int count = 0, flag = 0;
	scanf("%d", &n);
	Square start;
	start.x1 = 0;
	start.x2 = 0;
	start.y1 = 0;
	start.y2 = 0;
	start.midX = 0;
	start.midY = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &s[i].x1, &s[i].y1, &s[i].x2, &s[i].y2);
		s[i].midX = (s[i].x1 + s[i].x2) / 2.0;
		s[i].midY = (s[i].y1 + s[i].y2) / 2.0;
		if (flag == 0) {
			if (check(start, s[i])) {
				flag = 1;
			}
		}
	}
	if (flag) {
		count--;
	}
	for (int i = 0; i < n; i++) {
		if (memo[i] > 0)
			continue;
		count++;
		queue<int> candidate;
		candidate.push(i);
		memo[i] = 1;
		while (!candidate.empty()) {
			int startIndex = candidate.front();
			candidate.pop();
			for (int j = 0; j < n; j++) {
				if (memo[j] > 0) {
					continue;
				}
				if (check(s[startIndex], s[j])) {
					memo[j] = 1;
					candidate.push(j);
				}
			}
		}
	}
	printf("%d", count);
}