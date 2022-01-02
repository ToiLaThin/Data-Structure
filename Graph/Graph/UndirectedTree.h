//co bo sung trong so
#include"GraphMatrix.h"

struct Edge
{
	int v1;
	int v2;
	int d;
};

class UndirectedSpanTree
{
	int numE;
	Edge edgeList[100];
	int setMinEdge(Graph &gr, int &vFirst, int &vLast);

public:
	int numV;
	bool *Checked;
	UndirectedSpanTree();
	//chi co spanDFS recursion dung stack se sai
	void SpanDFSre(Graph &gr, int nowV);
	void SpanBFS(Graph &gr, int startV);
	void rePreorder(int nowV);
	void rePostorder(int nowV);
	void reInorder(int nowV);
	void SpanMinPrim(Graph &gr,int startV);
	void resetCheck();
	void display();
};

UndirectedSpanTree::UndirectedSpanTree()
{
	numV = 0;
	numE = 0;
	Checked = new bool[100];
	for (int v = 0; v < 100; v++)
		Checked[v] = false;
}

//not affact checked of the graph argument 
//only affect that of this span tree
//so that we can span many tree from a graph
void UndirectedSpanTree::SpanBFS(Graph &gr, int startV)
{
	Queue<int> qu = Queue<int>(gr.vertexNum);
	qu.enqueue(startV); this->Checked[startV] = true; this->numV++;
	while (!qu.isEmpty())
	{
		int nowV = qu.peek();
		qu.dequeue();
		for (int v = 0; v < gr.vertexNum; v++)
			if (gr.isAdjacent(nowV, v) == 1 && !this->Checked[v])
			{
				qu.enqueue(v);
				this->edgeList[numE].v1 = nowV; this->edgeList[numE].v2 = v;
				this->edgeList[numE].d = gr.Matr[nowV][v];
				this->numE++; this->numV++;
				this->Checked[v] = true;
			}
	}
}

//not affact checked of the graph argument 
//only affect that of this span tree
//so that we can span many tree from a graph
void UndirectedSpanTree::SpanDFSre(Graph &gr, int nowV)
{
	this->numV++;
	this->Checked[nowV] = true;
	for (int v = 0; v < gr.vertexNum; v++)
		if (gr.isAdjacent(nowV, v) && !this->Checked[v])
		{
			this->edgeList[numE].v1 = nowV; this->edgeList[numE].v2 = v;
			this->edgeList[numE].d = gr.Matr[nowV][v];
			this->numE++; 
			this->SpanDFSre(gr, v);
		}
}

void UndirectedSpanTree::rePreorder(int nowV)
{
	Checked[nowV] = true;
	cout << nowV << " ";
	for (int e = 0; e < this->numE; e++)
	{
		if (nowV == edgeList[e].v1)
		{
			if (!Checked[edgeList[e].v2])
				rePreorder(edgeList[e].v2);
		}
		else if (nowV == edgeList[e].v2)
		{
			if (!Checked[edgeList[e].v1])
				rePreorder(edgeList[e].v1);
		}
	}
}

void UndirectedSpanTree::rePostorder(int nowV)
{
	Checked[nowV] = true;
	for (int e = 0; e < this->numE; e++)
	{
		if (nowV == edgeList[e].v1)
		{
			if (!Checked[edgeList[e].v2])
				rePreorder(edgeList[e].v2);
		}
		else if (nowV == edgeList[e].v2)
		{
			if (!Checked[edgeList[e].v1])
				rePreorder(edgeList[e].v1);
		}
	}
	cout << nowV << " ";
}

void UndirectedSpanTree::reInorder(int nowV)
{
	Checked[nowV] = true;
	for (int e = 0; e < this->numE; e++)
	{
		if (nowV == edgeList[e].v1)
		{
			if (!Checked[edgeList[e].v2])
			{
				reInorder(edgeList[e].v2);
				break;
			}
		}
		else if (nowV == edgeList[e].v2)
		{
			if (!Checked[edgeList[e].v1])
			{
				reInorder(edgeList[e].v1);
				break;
			}
		}
	}
	cout << nowV << " ";
	for (int e = 0; e < this->numE; e++)
	{
		if (nowV == edgeList[e].v1)
		{
			if (!Checked[edgeList[e].v2])
				reInorder(edgeList[e].v2);
		}
		else if (nowV == edgeList[e].v2)
		{
			if (!Checked[edgeList[e].v1])
				reInorder(edgeList[e].v1);
		}
	}
}

//vFirst la dinh da duoc xet vLast la dinh chua dc xet
//Ham se thay doi gia tri hai dinh duoc truyen vao
//tra ve do dai canh
int UndirectedSpanTree::setMinEdge(Graph &gr, int &vFirst, int &vLast)
{
	int min = 2000000000;
	for (int v1 = 0; v1 < gr.vertexNum;v1++)
		if (this->Checked[v1])
		{
			for (int v2 = 0; v2 < gr.vertexNum; v2++)
				if (!this->Checked[v2])
					if(min>gr.Matr[v1][v2] && gr.Matr[v1][v2] != 0)
					{
						vFirst = v1; vLast = v2;
						min = gr.Matr[v1][v2];
					}
		}

	return min;
}

void UndirectedSpanTree::SpanMinPrim(Graph &gr,int startV)
{
	this->Checked[startV] = true; this->numV++;
	while (numE < gr.vertexNum - 1)//lay vertexNum-1 canh
	{
		this->numE++;
		edgeList[numE - 1].d = setMinEdge(gr, edgeList[numE - 1].v1, edgeList[numE - 1].v2);
		Checked[edgeList[numE - 1].v2] = true; this->numV++;
	}
}

void UndirectedSpanTree::resetCheck()
{
	for (int v = 0; v < 100; v++)
		this->Checked[v] = false;
}

void UndirectedSpanTree::display()
{
	cout << this->numE << endl;
	for (int e = 0; e < this->numE; e++)
		cout << "(" << edgeList[e].v1 << "," << edgeList[e].v2 << ") = " << edgeList[e].d << endl;
}





