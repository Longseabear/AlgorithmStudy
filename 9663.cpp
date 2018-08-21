#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

int n;

//step -> low // value -> col
vector<int> getCandidate(int step, int cur[16]) {
	vector<int> candy;
	for (int j = 0; j < n; j++) { // j is candi coloum
		int check = true;
		for (int i = 0; i < step; i++) {
			if (cur[i] == j || abs(cur[i] - j) == abs(i - step)) {
				check = false;
				break;
			}
		}
		if (check) candy.push_back(j);
	}
	return candy;
}
int backgtraking(int step, int cur[16]) {
	if (step == n) {
		return 1;
	}
	int sum = 0;
	vector<int> candi = getCandidate(step, cur);
	for (int idx : candi) {
		cur[step] = idx;
		sum += backgtraking(step + 1, cur);
	}
	return sum;
}
int main() {
	int cur[16];
	scanf("%d", &n);
	printf("%d", backgtraking(0, cur));
}