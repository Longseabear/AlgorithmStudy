#include <stdio.h>
#include <math.h>

int main() {
	double n, l;
	scanf("%lf %lf", &n, &l);
	for (double i = l - 1; i <= 99; i++) {
		double val = (2 * n - i*i - i) / (2 * i + 2);
		if (val < 0) continue;
		if (ceill(val) == floorl(val)) {
			int k = val;
			for (int j = k; j <= i + k; j++) {
				printf("%d ", j);
			}
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}