#include <stdio.h>
#include <algorithm>
#include <math.h>
#define SQUARE(a) ((a)*(a))
#define MIN(a,b) ((a)>(b)?(b):(a))
using namespace std;

double sum[501];
double map[501];
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%lf", &map[i]);
		
	}
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + map[i];
	}

	double min = 9999992345987654321;
	while (k<=n) {
		for (int i = 1; i <= n - k + 1; i++) {
			double mean_square = 0;
			double mean = (sum[k + i - 1] - sum[i - 1]) / k;
			for (int j = i; j <= k + i - 1; j++) {
				mean_square = mean_square + SQUARE(map[j] - mean);
			}
			mean_square /= k;
			min = MIN(min, mean_square);
		}
		k++;
	}
	printf("%.11lf", sqrt(min));
}