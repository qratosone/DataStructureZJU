#include"stdafx.h"
#include <memory.h>
#include <iostream>
#include <vector>
#include<algorithm>
#include <string>
#include <cstdio>
using namespace std;
int addr[100005];
class Node {
public:
	int addr;
	int data;
	int next;
	Node(){}
	Node(int addr, int data, int next) {
		this->addr = addr;
		this->data = data;
		this->next = next;
	}
};
int main() {
	int init, list;
	memset(addr, -1, sizeof(addr));
	int n;
	cin >> init >> n >> list;
	vector<Node>vInput;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		Node temp;
		cin >> temp.addr >> temp.data >> temp.next;
		vInput.push_back(temp);
		addr[temp.addr] = count++;//记录当前节点在vector中的位置
	}
	vector<Node>nodelist;
	int ptr = init;
	for (int i = 0; i < n; i++)
	{
		nodelist.push_back(vInput[addr[ptr]]);
		ptr = vInput[addr[ptr]].next;
		if (ptr==-1)
		{
			break;
		}
	}
	int times = nodelist.size() / list;
	for (int i = 0; i <times; i++)
	{
		reverse(nodelist.begin() + i*list, nodelist.begin() + i*list + list);
	}
	for (int i = 0; i < nodelist.size(); i++)
	{
		if(i == nodelist.size() - 1)
		{
			printf("%05d %d -1", nodelist[i].addr, nodelist[i].data);
		}
		else
		{
			printf("%05d %d %05d", nodelist[i].addr, nodelist[i].data, nodelist[i + 1].addr);
		}
		cout << endl;
	}
	return 0;
}