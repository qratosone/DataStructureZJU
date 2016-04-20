// HW6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Graph {
private:
	int n;
	bool *visited;
	vector<int> *edges;
public:
	Graph(int N) {
		n = N;
		visited = new bool[N];
		edges = new vector<int>[N];
		memset(visited, 0, N);
	}
	~Graph() {
		delete[] visited;
		delete[] edges;
	}
	void insert(int a, int b) {
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	void DFS(int n) {
		cout << n << " ";
		visited[n] = true;
		sort(edges[n].begin(), edges[n].end());
		for (int vertex:edges[n])
		{
			if (!visited[vertex])
			{
				DFS(vertex);
			}
		}
	}
	void DFSprint(int n) {
		cout << "{ ";
		DFS(n);
		cout << "}" << endl;
	}
	void DFSsearch() {
		
		DFSprint(0);
		for (int i = 0; i <n ; i++)
		{
			if (!visited[i])
			{
				DFSprint(i);
			}
		}
	}
	void BFSprint(int n) {
		cout << "{ ";
		BFS(n);
		cout << "}" << endl;
	}
	void BFSsearch() {
		BFSprint(0);
		for (int i = 0; i <n; i++)
		{
			if (!visited[i])
			{
				BFSprint(i);
			}
		}
	}
	void visit_reset() {
		memset(visited, 0, n);
	}
	void BFS(int n) {
		queue<int>q;
		q.push(n);
		while (!q.empty())
		{
			int vertex = q.front();
			q.pop();
			cout << vertex << " ";
			visited[vertex] = true;
			sort(edges[vertex].begin(), edges[vertex].end());
			for (int v:edges[vertex])
			{
				if (!visited[v])
				{
					visited[v] = true;
					q.push(v);
				}		
			}
		}
	}
};

int main()
{
	int N, M;
	cin >> N >> M;
	Graph graph(N);
	int x, y;
	for (int i = 0; i < M; i++)
	{
		cin >> x >> y;
		graph.insert(x, y);
	}
	graph.DFSsearch();
	graph.visit_reset();
	graph.BFSsearch();
    return 0;
}

