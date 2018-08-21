#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
	int testCase;
	int A[9] = {0,1, 3, 6, 10, 15, 21,0,0};
	int B[8] = {0,1, 3, 7, 15, 31,0,0 };
	int Ascore[9] = {0, 500,300,200,50,30,10,0,0 };
	int Bscore[8] = { 0, 512, 256,128,64,32,0,0 };

	scanf("%d", &testCase);
	while (testCase--) {
		int a, b;
		scanf("%d %d", &a, &b);
		int a_idx = lower_bound(A, A +8, a) - A;
		int b_idx = lower_bound(B, B +7, b) - B;
		printf("%d\n", (Ascore[a_idx] + Bscore[b_idx])*10000);
	}
}