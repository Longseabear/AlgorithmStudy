#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

vector<char*> cond;

int mapping(char c) {
	switch (c)
	{
	case 'A':
		return 0;
	case 'C':
		return 1;
	case 'F':
		return 2;
	case 'J':
		return 3;
	case 'M':
		return 4;
	case 'N':
		return 5;
	case 'R':
		return 6;
	case 'T':
		return 7;
	}
}
vector<int> get_candidate(int cur_bitmask, int map[8], int step) {
	vector<int> candidate;
	for (int i = 0; i < 8; i++) {
		if (cur_bitmask & (1 << i)) continue;

		bool check = true;
		for (char* s : cond) {
			int f1 = mapping(s[0]);
			int f2 = mapping(s[2]);
			char op = s[3];
			int val = s[4] - '0';
			
			if (f1 != i && f2 != i) continue;
			int me = i;
			int other = f1 == i ? f2 : f1;
			if (!(cur_bitmask & (1 << other))) continue;
			
			if (op == '=') {
				if (step - val - 1 < 0 || map[step - val - 1] != other) {
					check = false;
					break;
				}
			}
			else if (op == '>') {
				for(int k=step-1; k>=step-1-val && k>=0; k--){
					if (map[k] == other) {
						check = false;
						break;
					}
				}
			}
			else {
				for (int k = step - 1 - val; k >= 0; k--) {
					if (map[k] == other) {
						check = false;
						break;
					}
				}
			}
			if (!check) break;
		}
		if (check) candidate.push_back(i);
	}
	return candidate;
}
int algo(int step, int cur_bitmask, int map[8]) {
	if (step >= 8) {
		return 1;
	}

	vector<int> candidate = get_candidate(cur_bitmask, map, step);
	int res = 0;
	for (int next : candidate) {
		map[step] = next;
		res += algo(step + 1, cur_bitmask | (1 << next), map);
	}
	return res;
}
char s[102][7];

int main() {
	int n;
	int map[8] = { 0 };
	scanf("%d", &n);
	while (n--) {
		scanf("%s", s[n]);
		cond.push_back(s[n]);
	}
	printf("%d", algo(0, 0, map));
}