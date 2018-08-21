#include <stdio.h>
#include <vector>
using namespace std;

vector<int> load;
int main() {
	int n, b, w;
	char c;

	scanf("%d %d %d%c", &n, &b, &w, &c);
	//B의 모든 인덱스를 가지고 있따
	//2 3 6 9 여기서 가장 큰 차이, 소팅되어 있으므로 상관 읍음 0에는 b가 있다고 가정, 끝에도 b가 있다고 가정.
	
	load.push_back(0);
	for (int i = 1; i <= n; i++) {
		scanf("%c", &c);
		if (c == 'B') {
			load.push_back(i);
		}
	}
	load.push_back(n + 1);

	int load_size = load.size();
	int max = 0;
	for (int i = 0; i < load_size; i++) {
		if (i - b-1 < 0) {
			continue;
		}
		int val = load[i] - load[i - b-1] - 1;
		if (val > max) {
			max = val;
		}
	}
	if (max-b >= w) {
		printf("%d\n", max);
	}
	else {
		printf("0\n");
	}
}