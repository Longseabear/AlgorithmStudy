#include <stdio.h>

typedef struct Point {
	double x;
	double y;
}Point;

Point p[3];

double getGradient(Point a, Point b) {

}
int main() {
	for (int i = 0; i < 3; i++) {
		scanf("%lf %lf", &p[i].x, &p[i].y);
	}
}