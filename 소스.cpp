#include <stdio.h>
#include <queue>
#include <algorithm>

typedef struct A {
	int x;
	int y;
	int chance;
	int cost;
	A(int _x, int _y, int _chance, int _cost) {
		x = _x;
		y = _y;
		chance = _chance;
		cost = _cost;
	}
	A() {

	}
}Node;
using namespace std;
int map[1002][1002];
int visit[1002][1002][2];

int main() {
	int n, m;
	char c;
	scanf("%d %d", &n, &m);
	scanf("%c", &c);
	for (int i = 0; i != n; i++) {
		for (int j = 0; j != m; j++) {
			scanf("%c", &c);
			map[i + 1][j + 1] = c - '0';
		}
		scanf("%c", &c);
	}
	if (n == 1 && m == 1 && map[1][1] == 0) {
		printf("1\n");
		return 0;
	}

	queue<Node> q;
	q.push(Node(1, 1, 1, 1));
	visit[1][1][0] = visit[1][1][1] = 1;
	while (!q.empty()) {
		Node cur = q.front(); q.pop();
		Node newNode;
		// x-1
		if (cur.x > 1) {
			newNode.x = cur.x - 1;
			newNode.y = cur.y;
			newNode.chance = cur.chance;
			newNode.cost = cur.cost + 1;

			if (map[newNode.y][newNode.x] == 0) {
				if (visit[newNode.y][newNode.x][newNode.chance] == 0) {
					visit[newNode.y][newNode.x][newNode.chance] = newNode.cost;
					if (newNode.x == m && newNode.y == n) {
						printf("%d\n", newNode.cost);
						return 0;
					}
					q.push(Node(newNode.x, newNode.y, newNode.chance, newNode.cost));
				}
			}
			else {
				if (newNode.chance == 1 && visit[newNode.y][newNode.x][0] == 0) {
					visit[newNode.y][newNode.x][0] = newNode.cost;
					if (newNode.x == m && newNode.y == n) {
						printf("%d\n", newNode.cost);
						return 0;
					}
					q.push(Node(newNode.x, newNode.y, 0, newNode.cost));
				}
			}
		}
		if (cur.x < m) {
			newNode.x = cur.x + 1;
			newNode.y = cur.y;
			newNode.chance = cur.chance;
			newNode.cost = cur.cost + 1;

			if (map[newNode.y][newNode.x] == 0) {
				if (visit[newNode.y][newNode.x][newNode.chance] == 0) {
					visit[newNode.y][newNode.x][newNode.chance] = newNode.cost;
					if (newNode.x == m && newNode.y == n) {
						printf("%d\n", newNode.cost);
						return 0;
					}
					q.push(Node(newNode.x, newNode.y, newNode.chance, newNode.cost));
				}
			}
			else {
				if (newNode.chance == 1 && visit[newNode.y][newNode.x][0] == 0) {
					visit[newNode.y][newNode.x][0] = newNode.cost;
					if (newNode.x == m && newNode.y == n) {
						printf("%d\n", newNode.cost);
						return 0;
					}
					q.push(Node(newNode.x, newNode.y, 0, newNode.cost));
				}
			}
		}
		if (cur.y < n) {
			newNode.x = cur.x;
			newNode.y = cur.y + 1;
			newNode.chance = cur.chance;
			newNode.cost = cur.cost + 1;

			if (map[newNode.y][newNode.x] == 0) {
				if (visit[newNode.y][newNode.x][newNode.chance] == 0) {
					visit[newNode.y][newNode.x][newNode.chance] = newNode.cost;
					if (newNode.x == m && newNode.y == n) {
						printf("%d\n", newNode.cost);
						return 0;
					}
					q.push(Node(newNode.x, newNode.y, newNode.chance, newNode.cost));
				}
			}
			else {
				if (newNode.chance == 1 && visit[newNode.y][newNode.x][0] == 0) {
					visit[newNode.y][newNode.x][0] = newNode.cost;
					if (newNode.x == m && newNode.y == n) {
						printf("%d\n", newNode.cost);
						return 0;
					}
					q.push(Node(newNode.x, newNode.y, 0, newNode.cost));
				}
			}
		}
		if (cur.y > 1) {
			newNode.x = cur.x;
			newNode.y = cur.y - 1;
			newNode.chance = cur.chance;
			newNode.cost = cur.cost + 1;

			if (map[newNode.y][newNode.x] == 0) {
				if (visit[newNode.y][newNode.x][newNode.chance] == 0) {
					visit[newNode.y][newNode.x][newNode.chance] = newNode.cost;
					if (newNode.x == m && newNode.y == n) {
						printf("%d\n", newNode.cost);
						return 0;
					}
					q.push(Node(newNode.x, newNode.y, newNode.chance, newNode.cost));
				}
			}
			else {
				if (newNode.chance == 1 && visit[newNode.y][newNode.x][0] == 0) {
					visit[newNode.y][newNode.x][0] = newNode.cost;
					if (newNode.x == m && newNode.y == n) {
						printf("%d\n", newNode.cost);
						return 0;
					}
					q.push(Node(newNode.x, newNode.y, 0, newNode.cost));
				}
			}
		}
	}
	printf("-1");
	return 0;
}