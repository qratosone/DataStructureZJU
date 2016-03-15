#include"stdafx.h"
#include<iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
	int m, n, k;
	cin >> m >> n >> k;
	int num = 1;
	stack<int> s;
	int input;
	for (int i = 0; i <k; ++i) {
		bool flag = true;
		s.push(num);
		for (int j = 0; j <n; ++j) {
			cin >> input;
			
			do {
	//			cout << "size " << s.size() << endl;
				if (s.empty() || s.top() != input) {
					num++;
					s.push(num);
	//				cout << input << " push " << num << endl;
	//			cout << "size " << s.size() << endl;
				}
				else {
	//				cout << input << " pop " << s.top() << endl;
					s.pop();
	//			cout << "size " << s.size() << endl;
					break;
				}

				if (s.size()>m) {
	//				cout << "size " << s.size() << endl;
					flag = false;
				}
	//			cout << "size " << s.size() << endl;

			}while (!s.empty() && flag);

		}
		if (flag) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		num = 1;
		while (!s.empty())
		{
			s.pop();
		}
	}
	return 0;
}