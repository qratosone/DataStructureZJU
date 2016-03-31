#include "stdafx.h"
#include <iostream>
#include<algorithm>
using namespace std;
class Node {
public:
	Node* left;
	Node* right;
	int data;
	int height;
	Node(int v):data(v),left(NULL),right(NULL),height(0){}
};
int getHeight(Node* node){
	if (node==NULL)
	{
		return -1;
	}
	return node->height;
}
bool isBalanced(Node* node) {
	int balanced = getHeight(node->left) - getHeight(node->right);
	return abs(balanced) < 2;
}
Node* rotate_LL(Node* node) {
	Node* temp = node->left;
	node->left = temp->right;
	temp->right = node;
	//更新两者的高度
	node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
	temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
	return temp;
}
Node* rotate_RR(Node* node) {
	Node* temp = node->right;
	node->right = temp->left;
	temp->left = node;
	node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
	temp->height = max(getHeight(node->left), getHeight(node->right)) + 1;
	return temp;
}
Node* rotate_LR(Node* node) {
	Node* temp = node->left;
	node->left = rotate_RR(temp);
	return rotate_LL(node);
}
Node* rotate_RL(Node* node) {
	Node* temp = node->right;
	node->right = rotate_LL(temp);
	return rotate_RR(node);
}
Node* insert(Node* root, int value) {
	if (root==NULL)
	{
		root =new Node(value);
	}
	else
	{
		if (root->data<value)//R
		{
			root->right = insert(root->right, value);
			if (!isBalanced(root))
			{
				if (root->right->data < value) { //RR
					root = rotate_RR(root);
				}
				else//RL
				{
					root = rotate_RL(root);
				}
			}
		}
		else
		{
			root->left = insert(root->left, value);//L
			if (!isBalanced(root)) {
				if (root->left->data>value)//LL
				{
					root = rotate_LL(root);
				}
				else
				{   //LR
					root = rotate_LR(root);
				}
			}
		}
	}
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;//更新root的高度
	return root;
}
void PrintTree(Node* root)
{
	if (root != NULL)
	{
		cout << root->data << "--";
		PrintTree(root->left);
		PrintTree(root->right);
	}
	
}
int main() {
	int N;
	cin >> N;
	Node* root = NULL;
	int input;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		root = insert(root, input);
//		PrintTree(root);
	}
	int output = root->data;
	cout << output << endl;
	return 0;
}