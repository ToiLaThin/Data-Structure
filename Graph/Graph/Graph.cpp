// Graph.cpp : Defines the entry point for the console application.
//
//neu cung include undirected.h va graphmatrix.h thi loi do trong undirected da include graphmatrix.h roi

#include "stdafx.h"
//#include"GraphAdjList.h"
//#include"UndirectedTree.h"
#include"ShortestPathFinder.h"
//#include"GraphIncidence.h"
using namespace std;


int main()
{
	Graph gr(5);
	gr.addEdge(0, 1,5);
	gr.addEdge(0, 2, 12);
	gr.addEdge(1, 2, 6);
	gr.addEdge(1, 3, 7);
	gr.addEdge(2, 3, 18);
	gr.addEdge(2, 4, 21);
	gr.addEdge(3, 4, 32);

	gr.display();

	ShortestPathFinder spFinder = ShortestPathFinder();
	spFinder.findSPDjiktra(gr, 1);
	//dung cho do thi co huong(co the chua canh am)
	spFinder.findSPFordBell(gr, 1);

	spFinder.findSPFloyd(gr);

	//UndirectedSpanTree tr2 = UndirectedSpanTree();
	//tr2.SpanMinPrim(gr, 0);
	//tr2.display();
	//tr2.resetCheck();
	//tr2.reInorder(0);
	//cout << endl;


	//UndirectedSpanTree tr1 = UndirectedSpanTree();
	//tr1.SpanDFSre(gr, 0);
	//tr1.display();
	//tr1.resetCheck();
	////reset check vi khi span check= true roi | reset de co the duyet
	//tr1.rePreorder(0);
	return 0;
}
