#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;
long long nCount = 0;
int n[10000001];
int main() {
	long long a, b;
	scanf("%lld %lld", &a, &b);
	vector < pair<long long, long long>> v;
	long long lastB = (long long)sqrt(b);
	for (long long i = 2; i <= lastB; i++) {
		if (n[i]>0) {
			continue;
		}
		for (long long k = i*i; k <= b; k *= i) {
			if (k >= a ) {
				nCount++;
			}
			
			if (9223372036854775807/i < k) break;
		}
		for (long long j = i; j < 10000011; j+=i) {
			n[j] = 1;
		}
	}
	printf("%lld", nCount);
	//4 9 25 49  10^14
}