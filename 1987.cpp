#include <stdio.h>
#include <vector>
#include <algorithm>
#include <memory.h>

//MEM COPY 애용하자
//BACKTRACKING에서 최대한 for문의 수를 줄이자.
//MEMCOPY 짱짱맨

using namespace std;

int max_res;

char map[21][21];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int MAX(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}
int mapX, mapY;

void getCandidate(int y, int x, char currentState[26], int step,vector<pair<int, int>>& candidate) {
	for (int i = 0; i<4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		
		if (nx >= 0 && nx < mapX && ny >= 0 && ny < mapY) {
			char nextAlphanet = map[ny][nx];
			int flag = 1;
			for (int i = 0; i < step; i++) {
				if (currentState[nextAlphanet-'A']) {
					flag = 0;
					break;
				}
			}
			if (flag) {
				candidate.push_back(pair<int,int>(ny, nx));
			}
		}
	}
}
int backTracking(int i, int j, char currentState[26], int step) {
	char check[26] = { 0 };
	step++;
	memcpy(check, currentState, sizeof(char) * 26);
	check[map[i][j] - 'A'] = 1;

	int resStep = step;
	if (step==26) {
		return step;
	}
	else {
		vector<pair<int, int>> candidate;
		getCandidate(i,j,check,step,candidate);

		for (pair<int, int> n : candidate) {
			resStep = MAX(resStep,backTracking(n.first, n.second, check, step));
		}
	}
	return resStep;
}
int main() {
	char c;
	char state[26] = {};
	scanf("%d %d%c", &mapY, &mapX, &c);
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			scanf("%c", &map[i][j]);
		}
		scanf("%c", &c);
	}
	printf("%d\n",backTracking(0, 0, state, 0));
}