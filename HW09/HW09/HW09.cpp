// HW09.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Vector {
private:
	int size, length;
	int * data, *temp;
	void merge_sort(int l, int r) {
		if (l == r) {//如果左右边界相等，表示已完成排序，直接退出
			return;
		}
		int mid = (l + r) / 2; //取中点
		merge_sort(l, mid); //分别对左右两部分递归调用
		merge_sort(mid + 1, r);
		int x = l, y = mid + 1, loc = l; //x表示左半部分指针，y表示右半部分指针，loc表示总的指针
		while (x <= mid || y <= r) {//左右两侧至少有一侧没有跑完
			if (x <= mid && (y>r || data[x] <= data[y])) {//对于条件：x没有跑完，而y已经跑完，或者左边的值不大于右边的值
				temp[loc] = data[x];//把x填进最后排序完成的数组
				x++;
			}
			else {//相反则把y填进去
				temp[loc] = data[y];
				y++;
			}
			loc++;
		}
		for (int i = l; i <= r; i++) {
			data[i] = temp[i];//覆盖原有数组
		}
	}
public:
	Vector(int input_size) {
		size = input_size;
		length = 0;
		data = new int[size];
		temp = new int[size];
	}
	~Vector() {
		delete[] data;
		delete[] temp;
	}
	void push_back(int value) {
		data[length] = value;
		length++;
	}
	bool insert(int loc, int value) {
		if (loc < 0 || loc > length) {
			return false;
		}
		if (length >= size) {
			return false;
		}
		for (int i = length; i > loc; --i) {
			data[i] = data[i - 1];
		}
		data[loc] = value;
		length++;
		return true;
	}
	void print() {
		for (int i = 0; i < length; ++i) {
			if (i > 0) {
				cout << " ";
			}
			cout << data[i];
		}
		cout << endl;
	}
	void sort() {
		merge_sort(0, length - 1);
	}

};
int main()
{
	int N, temp;
	cin >> N;
	Vector v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	v.sort();
	v.print();
    return 0;
}

