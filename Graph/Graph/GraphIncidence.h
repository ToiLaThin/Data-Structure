#include<iostream>
using namespace std;

class Graph
{
public:

	int incMatrix[100][100];
	int vertexNum;
	int edgeNum;
	Graph(int);
	~Graph();
	void addEdge(int, int);
	void display();

private:

};

Graph::Graph(int v){
	edgeNum = 0; vertexNum = v;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			this->incMatrix[i][j] = 0;
}
Graph::~Graph(){
	edgeNum = 0; vertexNum = 0;
}
void Graph::addEdge(int u, int v)
{
	edgeNum++;
	this->incMatrix[edgeNum-1][u] = 1;
	this->incMatrix[edgeNum-1][v] = 1;
}
void Graph::display()
{
	for (int i = 0; i < edgeNum; i++)
	{
		cout << "Edge " << i << ": ";
		for (int j = 0; j < vertexNum; j++)
			cout << this->incMatrix[i][j] << " ";
		cout << endl;
	}
}