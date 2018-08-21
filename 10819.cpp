#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
int n;
int N[8];
int getResult(vector<int> k) {
	int sum = 0;
	for (int i = 0; i < n-1; i++) {
		sum += abs(N[k[i]] - N[k[i+1]]);
	}
	return sum;
}
int containK(vector<int> k, int val) {
	for (int a : k) {
		if (a == val) return true;
	}
	return false;
}
int MAX(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}
int getNPermu(int step, vector<int> k) {
	int max = 0;
	if (step == n) return getResult(k);
	else {
		for (int i = 0; i < n; i++) {
			if (!containK(k, i)) {
				vector<int> nextV = k;
				nextV.push_back(i);
				max = MAX(max,getNPermu(step+1, nextV));
			}
		}
	}
	return max;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &N[i]);
	vector<int> k;
	printf("%d", getNPermu(0, k));
}