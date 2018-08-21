/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int Answer;

int pelindrom(char* arr, int size) {
	int flag = 1;
	for (int i = 0; i < size / 2; i++) {
		if (arr[i] != arr[size - 1 - i]) {
			flag = 0; break;
		}
	}
	return flag;
}
int checkRotation(int n) {
	char str[6];
	sprintf(str, "%d", n);
	return pelindrom(str, strlen(str));
}
pair<int, int> dp[10001];
#define MIN(a,b) (((a)>(b))?(b):(a))
#define MAX(a,b) (((a)<(b))?(b):(a))
void getDP() {
	vector<int> maxPool;

	for (int i = 0; i <= 9; i++) {
		dp[i] = pair<int,int>(i,-1);
		if(i!=0)
			maxPool.push_back(i);
	}
	int currentMax = 9;
	for (int i = 10; i <= 10000; i++) {
		if (checkRotation(i)) {
			dp[i] = pair<int, int>(i, -1);
			currentMax = i;
			maxPool.push_back(i);
		}
		else {
			if (dp[i - currentMax].second != -1) {
				int maxPoolSize = maxPool.size();
				int flag = 1;
				for (int j = 0; j < maxPoolSize-1; j++) {
					if (dp[i - maxPool[j]].second == -1) {
						int minV = MIN(maxPool[j],i-maxPool[j]);
						int maxV = MAX(maxPool[j], i - maxPool[j]);
						dp[i] = pair<int, int>(maxV, minV);
						flag = 0;
						break;
					}
				}
				if (flag) {
					dp[i] = pair<int, int>(currentMax, i - currentMax);
				}
			}
			else {
				dp[i] = pair<int, int>(currentMax, i - currentMax);
			}
		}
	}
}
/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

int main(int argc, char** argv)
{
	/*getDP();
	printf("ok");
	for (int i = 0; i <= 10000; i++) {
		printf("%d ::: ", i);
		int count = 1;
		vector<int> res;
		int currentNumber = i;
		while (1) {
			if (dp[currentNumber].second == -1) {
				res.push_back(dp[currentNumber].first);
				break;
			}
			res.push_back(dp[currentNumber].first);
			currentNumber = dp[currentNumber].second;
			count++;
		}
		printf("%d ", count);
		for (int i = 0; i != count; i++) {
			printf("%d ", res[i]);
		}
		printf("\n");
	}
	exit(1);*/

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
	getDP();
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		int n;
		vector<int> res;
		scanf("%d", &n);

		int count = 1;
		int currentNumber = n;
		while (1) {
			if (dp[currentNumber].second == -1) {
				res.push_back(dp[currentNumber].first);
				break;
			}
			res.push_back(dp[currentNumber].first);
			currentNumber = dp[currentNumber].second;
			count++;
		}

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		if (count < 4) {
			printf("%d ", count);
			for (int i = 0; i < count - 1; i++)
				printf("%d ", res[i]);
			printf("%d\n", res[count - 1]);
		}
		else {
			printf("0\n");
		}
	}

	return 0;//Your program should return 0 on normal termination.
}