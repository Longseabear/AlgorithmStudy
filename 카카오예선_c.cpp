#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

struct Node {
	int is = 0;
	int firstX, firstY;
	int secondX, secondY;
	int dir_LEFT_RIGHT;
	int dir_TOP_BOTTOM;
};
template <typename T> int sgn(T val) {
	return (T(0) < val) - (val < T(0));
}
char map[102][102];
Node dp[26];
int getAlgo(int pos) {
	Node cur = dp[pos];
	int directionX = sgn(cur.dir_LEFT_RIGHT);
	int directionY = sgn(cur.dir_TOP_BOTTOM);
		for (int i = cur.firstY + directionY; abs(i - cur.firstY) <= 1 + cur.dir_TOP_BOTTOM*directionY; i += directionY) {
			if ((map[i][cur.firstX] != '.' && map[i][cur.firstX] != (char)pos + 'A') || map[i][cur.firstX] == 0) {
				break;
			}
			for (int j = cur.firstX + directionX; abs(j - cur.firstX) <= 1 + cur.dir_LEFT_RIGHT*directionX; j += directionX) {
				if ((map[i][j] != '.' && map[i][j] != (char)pos + 'A') || map[i][j] == 0) {
					break;
				}
				if (directionX == 0) break;
				if (map[i][j] == pos + 'A') return 1;
			}
			if (directionY == 0) break;
		}
		for (int i = cur.firstX + directionX; abs(i - cur.firstX) <= 1 + cur.dir_LEFT_RIGHT*directionX; i += directionX) {
			if ((map[cur.firstY][i] != '.' && map[cur.firstY][i] != (char)pos + 'A') || map[cur.firstY][i] == 0) {
				break;
			}
			for (int j = cur.firstY + directionY; abs(j - cur.firstY) <= 1 + cur.dir_TOP_BOTTOM*directionY; j += directionY) {
				if ((map[j][i] != '.' && map[j][i] != (char)pos + 'A') || map[j][i] == 0) {
					break;
				}
				if (directionY == 0) break;
				if (map[j][i] == pos + 'A') return 1;
			}
			if (directionX == 0) break;
		}
	return 0;
}
int main() {
	int n, m;
	char c;
	scanf("%d %d%c", &n, &m, &c);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%c", &map[i][j]);
			if (map[i][j] == '.' || map[i][j] == '*' || map[i][j] == 0) continue;
			if (dp[map[i][j] - 'A'].firstX == 0) {
				dp[map[i][j] - 'A'].firstX = j;
				dp[map[i][j] - 'A'].firstY = i;
				dp[map[i][j] - 'A'].is = 1;
			}
			else {
				Node& c = dp[map[i][j] - 'A'];
				c.secondX = j;
				c.secondY = i;
				c.dir_LEFT_RIGHT = c.secondX - c.firstX;
				c.dir_TOP_BOTTOM = c.secondY - c.firstY;
			}
		}
		scanf("%c", &c);
	}
	vector<char> res;
	bool change, existIs;
	while (1) {
		change = false;
		existIs = false;
		for (int i = 0; i < 26; i++) {
			if (dp[i].is) {
				existIs = true;
				if (getAlgo(i)) {
					change = true;
					res.push_back(i);
					dp[i].is = 0;
					map[dp[i].firstY][dp[i].firstX] = '.';
					map[dp[i].secondY][dp[i].secondX] = '.';
					break;
				}
			}
		}
		if (change == false) break;
	}
	if (existIs) printf("IMPOSSIBLE");
	else
	for (char c : res) {
		printf("%c", c + 'A');
	}
}