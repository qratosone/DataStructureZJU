// StackOverflow.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;
void printN(int N) {
	
	if (N>0)
	{
		printN(N - 1);
	}
	cout << N << endl;
}
int main()
{
	int N;
	cin >> N;
	printN(N);
    return 0;
}

