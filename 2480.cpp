#include <stdio.h>

#define MAX(a,b) ((a)>(b)?(a):(b))
int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if (a == b && b == c) {
		printf("%d\n", a * 1000 + 10000);
	}
	else if( a==b || a==c|| b==c) {
		if (a == b || a==c) {
			printf("%d\n", a*100+1000);
		}
		else {
			printf("%d\n", c * 100 + 1000);
		}
	}
	else {
		int max = MAX(a, b);
		max = MAX(max, c);

		printf("%d\n", max * 100);
	}
}