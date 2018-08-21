#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
typedef struct Node {
	Node(int s, int c):step(s), state(c) {
	}
	int step;
	int state;
	
}Node;
using namespace std;
int current[9];
char dp[362880];
int obj = 46233;
int factorial[10] = { 1, 1, 2, 6, 24, 120, 720, 7*720, 8*7*720, 9*8*7*720 };
int dx[4] = {1 ,-1,0,0};
int dy[4] = { 0 ,0,1,-1 };
int array2num(int arr[9]) {
	int n = 9;
	int m = 0;
	for (int i = 0; i < n; i++) {
		int k = 0;
		for (int j = i + 1; j < n; j++) if (arr[i] > arr[j]) k++;
		m += k*factorial[n - i - 1];
	}
	return m;
}
int vector2num(vector<int> arr) {
	int n = 9;
	int m = 0;
	for (int i = 0; i < n; i++) {
		int k = 0;
		for (int j = i + 1; j < n; j++) if (arr[i] > arr[j]) k++;
		m += k * factorial[n - i - 1];
	}
	return m;
}
vector<int> num2Array(int m) {
	int n = 9;
	int i,j;
	vector<int> a(10);
	for (i = n - 1; i >= 0; i--)
	{
		a[i] = m % (n - i);
		m /= n - i;
		for (j = i + 1; j < n; j++) if (a[j] >= a[i]) a[j]++;
	}
	return a;
}
void check(Node n) {
	if (n.state == obj) {
		printf("%d", n.step);
		exit(0);
	}
}
vector<int> candidate(vector<int> currentState) {
	vector<int> c;
	int zeroPos;
	for (int i = 0; i < 9; i++) {
		if (currentState[i] == 0) {
			zeroPos = i;
			break;
		}
	}
	int x = zeroPos % 3;
	int y = zeroPos / 3;

	for (int i = 0; i < 4; i++) {
		if (x + dx[i] >= 0 && x + dx[i] <= 2 && y + dy[i] >= 0 && y + dy[i] <= 2) {
			int temp = currentState[zeroPos];
			currentState[zeroPos] = currentState[(y + dy[i]) * 3 + x + dx[i]];
			currentState[(y + dy[i]) * 3 + x + dx[i]] = temp;
			int nextState = vector2num(currentState);
			if (dp[nextState] != 1) {
				c.push_back(nextState);
				dp[nextState] = 1;
			}
			temp = currentState[zeroPos];
			currentState[zeroPos] = currentState[(y + dy[i]) * 3 + x + dx[i]];
			currentState[(y + dy[i]) * 3 + x + dx[i]] = temp;
		}
	}
	return c;
}
int main() {
	for (int i = 0; i < 9; i++) {
		scanf("%d", &current[i]);
	}
	queue<Node> q;
	Node n = Node(0, array2num(current));
	check(n);
	dp[n.state] = 1;
	q.push(n);
	while (!q.empty()) {
		Node c = q.front();
		q.pop();
		
		vector<int> cv = candidate(num2Array(c.state));
		int candidateNum = cv.size();
		for (int i = 0; i < candidateNum; i++) {
			Node next = Node(c.step + 1, cv[i]);
			check(next);
			q.push(next);
		}
	}
	printf("0\n");
}