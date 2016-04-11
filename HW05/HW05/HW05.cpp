// HW05.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
class Heap {
private:
	int *data;
	int size;
public:
	Heap(int length) {
		size =1;
		data = new int[length+1];
		data[0] = -10001;
	}
	~Heap() {
		delete[] data;
	}
	void insert(int value) {
		data[size] = value;
		int current = size;
		int father = current / 2;
		while (data[current]<data[father])
		{
			swap(data[current], data[father]);
			current = father;
			father = current / 2;
			
		}
		//cout << father << " " << current << endl;
		size++;
	}
	void output() {
		for (int i = 1; i <size; i++)
		{
			cout << data[i] << endl;
		}
	}
	void output_route(int start) {
		bool flag = false;
		int current = start;
		
		while (true)
		{
			
			if (!flag)
			{
				cout << data[current];
				flag = true;
			}
			else
			{
				cout << " " << data[current];
			}
			if (current == 1)
			{
				cout << endl;
				break;
			}
			current /= 2;
			
		}
	}
};

int main()
{
	int M,N;
	cin >> M>>N;
	Heap heap(M);
	int input;
	for (int i = 0; i < M; i++)
	{
		cin >> input;
		heap.insert(input);
	}
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		heap.output_route(input);
	}
    return 0;
}

