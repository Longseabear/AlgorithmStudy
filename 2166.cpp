#include <stdio.h>
#include <vector>

using namespace std;
char map[27][27];
void makeMap(char i, char j, char val) {
	map[i - 'A'][j - 'A'] = val;
	map[j - 'A'][i - 'A'] = val;
}
int main() {
	char str[1000001];
	int n;
	scanf("%d", &n);
	scanf("%s", str);

	makeMap('A', 'A', 'A');
	makeMap('A', 'G', 'C');
	makeMap('A', 'C', 'A');
	makeMap('A', 'T', 'G');

	makeMap('G', 'G', 'G');
	makeMap('G', 'C', 'T');
	makeMap('G', 'T', 'A');

	makeMap('C', 'C', 'C');
	makeMap('C', 'T', 'G');

	makeMap('T', 'T', 'T');

	for (int i = n - 1; i >= 1; i--) {
		str[i - 1] = map[str[i] - 'A'][str[i - 1] - 'A'];
	}
	printf("%c\n", str[0]);
}