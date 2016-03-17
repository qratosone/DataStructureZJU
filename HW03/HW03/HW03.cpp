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
void treeValue(TreeNode& tree, int mark[]) {
	char data, left, right;
	cin >> data >> left >> right;
	tree.data = data;
	if (left != '-')
	{
		int leftnum = left - '0';
		mark[leftnum] = 1;
		tree.left = leftnum;
	}
	else
	{
		tree.left = -1;
	}
	if (right!='-')
	{
		int rightnum = right - '0';
		mark[rightnum] = 1;
		tree.right = rightnum;
	}
	else
	{
		tree.right = -1;
	}
}
bool Isomorphic(vector<TreeNode>T1,vector<TreeNode>T2,int r1, int r2) {
	if(r1==-1&&r2==-1){
		return true;
	}
	if (r1 == -1 && r2 != -1 || r1 != -1 && r2 == -1) {
		return false;
	}
	if (T1[r1].data!=T2[r2].data)
	{
		return false;
	}
	if (T1[r1].left == -1 && T2[r2].left == -1) {
		return Isomorphic(T1, T2, T1[r1].right, T2[r2].right);
	}
	if ((T1[r1].left != -1) && (T2[r2].left != -1) && (T1[T1[r1].left]).data==(T2[T2[r2].left]).data) {
		return (Isomorphic(T1, T2, T1[r1].left, T2[r2].left) && Isomorphic(T1, T2, T1[r1].right, T2[r2].right));
	}
	else
	{
		return (Isomorphic(T1, T2, T1[r1].left, T2[r2].right) && Isomorphic(T1, T2, T1[r1].right, T2[r2].left));
	}
}
int main()
{
	int N;
	cin >> N;
	vector<TreeNode>TreeA;
	vector<TreeNode>TreeB;
	int markA[20] = { 0 };
	int markB[20] = { 0 };
	TreeNode nodeA, nodeB;
	for (int i = 0; i < N; i++)
	{
		treeValue(nodeA, markA);
		TreeA.push_back(nodeA);
	}
	int rootA;
	for (int i = 0; i <N; i++)
	{
		if (markA[i] == 0) {
			rootA = i;
			break;
		}
	}
//	cout << rootA << endl;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		treeValue(nodeB, markB);
		TreeB.push_back(nodeB);
	}
	int rootB;
	for (int i = 0; i < N; i++)
	{
		if (markB[i] == 0) {
			rootB = i;
//			cout << i << endl;
			break;
		}
	}
//	cout << rootB << endl;
	bool judge = Isomorphic(TreeA, TreeB, rootA, rootB);
	if (judge)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
    return 0;
}

