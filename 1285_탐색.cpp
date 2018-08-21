#include <stdio.h>
#include <memory.h>
using namespace std;
int coin[21];

int n; char c;
void setCoin(int y, int x) {
	coin[y] |= (1 << x);
}
int MIN(int a, int b) {
	return a < b ? a : b;
}
int changeY(int y) {
	return ~coin[y];
}
int numMinTail(int currentCoin[21]) {
	int num[21] = { 0, };
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (currentCoin[i] & (1 << j)) {
				num[j]++;
			}
		}
	}
	int sum = 0;
	for (int j = 1; j <= n; j++) {
		sum += MIN(num[j], n - num[j]);
	}
	return sum;
}
int checkvalue;
int algo(int current, int* mCoin) {
	int minVal = 987654321;
	current++;
	if (current > n) {
		return numMinTail(mCoin);
	}
	if (mCoin[current] != checkvalue)
	{
		minVal = algo(current, mCoin);
		mCoin[current] = changeY(current);
		minVal = MIN(algo(current, mCoin), minVal);
	}
	else {
		mCoin[current] = 0;
		minVal = MIN(algo(current, mCoin), minVal);
	}
	return minVal;
}
int main() {
	scanf("%d%c", &n, &c);
	for (int i = 1; i <= n; i++) {
		checkvalue |= (1 << i);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%c", &c);
			if (c == 'H')
				setCoin(i, j);
		}
		scanf("%c", &c);
	}
	printf("%d", algo(0, coin));
}

