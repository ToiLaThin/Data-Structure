//co bo sung trong so
#include<iostream>
#include"Queue.h"
#include"Stack.h"
using namespace std;

class Graph
{
public:

	int Matr[100][100];
	int vertexNum;
	bool *Checked;
	Graph();
	Graph(int);
	~Graph();
	void addEdge(int, int,int);
	bool isAdjacent(int V, int v);
	int degreeOf(int V);
	void display();

private:

};

Graph::Graph(){
	vertexNum = 0;
	Checked = new bool[100];
	for (int v = 0; v < 100; v++)
		Checked[v] = false;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			Matr[i][j] = 0;
}
Graph::Graph(int v)
{
	vertexNum = v;
	Checked = new bool[vertexNum];
	for (int v = 0; v < vertexNum; v++)
		Checked[v] = false;
	for (int i = 0; i < vertexNum;i++)
		for (int j = 0; j < vertexNum; j++)
			Matr[i][j] = 0;
}
Graph::~Graph(){
	vertexNum = 0;
	delete(Checked);
}
void Graph::addEdge(int u, int v,int d)
{
	this->Matr[u][v] = d;
	this->Matr[v][u] = d;
}
bool Graph::isAdjacent(int V, int v)
{
	return this->Matr[V][v] != 0;
}
int Graph::degreeOf(int V)
{
	int deg = 0;
	for (int v = 0; v < this->vertexNum; v++)
		if (this->isAdjacent(V, v))
			deg++;
	return deg;
}
void Graph::display()
{
	for (int i = 0; i < vertexNum; i++)
	{
		for (int j = 0; j < vertexNum; j++)
			cout << this->Matr[i][j] << " ";
		cout << endl;
	}
}

void reDFS(Graph &gr,int nowV)//phai tham chieu
{
	gr.Checked[nowV] = true;
	cout << nowV << " ";
	for (int v = 0; v < gr.vertexNum; v++)
		if (gr.isAdjacent(nowV,v) && !gr.Checked[v])
			reDFS(gr, v);
}
void BFS(Graph &gr, int startV)
{
	cout << endl;
	Queue<int> qu = Queue<int>(gr.vertexNum);
	qu.enqueue(startV); gr.Checked[startV] = true;
	while (!qu.isEmpty())
	{
		int nowV = qu.peek();
		cout << nowV << " ";
		qu.dequeue();
		for (int v = 0; v < gr.vertexNum; v++)
			if (gr.isAdjacent(nowV,v) == 1 && !gr.Checked[v])
			{
				qu.enqueue(v);
				gr.Checked[v] = true;
			}
	}
}
void DFS(Graph &gr, int startV)
{
	cout << endl;
	Stack<int, 100>  st = Stack<int, 100>();
	st.push(startV); gr.Checked[startV] = true;
	while (!st.isEmpty())
	{
		int nowV = st.peek();
		cout << nowV << " ";
		st.pop();
		for (int v = 0; v < gr.vertexNum; v++)
			if (gr.isAdjacent(nowV,v) && !gr.Checked[v])
			{
				st.push(v);
				gr.Checked[v] = true;
			}
	}
}
