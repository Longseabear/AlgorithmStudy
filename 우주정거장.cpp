#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef struct Node {
	set<int> link;
	int num;
}Node;
typedef struct EDGE {
	int val;
	int* num;
}Edge;

Node node[200001];
Edge edge[200001];
struct less_than_key
{
	inline bool operator() (const Edge& struct1, const Edge& struct2)
	{
		int a = *(struct1.num);
		int b = *(struct2.num);

		return (a < b);
	}
};

int algo() {
	int n, k;
	int count = 0;

	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		edge[i].val = i;
		edge[i].num = 0;
		node[i].link.clear();
		node[i].num = 0;
	}
	for (int i = 0; i < k; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		node[a].num++;
		node[b].num++;
		node[a].link.insert(b);
		node[b].link.insert(a);
	}
	for (int i = 1; i <= n; i++) {
		edge[i].val = i;
		edge[i].num = &node[i].num;
	}
	int check = 1;
	while (check) {
		check = 0;
		sort(edge + 1, edge + 1 + n, less_than_key());
		for (int i = 1; i <= n; i++) {
			if (*edge[i].num == 2) {
				set<int>::iterator it = node[edge[i].val].link.begin();
				int val1 = *it;
				int val2 = *(++it);

				if (node[val1].link.find(val2) != node[val1].link.end()) {
					count++;
					check = 1;
					node[edge[i].val].num = 0;
					node[edge[i].val].link.clear();
					node[val1].num--;
					node[val2].num--;
					node[val1].link.erase(edge[i].val);
					node[val2].link.erase(edge[i].val);
				}
			}
		}
	}

	return n - count;
}

/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>


int Answer;

int main(int argc, char** argv)
{
	setbuf(stdout, NULL);
	int T, test_case;
	/*
	The freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using cin function.
	You may remove the comment symbols(//) in the below statement and use it.
	Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		Answer = algo();

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}