// HW01.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int getMaxSeq(int*a,int n,int &i_start,int &i_end) {
	int currentSum = 0;
	int MaxSum = 0;
	i_start = 0;
	i_end = 0;
	int i_temp = 0;

	for (int i = 0; i < n; i++)
	{

		currentSum += a[i];
		if (currentSum>MaxSum)
		{
			MaxSum = currentSum;
			i_end = i;
			i_start = i_temp;
		}
		else if (currentSum < 0) {
			currentSum = 0;
			i_temp = i + 1;
		}
	}
	return MaxSum;
}
int getMaxSeq2(int*a, int n, int &i_start, int &i_end) {
	int current_sum = 0;
	int max_sum = -1;
	i_start = 0;
	i_end = 0;
	for (int i = 0; i < n; i++)
	{
		current_sum = 0;
		for (int j = i; j < n; j++) {
			current_sum += a[j];
			if (current_sum>max_sum)
			{
				max_sum = current_sum;
				i_start = i;
				i_end = j;
			}
		}
	}
	return max_sum;
}
int main()
{
	int n;
	cin >> n;
	int*a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int i_start, i_end;
	int max = getMaxSeq2(a, n,i_start,i_end);
	if (max < 0) {
		cout << 0 <<" "<< a[0] <<" "<< a[n - 1] << endl;
	}
	else
	{
        cout << max <<" "<< a[i_start]<<" "<<a[i_end]<<endl;
	}
	
    return 0;
}

