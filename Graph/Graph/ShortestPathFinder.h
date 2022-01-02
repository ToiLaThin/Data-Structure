#include"UndirectedTree.h"


class DjiktraEntry
{
public:
	int minD;
	int preVer;
	bool checked;
	DjiktraEntry()
	{
		minD = 2000;
		preVer = NULL;
		checked = false;
	}
};

class FordBellmanEntry
{
public:
	int minD;
	int preVer;
	FordBellmanEntry()
	{
		this->preVer = NULL;
		this->minD = 2000;
	}
};

class FloydEntry
{
public:
	int minD;
	int preVer;
	FloydEntry()
	{
		this->preVer = NULL;
		this->minD = 2000;
	}
};

class ShortestPathFinder
{
public:
	ShortestPathFinder();
	void findSPDjiktra(Graph &gr,int startV);
	void findSPFordBell(Graph &gr, int startV); 
	void findSPFloyd(Graph &gr);
private:
	DjiktraEntry *djik;
	FordBellmanEntry *ford;
	FloydEntry floyd[100][100];
	int numV;

	int UncheckedVerMinD();
	bool AllVerChecked();
	void doDjiktraAlgo(Graph &gr,int startV);
	void printDjiktra(int);

	void doFordBellAlgo(Graph &gr, int startV);
	void printFordBell(int);

	void doFloydAlgo(Graph &gr);
	void printFloyd();


};

ShortestPathFinder::ShortestPathFinder()
{
	this->numV = 0;
	this->djik = nullptr;
	this->ford = nullptr;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			this->floyd[i][j] = FloydEntry();
}

int ShortestPathFinder::UncheckedVerMinD()
{
	int min = 2000, result = NULL;
	for (int v = 0; v < numV; v++)
	{
		if (!djik[v].checked)
			if (djik[v].minD < min)
			{
				min = djik[v].minD;
				result = v;
			}
	}
	return result;;
		
}

bool ShortestPathFinder::AllVerChecked()
{
	for (int v = 0; v < this->numV; v++)
		if (!this->djik[v].checked)
			return false;
	return true;
}

void ShortestPathFinder::doDjiktraAlgo(Graph &gr, int startV)
{
	
	this->djik[startV].minD = 0;

	while (!AllVerChecked())
	{
		int x = UncheckedVerMinD();
		this->djik[x].checked = true;
		for (int v = 0; v < this->numV; v++)
		{
			if (gr.isAdjacent(x, v) && !djik[v].checked)
				if (djik[v].minD>djik[x].minD + gr.Matr[x][v])
				{
					djik[v].minD = djik[x].minD + gr.Matr[x][v];
					djik[v].preVer = x;
				}
		}
	}
}

void ShortestPathFinder::printDjiktra(int startV)
{
	for (int v = 0; v < this->numV; v++)
		cout << "SP from " << startV << " to " << v << " : (" << djik[v].minD << "," << djik[v].preVer << ")" << endl;
	cout << endl;
}

void ShortestPathFinder::findSPDjiktra(Graph &gr, int startV)
{
	this->numV = gr.vertexNum;
	this->djik = new DjiktraEntry[this->numV]();
	this->doDjiktraAlgo(gr, startV);
	this->printDjiktra(startV);
}

void ShortestPathFinder::doFordBellAlgo(Graph &gr, int startV)
{
	this->ford[startV].minD = 0;
	for (int nowV = 0; nowV < this->numV; nowV++)
		for (int v = 0; v < this->numV; v++)
		{
			if (gr.Matr[nowV][v] != 0 && nowV != v)//ke va nowV != v
				if (this->ford[v].minD>this->ford[nowV].minD + gr.Matr[nowV][v])
				{
					this->ford[v].minD = this->ford[nowV].minD + gr.Matr[nowV][v];
					this->ford[v].preVer = nowV;
				}
		}
}

void ShortestPathFinder::printFordBell(int startV)
{
	for (int v = 0; v < this->numV; v++)
		cout << "SP from " << startV << " to " << v << " : (" << ford[v].minD << "," << ford[v].preVer << ")" << endl;
	cout << endl;
}

void ShortestPathFinder::findSPFordBell(Graph &gr, int startV)
{
	this->numV = gr.vertexNum;
	this->ford = new FordBellmanEntry[this->numV]();
	this->doFordBellAlgo(gr, startV);
	this->printFordBell(startV);
}

void ShortestPathFinder::doFloydAlgo(Graph &gr)
{
	for (int i = 0; i < this->numV; i++)
	{
		this->floyd[i][i].minD = 0;
		for (int j = 0; j < this->numV; j++)
		{
			if (gr.Matr[i][j] != 0)
				this->floyd[i][j].minD = gr.Matr[i][j];
			if (j != i)
				this->floyd[i][j].preVer = i;
		}
	}

	for (int u = 0; u < this->numV; u++)
		for (int v = 0; v < this->numV; v++)
			for (int k = 0; k <this->numV; k++)
				if (this->floyd[u][v].minD > this->floyd[u][k].minD + this->floyd[k][v].minD)
				{
					this->floyd[u][v].minD = this->floyd[u][k].minD + this->floyd[k][v].minD;
					this->floyd[u][v].preVer = this->floyd[k][v].preVer;// tai sao ko phai la k
				}


}

void ShortestPathFinder::printFloyd()
{
	for (int startV = 0; startV < this->numV; startV++)
	{
		cout << endl;
		for (int finishV = 0; finishV < this->numV; finishV++)
			cout << "(" << this->floyd[startV][finishV].minD << "," << this->floyd[startV][finishV].preVer << ")  ";
	}
	cout << endl;

}

void ShortestPathFinder::findSPFloyd(Graph &gr)
{
	this->numV = gr.vertexNum;
	this->doFloydAlgo(gr);
	this->printFloyd();
}

