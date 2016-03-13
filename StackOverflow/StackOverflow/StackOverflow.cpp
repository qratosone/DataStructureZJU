// StackOverflow.cpp : 定义控制台应用程序的入口点。
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

