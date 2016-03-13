// HW02.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>

using namespace std;
class Node {
public:
	int _val;
	int _exp;
	Node* next;
	Node* prev;
	Node() {
		_val = 0;
		_exp = 0;
		next = NULL;
		prev = NULL;
	}
	Node(int val, int exp) {
		_val = val;
		_exp = exp;
		next = NULL;
		prev = NULL;
	}
	bool isGreater(Node* another) {
		if (_exp>another->_exp)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
class LinkList {
public:
	Node* head;
	LinkList() {
		head = NULL;
	}

	void insert(int val, int exp) {
		if (head==NULL)
		{
			head = new Node(val, exp);//head有值
		}
		else
		{
			Node* p = head;
			while (p->next!=NULL)
			{
				p = p->next;
			}
			p->next = new Node(val, exp);
			p->next->prev = p;
		}
	}
	void insertAfter(int val, int exp) {
		Node* p = head;
		while (true)
		{
			if (p->_exp>exp) {
				p = p->next;
			}
			else
			{
				break;
			}
		}
	}
	void traverse() {
//		cout << "traverse"<<endl;
		Node* p = head;
		while (p)
		{
			cout << p->_val << " " << p->_exp<<" " ;
			p = p->next;
		}
		cout << endl;
	}

};

void LLplus(LinkList L1, LinkList L2,LinkList& result) {
	Node* p1 = L1.head;
	LinkList temp2;
	Node* p = L2.head;
	while (p != NULL)
	{
		temp2.insert(p->_val, p->_exp);
		p = p->next;
	}
	Node* p2 = temp2.head;
	while (p1!=NULL&&p2!=NULL)
	{
		if (p1->_exp == p2->_exp) {
			int val = p1->_val + p2->_val;
			int exp = p1->_exp;
			if (val!=0)
			{
				result.insert(val, exp);
			}
			p1 = p1->next;
			p2 = p2->next;
		}
		else
		{
			int val, exp;
			if (p1->isGreater(p2))
			{
				val = p1->_val;
				exp = p1->_exp;
				result.insert(val, exp);
				p1 = p1->next;
			}
			else
			{
				val = p2->_val;
				exp = p2->_exp;
				result.insert(val, exp);
				p2 = p2->next;
			}
			
		}

	}
	while (p1!=NULL)
	{
		int val = p1->_val;
		int exp = p1->_exp;
		result.insert(val, exp);
		p1 = p1->next;
	}
	while (p2 != NULL)
	{
		int val = p2->_val;
		int exp = p2->_exp;
		result.insert(val, exp);
		p2 = p2->next;
	}
	if (result.head==NULL)
	{
		result.insert(0, 0);
	}
}
void LLmultiply(LinkList l1, LinkList l2, LinkList& result) {
	LinkList temp;
	Node* p1 = l1.head;
	Node* p2 = l2.head;
	bool flag = false;
	while (p1!=NULL)
	{
		//cout << "p1 " << p1->_val << " " << p1->_exp << endl;
		while (p2 != NULL) {
		//	cout << "p2 " << p2->_val << " " << p2->_exp << endl;
			int val = p1->_val*p2->_val;
			int exp = p1->_exp + p2->_exp;
			temp.insert(val, exp);
			p2 = p2->next;
		}
		if (!flag) {
			Node* p = temp.head;
			while (p!=NULL)
			{
				result.insert(p->_val, p->_exp);
				p = p->next;
			}
			flag = true;
		}

	
	}
}
int main()
{
	LinkList L1;
	int N;
	cin >> N;
	int val, exp;
	for (int i = 0; i < N; i++)
	{
		cin >> val >> exp;
		L1.insert(val, exp);
	}
	LinkList L2;
	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> val >> exp;
		L2.insert(val, exp);
	}
	LinkList resultPlus;
	LLplus(L1, L2, resultPlus);
	resultPlus.traverse();
	LinkList resultMultiply;
	LLmultiply(L1, L2, resultMultiply);
	resultMultiply.traverse();
    return 0;
}

