#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;
int speicial[26];
vector<vector<char>> v(1001);
int main() {
	char c[1001];
	scanf("%s", c);
	int len = strlen(c);
	int state = 0;
	int wordIndex = 0;
	// state 1 �빮�� �ѹ� ����.
	// state 2 ��Ģ 2 ����
	for (int i = 0; i < len; i++) {
		if (c[i] < 'a') {
			// �빮��
			if (state == 0) {
				state = 1;
				v[wordIndex].push_back(c[i]);
			}
			else if(state==1){
				wordIndex++;
				v[wordIndex].push_back(c[i]);
			}
			else if(state==2) {
				v[wordIndex].push_back(c[i]);
			}
		}
		else {
			if (state == 0||state==1) {
				if (speicial[c[i] - 'a']) { printf("invalid\n"); return 0; }
				speicial[c[i]-'a'] = 1;
				state = 2;
			}
		}
	}
}