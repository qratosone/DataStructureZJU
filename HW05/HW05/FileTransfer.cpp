#include "stdafx.h"
#include <iostream>
using namespace std;
class Set {
private:
	int size;
	int *father;
public:
	Set(int length) {
		father = new int[length + 1];
		for (int i = 1; i <=length; i++)
		{
			father[i] = i;
		}
	}
	~Set() {
		delete[] father;
	}
	int find_set(int node) {
		if (father[node]!=node)
		{
			return find_set(father[node]);
		}
		return node;
	}
	bool merge(int node1, int node2) {
		int mark1 = find_set(node1);
		int mark2 = find_set(node2);
		if (mark1!=mark2)
		{
			father[mark1] = mark2;
			return true;
		}
		return false;
	}

};
int main() {
	int N;
	cin >> N;
	Set set(N);
	char op;
	int x, y;
	while (true)
	{
		cin >> op;
		if (op == 'S') {
			break;
		}
		if (op=='I')
		{
			cin >> x >> y;
			if (set.merge(x, y)) {
				N--;
			}
			
		}
		if (op=='C')
		{
			cin >> x >> y;
			if (set.find_set(x)==set.find_set(y))
			{
				cout << "yes" << endl;
			}
			else
			{
				cout << "no" << endl;
			}
		}
	}

	if (N!=1)
	{
		cout << "There are "<<N<<" components." << endl;
	}
	else
	{
		cout << "The network is connected." << endl;
	}
	return 0;
}