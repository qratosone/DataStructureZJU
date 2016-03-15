// HW03.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;
class TreeNode {
public:
	char data;
	int left;
	int right;
};

int main()
{
	int N;
	cin >> N;
	vector<TreeNode>TreeA;
	vector<TreeNode>TreeB;
	int* markA = new int[N];
	memset(markA, 0, sizeof(markA));
	int* markB = new int[N];
	memset(markB, 0, sizeof(markB));
	TreeNode nodeA, nodeB;
	for (int i = 0; i < N; i++)
	{
		char data, left, right;
		cin >> data >> left >> right;
		TreeA.data = data;
		if (left!='-')
		{
			int leftnum = left - '0';

		}
	}
    return 0;
}

