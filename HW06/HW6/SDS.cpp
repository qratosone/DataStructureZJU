#include"stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
class Graph {
private:
	int n;
	bool* visited;
	vector<int>* edges;
public:
	Graph(int num) {
		n = num;
		visited = new bool[n+1];
		memset(visited, 0, n+1);
		edges = new vector<int>[n+1];
	}
	~Graph() {
		delete[] visited;
		delete[] edges;
	}
	void insert(int x, int y) {
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	int BFS(int vertex) {
		int count = 1;
		int *level = new int[n + 1];
		level[vertex] = 0;
		visited[vertex] = true;
		queue<int>q;
		q.push(vertex);
		while (!q.empty())
		{
			int top = q.front();	
			for (int adj_vertex : edges[top]) {
				if (!visited[adj_vertex]) {
					visited[adj_vertex] = true;
					level[adj_vertex] = level[top] + 1;
					count++;
					q.push(adj_vertex);
				}
			}	
			if (level[top]+1==6)
			{
				break;
			}
			q.pop();
		}
		delete[] level;
		return count;
	}
	int BFS2(int vertex) {
		int level = 0, last = vertex, tail;//last为最后访问的节点，初始为第一个节点
		queue<int>q;    //tail为这一层的尾节点
		q.push(vertex);
		int count = 1;
		visited[vertex] = true;
		while (!q.empty())
		{
			int top = q.front();
			q.pop();
			for (int adj_vertex : edges[top]) {
				if (!visited[adj_vertex])
				{
					q.push(adj_vertex);
					count++;
					tail = adj_vertex;
					visited[adj_vertex] = true;
				}
			}
			if (top == last) { //top等于last即意味着这一层扫完了
				last = tail;//用当前找到的最末端节点更新之
				level++;//加一层
			}
			if (level==6)
			{
				break;
			}
		}
		return count;
	}
	void SDS() {
		int count;
		for (int i =1; i <= n; i++)
		{
			count = BFS2(i);
			printf("%d: %.2f%%\n", i, 100.0 * count / n);
			memset(visited, 0, n + 1);
		}
	}
};
int main() {
	int n, m;
	cin >> n >> m;
	Graph g(n);
	int x, y;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		g.insert(x, y);
	}
	g.SDS();
	return 0;
}