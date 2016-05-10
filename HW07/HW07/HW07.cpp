// HW07.cpp : 定义控制台应用程序的入口点。
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
			//注意数组下标从0开始计数
		}
	}
	void Floyd() {//Floyd算法
		for (int k= 0;k <n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (matrix[i][k]+matrix[k][j]<matrix[i][j])
					{
						matrix[i][j] = matrix[i][k] + matrix[k][j];
						//path[i][j]=k; 如有需要可以记录路径
					}
				}
			}
		}
	}
	int findMaxDist(int vertex) {  //找到顶点vertex到其他顶点最长的路径
		int maxDist = 0;
		for (int i = 0; i < n; i++)
		{
			if (i!=vertex&&matrix[vertex][i]>maxDist) {//注意不要计算自己到自己的距离
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
		//类型自动推导fromCpp_11，我也来装个逼23333
		if (dist>=INF)
		{
			cout << 0 << endl;
			return 0;
			//自动退出？非连通集？
		}
		if (miniDist>dist) //如果当前找到的距离最小则更新miniDist
		{
			animal = i + 1;//还是从0开始的问题
			miniDist = dist;
		}
	}
	cout << animal << " " << miniDist << endl;
    return 0;
}

