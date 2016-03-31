// HW04.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class TreeNode {
public:
	int data;
	TreeNode* left;
	TreeNode* right;
	bool flag;
	TreeNode() {
		left = NULL;
		right = NULL;
		flag = false;
	}
	TreeNode(int v) {
		data = v;
		left = NULL;
		right = NULL;
		flag = false;
	}
};
TreeNode* insert(TreeNode* T, int v) {
	if (!T) {
		T = new TreeNode(v);
	}
	else
	{
		if (T->data<v)
		{
			cout << T->data << endl;
			cout << "right " << v << endl;
			T->right = insert(T->right, v);
		}
		else
		{
			cout << T->data << endl;
			cout << "left " << v << endl;
			T->left = insert(T->left, v);
		}
	}
	
	return T;
}
TreeNode* buildTree(int M) {
	TreeNode* root;
	int v;
	cin >> v;
	root = new TreeNode(v);
	for (int i = 1; i < M; i++)
	{
		cin >> v;
		root = insert(root, v);
	}
	return root;
}

bool checkNode(TreeNode* T,int v){
	if (T->flag)
	{
		if (T->data > v) {
			cout << T->data<<" " << endl;
			return checkNode(T->left, v);
		}
		else if(T->data<v)
		{
			cout <<T->data<<" "<<v << endl;
			return checkNode(T->right, v);
		}
		else { 
			cout << "falseA " << T->data << " " << v << endl;
			return false; 
		}
	}
	else
	{
		if (T->data == v) {
			T->flag = true;
			return true;
		}
		else
		{
			cout << "falseB " << T->data << " " << v << endl;
			return false;
		}
	}
}
bool judge(TreeNode* T, int N) {
	int input;
	bool flag = false;
	cin >> input;
	if (T->data!=input)
	{
		flag =true;
	}
	else
	{
		T->flag = true;
	}
	for (int i = 1; i <N ; i++)
	{
		cin >> input;
		if (!flag&&!checkNode(T,input))
		{
			flag = true;
		}
	}
	return !flag;
}
int main()
{
	int N, M;
	cin >> N;
	while (N)
	{
		cin >> M;
		
		TreeNode* root = buildTree(N);
		cout << "build tree " << N << " " << M << endl;
		for (int j = 0; j < M; j++)
		{
			if (judge(root, N)) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
			
		}
		delete root;
		cin >> N;
	}
    return 0;
}

