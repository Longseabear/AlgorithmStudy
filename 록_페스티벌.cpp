#include <stdio.h>

double min = 9999999999;
double N[1001];
double MIN(double a, double b) {
	return a < b ? a : b;
}
int main() {
	int testCase;
	scanf("%d", &testCase);
	while (testCase--) {
		min = 9999999999;
		int n, l;
		scanf("%d %d", &n, &l);
		for (int i = 1; i <= n; i++) {
			double val;
			scanf("%lf", &val);
			N[i] = N[i - 1] + val;
		}
		for (int i = l; i <= n; i++) {
			double roopMin = 9999999999;
			for (int j = i; j <= n; j++) {
				roopMin = MIN(roopMin, (N[j]-N[j-i])/i);
			}
			min = MIN(min, roopMin);
		}
		printf("%.11lf\n", min);
	}
}