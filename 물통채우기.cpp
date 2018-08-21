#include <stdio.h>
#include <queue>

using namespace std;

typedef struct waterState {
	int A;
	int B;
	int step;
	waterState(int a, int b, int _step):A(a), B(b), step(_step) {
	}
}WaterState;

int main() {
	int a, b, resA, resB;
	printf("%d", 7 % 8);
	exit(1);
	scanf("%d %d %d %d", &a, &b, &resA, &resB);

	queue<WaterState> q;
	q.push(WaterState(0, 0, 0));
	while (!q.empty()) {
		WaterState ws = q.front();
		q.pop();
	}
}