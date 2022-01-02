#pragma once
#include"LinkedList.h"
#include<vector>
#include<iostream>
using namespace std;

class Graph
{
private:
	int vertexNum;
	vector<LinkedList<int>> adjLst;
public:
	Graph(int);
	~Graph();
	void addEdge(int, int);
	void display();
	bool isAdjacent(int, int);
	

};

Graph::Graph(int v)
{
	vertexNum = v;
	adjLst.resize(vertexNum);
	cout << adjLst.size();
	for (int i = 0; i < vertexNum; i++)
	{
		LinkedList<int> temp = LinkedList<int>();
		adjLst.push_back(temp);
	}
}

Graph::~Graph(){
	for (int i = 0; i < vertexNum; i++)
		adjLst[i].~LinkedList();
	vertexNum = 0;
	adjLst.resize(vertexNum);
	//hoac khong can for chi can resize(0) la dc
}

void Graph::addEdge(int src, int dest)
{
	adjLst[src].addFirst(dest);
	adjLst[dest].addFirst(src);
}

void Graph::display()
{
	int v;
	for (v = 0; v < vertexNum; ++v)
	{
		cout << "\n Adjacency list of vertex " << v << "\n head ";
		adjLst[v].printList();
	}
}

bool Graph::isAdjacent(int u, int v)
{
}


