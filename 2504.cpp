#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

char s[31];
int num;
int failed = 0;
int recur(int& pos) {
	char original = s[pos];
	if (s[pos] != '(' && s[pos] != '[') {
		failed = 1;
		pos = num;
		return -1;
	}
	if (pos + 1 >= num) {
		failed = 1;
		pos = num;
		return -1;
	}
	if (s[pos + 1]-s[pos]==2) {
		// []
		pos += 1;
		return 3;
	}
	else if (s[pos + 1] - s[pos] == 1) {

		pos += 1;
		return 2;
	}

	int sum = 0;
	while (pos < num) {
		pos += 1;
		if (s[pos] == '(' || s[pos] =='[') {
			sum+=recur(pos);
		}
		else if (s[pos]-original==1) {
			//()
			return sum *= 2;
		}
		else if(s[pos]-original==2) {
			return sum *= 3;
		}
		else {
			failed = 1;
			pos = num;
			return -1;

		}
	}
	failed = 1;
	pos = num;
	return -1;
}
int main() {
	scanf("%s", s);
	num = strlen(s);
	stack<char> q;
	int res = 0;
	int index = 0;
	while (index < num) {
		res += recur(index);
		index += 1;
	}
	if (failed) {
		printf("0\n");
	}
	else {
		printf("%d", res);
	}
}