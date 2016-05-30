// HW11.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include<cmath>
#define Max 1000000

using namespace std;
class Node {
public:
	string data;
	Node* next;
	int count;
};
int nextPrime(int N) {
	int i, p = (N % 2) ? N + 2 : N + 1;
	while (p<=Max)
	{
		for (int i = (int)sqrt(p); i >2; i--)
		{
			if (!(p%i))break;
		}
		if (i==2)
		{
			break;
		}
		else
		{
			p += 2;
		}
	}
	return p;
}
class HashTable {
private:
	int tableSize;
	Node* Heads;
public:
	HashTable(int size) {
		tableSize = nextPrime(size);
		Heads = new Node[tableSize];
		for (int i = 0; i < tableSize; i++)
		{
			Heads[i].data = "";
			Heads[i].next = NULL;
			Heads[i].count = 0;
		}
	}
	~HashTable() {
		delete[] Heads;
	}
	int Hash(int Key) {
		return Key%tableSize;
	}
	Node* find(string Key) {

	}
};
int main()
{
    return 0;
}

