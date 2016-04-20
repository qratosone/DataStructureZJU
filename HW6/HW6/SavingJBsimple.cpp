#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
class Node {
public:
	int x;
	int y;
	bool visited;
	Node() {
		visited = false;
	}
};
vector<Node>crocodile;
int jump;
int n;
int new_x = 0, new_y = 0;
double distance(int a, int b, int c, int d)
{
	if (a<0) a = -a;
	if (b<0) b = -b;
	if (c<0) c = -c;
	if (d<0) d = -d;

	//现在 a b c d 都是正数
	//  double y=1.0*((a-c)*(a-c)+(d-b)*(d-b));
	double y = hypot((a - c), (b - d));  //可以为 负 0
	return y;
}
void bank(int i)
{
	int x = crocodile[i].x, y = crocodile[i].y;
	if (distance(x, 0, 50, 0) <= jump) {
		cout << "Yes" << endl;
		exit(0);
	}
	else if (distance(0, y, 0, 50) <= jump) {
		cout << "Yes" << endl;
		exit(0);
	}

}
void jump_action(int i) {
	bank(i);
	stack<int>s;
	s.push(i);
	int current_x = crocodile[i].x;
	int current_y = crocodile[i].y;
	while (!s.empty())
	{
		for (int j = 0; j < n; j++) {
			int next_x = crocodile[j].x;
			int next_y = crocodile[j].y;
			if (distance(current_x, current_y, next_x, next_y) <= jump&&crocodile[j].visited == false)
			{
				crocodile[j].visited = true;
				bank(j);
				s.push(j);
				i = j;
				current_x = crocodile[i].x;
				current_y = crocodile[i].y;
				j = 0;
			}
		}
		if (s.empty()) {
			return;
		}
		i = s.top();
		s.pop();
		current_x = crocodile[i].x;
		current_y = crocodile[i].y;
	}
}
int main() {
	cin >> n >> jump;
	if (jump>=50)
	{
		cout << "Yes" << endl;
		return 0;
	}
	Node input;
	stack<Node>s;
	for (int i = 0; i < n; i++)
	{
		cin >> input.x >> input.y;
		crocodile.push_back(input);
	}
	int x1 = 0, y1 = 0, x2, y2;
	for (int i = 0; i < n;i++)
	{
		x2 = crocodile[i].x;
		y2 = crocodile[i].y;
		if (distance(x1,y1,x2,y2)<=jump&&crocodile[i].visited==false)
		{
			crocodile[i].visited = true;
			jump_action(i);
		}

	}
	cout << "No" << endl;
	return 0;
}