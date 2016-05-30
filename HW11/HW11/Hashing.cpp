#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;
bool isPrime(int x) {
	if (x == 1)return false;
	if (x == 2 || x == 3)return true;
	for (int i = 2; i*i <=x; i++)
	{
		if (x%i == 0)return false;

	}
	return true;
}
bool flag[10000];
int main() {
	int m, n, input;//mÊÇ´óÐ¡
	cin >> m >> n;
	while (!isPrime(m))
	{
		m++;
	}
	while(n--)
	{
		cin >> input;
		bool inserted = false;
		for (int j = 0; j < m; j++) {
			int position = (input + j*j) % m;
			if (!flag[position])
			{
				inserted = true;
				flag[position] = true;
				cout << position << (n ? " " :"\n");
				break;
			}
		}
		if (!inserted) {
			cout<<"-"<< (n ? " " : "\n");
		}
	}
	return 0;
}