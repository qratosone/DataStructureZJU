// HW07.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <vector>
#define INF 65536
using namespace std;
class Graph {
private:
	int n;
	vector<vector<int>> matrix;
public:
	Graph(int N) {
		n = N;
		vector<vector<int>>_matrix(n, vector<int>(n, INF));
		matrix = _matrix;
	}
	~Graph() {
		
	}
	void build(int m) {
		int a, b, weight;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b >> weight;
			matrix[a - 1][b - 1] = weight;
			matrix[b - 1][a - 1] = weight;
			//ע�������±��0��ʼ����
		}
	}
	void Floyd() {//Floyd�㷨
		for (int k= 0;k <n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (matrix[i][k]+matrix[k][j]<matrix[i][j])
					{
						matrix[i][j] = matrix[i][k] + matrix[k][j];
						//path[i][j]=k; ������Ҫ���Լ�¼·��
					}
				}
			}
		}
	}
	int findMaxDist(int vertex) {  //�ҵ�����vertex�������������·��
		int maxDist = 0;
		for (int i = 0; i < n; i++)
		{
			if (i!=vertex&&matrix[vertex][i]>maxDist) {//ע�ⲻҪ�����Լ����Լ��ľ���
				maxDist = matrix[vertex][i];
			}
		}
		return maxDist;
	}
};
int main()
{
	int N, M;
	cin >> N >> M;
	Graph graph(N);
	graph.build(M);
	graph.Floyd();
	int animal = 0;
	int miniDist = INF;
	int check = graph.findMaxDist(3);
	for (int i = 0; i < N; i++)
	{
		auto dist = graph.findMaxDist(i);
		//�����Զ��Ƶ�fromCpp_11����Ҳ��װ����23333
		if (dist>=INF)
		{
			cout << 0 << endl;
			return 0;
			//�Զ��˳�������ͨ����
		}
		if (miniDist>dist) //�����ǰ�ҵ��ľ�����С�����miniDist
		{
			animal = i + 1;//���Ǵ�0��ʼ������
			miniDist = dist;
		}
	}
	cout << animal << " " << miniDist << endl;
    return 0;
}

