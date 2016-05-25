// HW09.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Vector {
private:
	int size, length;
	int * data, *temp;
	void merge_sort(int l, int r) {
		if (l == r) {//������ұ߽���ȣ���ʾ���������ֱ���˳�
			return;
		}
		int mid = (l + r) / 2; //ȡ�е�
		merge_sort(l, mid); //�ֱ�����������ֵݹ����
		merge_sort(mid + 1, r);
		int x = l, y = mid + 1, loc = l; //x��ʾ��벿��ָ�룬y��ʾ�Ұ벿��ָ�룬loc��ʾ�ܵ�ָ��
		while (x <= mid || y <= r) {//��������������һ��û������
			if (x <= mid && (y>r || data[x] <= data[y])) {//����������xû�����꣬��y�Ѿ����꣬������ߵ�ֵ�������ұߵ�ֵ
				temp[loc] = data[x];//��x������������ɵ�����
				x++;
			}
			else {//�෴���y���ȥ
				temp[loc] = data[y];
				y++;
			}
			loc++;
		}
		for (int i = l; i <= r; i++) {
			data[i] = temp[i];//����ԭ������
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

