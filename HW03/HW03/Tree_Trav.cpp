#include"stdafx.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int N;
class Node {
public:
	int num;
	Node* left;
	Node* right;
	Node() {
		left = NULL;
		right = NULL;
	}
};
int counter = 0;
string op;
int num;
Node* preOrder() {
	Node* root=NULL;
	if (counter<2*N)
	{
		cin >> op;
		if (op.length()==4)
		{
			cin >> num;
			root = new Node();
			root->num = num;
			counter++;
		}
		if (op.length()==3)
		{
			counter++;
			return NULL;
		}
		root->left = preOrder();
		root->right = preOrder();
	}
	return root;
}
vector<int>post;
void postOrder(Node* root) {
	if (root!=NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		post.push_back(root->num);
	}

}
int main()
{

	cin >> N;
	Node* root = preOrder();
	postOrder(root);
	cout << post[0];
	for (int i = 1; i < N; i++)
	{
		cout <<" " << post[i];
	}
	cout << endl;
	return 0;
}