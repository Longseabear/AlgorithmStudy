#include <stdio.h>
#include <vector>
using namespace std;

vector<int> load;
int main() {
	int n, b, w;
	char c;

	scanf("%d %d %d%c", &n, &b, &w, &c);
	//B�� ��� �ε����� ������ �ֵ�
	//2 3 6 9 ���⼭ ���� ū ����, ���õǾ� �����Ƿ� ��� ���� 0���� b�� �ִٰ� ����, ������ b�� �ִٰ� ����.
	
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