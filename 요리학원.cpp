#include <stdio.h>
#include <iostream>
#include <limits>
#include <math.h>

int memo[3001][3001];
long long cost[3001][3001];
int noAccess[3001];

int n, m, s, e, t;

const long long _INFINITY = std::numeric_limits<long long>::max();

#define MIN(a,b) ((a)<(b)?(a):(b)) 
long long algo(int posY, int posX, long long currentCost, int currentS) {
	// select Pos Y pos X
	if (currentS == 1) {
		while (currentS <= s && posX <= m) {
			currentS++;
			currentCost += cost[posY][posX];
			posX++;
		}
	}
	if (posX > m) {
		return currentCost;
	}

	long long min = _INFINITY;
	for (int i = 1; i <= n; i++) {
		if (i == posX) {
			if (currentS <= e) {
				min = MIN(min,algo(posY, posX, currentCost+cost[posY][posX], currentS + 1));
			}
		}
	}
}
int main() {
	scanf("%d %d %d %d %d", &n, &m, &s, &e, &t);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &cost[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &noAccess[i]);
	}
	long long min = _INFINITY;
	for (int i = 1; i <= n; i++) {
		min = MIN(min, algo(i, 1, 0, 1));
	}
	printf("%lld", min != _INFINITY ? min : -1);
}
