#include"stdafx.h"
#include<iostream>
#include<string>
#include <vector>
#include<queue>
using namespace std;
class Node {
public:
	int data;
    int left;
	int right;
	Node() {
		data = 0;
		left = -1;
		right = -1;
	}
};
int main() {
	vector<Node>input;
	int N;
	cin >> N;
	int check[20] = { 0 };
	char left, right;
	for (int i = 0; i < N; i++)
	{
		Node node;
		cin >> left >> right;
		if (left!='-')
		{
			int leftnum = left - '0';
			node.left = leftnum;
			check[leftnum] = 1;
		}
		if (right!='-')
		{
			int rightnum = right - '0';
			node.right = rightnum;
			check[rightnum] = 1;
		}
		input.push_back(node);
	}
	int root;
	for (int i = 0; i < N; i++) {
		if (check[i]==0)
		{
			root = i;
		}
	}
//	cout << root << endl;
	vector<int>output;
	queue<int>lev_trav;
	lev_trav.push(root);
	while (!lev_trav.empty())
	{
		int get = lev_trav.front();
//		cout << get << endl;
		if (input[get].left==-1&&input[get].right==-1)
		{
//			cout << "push"<<get << endl;
			output.push_back(get);
		}
		if (input[get].left!=-1)
		{
			lev_trav.push(input[get].left);
		}
		if (input[get].right!=-1)
		{
			lev_trav.push(input[get].right);
		}
		lev_trav.pop();
	}
	
	for (int i = 0; i < output.size(); i++)
	{
		if (i==0) {
			cout << output[i];
		}
		else
		{
			cout << " " << output[i];
		}
	}
	cout << endl;
	return 0;
}