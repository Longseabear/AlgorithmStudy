/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int Answer;

typedef struct POINT {
	double x;
	double y;
}Point;

typedef struct LINE{
	Point from;
	Point to;
	char left_right;
	char left;
	char right;

	int gradient() {
		if (from.y > to.y)
			return -1;
		else
			return 1;
	}
	Point checkMinLeftOne(double midX, double midY) {
		Point minPoint = from.y < to.y ? from : to;
		if (abs(minPoint.y-midY) <= -(minPoint.x-midX)) {
			return minPoint;
		}
		else {
			Point res;
			int a = from.y - (from.x * gradient());
			if (gradient() == 1) {
				res.y = (a+midX+midY) / 2;
				res.x = res.y - a;
			}
			else {
				res.y = (a + midY - midX) / 2;
				res.x = a - res.y;
			}
			return res;
		}
	}
	int contain(double x, double y) {
		if (x >= from.x && x <= to.x) {
			if (gradient()==1 && y >= from.y && y <= to.y) {
				return 1;
			}
			else if(gradient() == -1 && y <= from.y && y >= to.y){
				return 1;
			}
		}
		return 0;
	}
	Point checkMinRightOne(double midX, double midY) {
		Point minPoint = from.y < to.y ? from : to;
		if (abs(minPoint.y - midY) <= (minPoint.x - midX)) {
			return minPoint;
		}
		else {
			Point res;
			int a = from.y - (from.x * gradient());
			if (gradient() == 1) {
				res.y = (a + midX + midY) / 2;
				res.x = res.y - a;
			}
			else {
				res.y = (a + midY - midX) / 2;
				res.x = a - res.y;
			}
			return res;
		}
	}

	Point checkMinPointOne(double midX, double midY) {
		Point minPoint = from.y < to.y ? from : to;
		if (minPoint.y >= abs(minPoint.x - midX) + midY) {
			return minPoint;
		}
		else{
			Point res;
			int a = from.y - (from.x * gradient());
			if (gradient()==1) {
				res.x = (midX + midY - a) / 2;
				res.y = res.x + a;
			}
			else {
				res.x = (a + midX - midY) / 2;
				res.y = -res.x + a;
			}
			return res;
		}
	}
	void checkAll(double midX, double midY){
		if (from.y >= abs(from.x - midX) + midY ||
			to.y >= abs(to.x - midX) + midY) {
			left_right = 1;
		}
		else {
			left_right = 0;
		}
		if (abs(from.y-midY) <= -(from.x-midX)||
			abs(to.y - midY) <= -(to.x - midX)) {
			left = 1;
		}
		else {
			left = 0;
		}
		if (abs(from.y - midY) <= (from.x - midX) ||
			abs(to.y - midY) <= (to.x - midX)) {
			right = 1;
		}
		else {
			right = 0;
		}
	}
}Line;

struct based_x
{
	inline bool operator() (const Point& struct1, const Point& struct2)
	{
		return struct1.x < struct2.x;
	}
};
int getGradient(double fromY, double toY) {
	if (fromY > toY)
		return -1;
	else
		return 1;
}
Point point[200001];
Line line[200001];

const double DOUBLE_INFINITY = std::numeric_limits<double>::infinity();

void checkCurrentState(double middleX, double middleY , int lineS, int lineE) {
	for (int i = lineS; i < lineE; i++) {
		line[i].checkAll(middleX, middleY);
	}
}

#define MIN(a,b) (((a)>(b))?(b):(a))
#define MAX(a,b) (((a)>(b))?(a):(b))
double recul(double start, double end, int lineS, int lineE, int L, double currentMin) {
	if (L <= 0 || start > end) {
		return DOUBLE_INFINITY;
	}
	double min = DOUBLE_INFINITY;
	double middleX = start + ((end - start) / 2);
	double middleY = ((end - start) / 2);


	checkCurrentState(middleX, middleY, lineS, lineE);

	// one check
	for (int i = lineS; i < lineE; i++) {
		if (line[i].left_right) {
			Point val = line[i].checkMinPointOne(middleX, middleY);
			if (min > val.y)
				min = val.y;
		}
	}
	if (L - 1 <= 0)
		return MAX(currentMin, min);
	min = MAX(currentMin, min);

	// two check
	int leftIndex = -1, rightIndex= -1;
	Point leftMin, rightMin;
	leftMin.y = DOUBLE_INFINITY;
	rightMin.y = DOUBLE_INFINITY;
	for (int i = lineS; i < lineE; i++) {
		if (line[i].left && line[i].left_right!=1) {
			Point val = line[i].checkMinLeftOne(middleX, middleY);
			if (leftMin.y > val.y) {
				leftMin = val;
				leftIndex = i;
			}
		}
		if (line[i].right && line[i].left_right != 1) {
			Point val = line[i].checkMinRightOne(middleX, middleY);
			if (rightMin.y > val.y) {
				rightMin = val;
				rightIndex = i;
			}
		}
	}
	if (rightMin.y == DOUBLE_INFINITY || leftMin.y == DOUBLE_INFINITY) {
		return min;
	}
	
	double nextLeftIndex = leftMin.x + leftMin.y;
	double nextRightIndex = rightMin.x - rightMin.y;

	if (nextLeftIndex >= nextRightIndex) {
		double doubleMin = MAX(leftMin.y, rightMin.y);
		doubleMin = MAX(currentMin, doubleMin);
		return MIN(min, doubleMin);
	}
	else {
		if (line[leftIndex].gradient() == 1 && line[rightIndex].gradient==-1) {
			double middlePoint = (line[leftIndex].from.x + line[rightIndex].to.x) / 2;
			Point p = line[leftIndex].checkMinPointOne(middlePoint,0);
			Point p2 = line[rightIndex].checkMinPointOne(middlePoint, 0);

			if (line[leftIndex].contain(p.x, p.y) && line[rightIndex].contain(p2.x,p2.y) {
				double newmin = MAX(p.y, p2.y);
				newmin = MAX(currentMin, newmin);
				min = 
			}
		}
	}

	return min;
}
double algo() {
	int N, M, L;
	scanf("%d %d %d", &N, &M, &L);
	for (int i = 0; i <= M; i++) {
		scanf("%lf %lf", &point[i].x, &point[i].y);
	}
	sort(point, point + M + 1, based_x());
	int j = 0;
	int currentGradient = 0;
	for (int i = 0; i < M; i++) {
		if (i != 0 && getGradient(point[j].y, point[j + 1].y)==currentGradient){
			i--;
			M--;
			line[i].to = point[j + 1];
			j++;
		}
		else {
			line[i].from = point[j];
			line[i].to = point[j + 1];
			currentGradient = line[i].gradient();
			j++;
		}
	}
	for (int i = 0; i < M; i++) {
		line[i].left = 0;
		line[i].right = 0;
		line[i].left_right = 0;
	}
	return recul(0, N, 0, M, L, -1);
}

int main(int argc, char** argv)
{
	setbuf(stdout, NULL);

//	algo();
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
		double answer = algo();
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;

		if (answer == DOUBLE_INFINITY) {
			printf("-1\n");
			continue;
		}

		if ((long long)answer == (long long)(answer + 0.5)) {
			printf("%.0lf 1\n", answer);
		}
		else {
			printf("%.0lf 2\n", ((answer + 0.5)) * 2 - 1);
		}
	}

	return 0;//Your program should return 0 on normal termination.
}