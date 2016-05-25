// HW10.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
	int count[51] = { 0 };
	int N;
	cin >> N;
	int input;
	for (int i = 0; i <N; i++)
	{
		cin >> input;
		count[input]++;
	}
	for (int i = 0; i < 51; i++)
	{
		if (count[i])
		{
			cout << i << ":" << count[i] << endl;
		}
	}
    return 0;
}

