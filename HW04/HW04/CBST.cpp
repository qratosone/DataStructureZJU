#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int node[1001] ;
vector<int>input;
int counter;
void build(int root) {
	if (root>input.size())
	{
		return;
	}
	int lchild = root * 2;
	int rchild = root * 2 + 1;
	build(lchild);
	node[root] = input[counter];
	counter++;
	build(rchild);
}
int main() {
	int N;
	cin >> N;
	int input_num;
	for (int i = 0; i < N; i++)
	{
		cin >> input_num;
		input.push_back(input_num);
	}
	sort(input.begin(), input.end());
	counter = 0;
	build(1);
	for (int i = 1; i <=N; i++)
	{
		if (i == 1) {
			cout << node[i];
		}
		else {
			cout << " " << node[i];
		}
	}
	cout << endl;
	return 0;
}
