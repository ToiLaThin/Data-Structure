// B-Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<math.h>
#define ORDER 4
using namespace std;

struct NodeBTr
{
	int nKeys;//so luong key trong Node hien tai o thoi diem hien tai| maximum la ORDER-1
	int arrKey[ORDER];
	bool isLeaf;
	NodeBTr* arrChild[ORDER+1];//so luong child trong Node hien tai o thoi diem hien tai la nKeys+1
} *root;//dinh nghia bien toan cuc root kieu NodeBTr

typedef struct NodeBTr* BTree;
NodeBTr* init(NodeBTr* &node)
{
	node = new NodeBTr();
	node->isLeaf = true;
	node->nKeys = 0;
	return node;
}

void sort(int arrKey[],int n)
{
	for (int i = 0; i < n-1; i++)
		for (int j = i + 1; j < n;j++)
			if (arrKey[i] > arrKey[j])
			{
				int temp = arrKey[i];
				arrKey[i] = arrKey[j];
				arrKey[j] = temp;
			}
}

void travesal(NodeBTr* root)
{
	if (root == NULL || root->nKeys == 0)
		return;
	for (int i = 0; i < root->nKeys; i++)
	{
		travesal(root->arrChild[i]);
		cout << root->arrKey[i] << " ";
	}
	travesal(root->arrChild[root->nKeys]);
}

void splitChild(NodeBTr*& parent, int pos, NodeBTr* &child)
{
	NodeBTr* newChild; init(newChild); newChild->isLeaf = child->isLeaf; //newChild chua values lon(ben trai)
	int mid, nleft, nright;
	//xac dinh index phan tu day len dua vao ORDER
	if ((ORDER - 1) % 2 == 1){
		mid = (ORDER - 1) / 2;
		nright = (ORDER - 1) / 2;
		nleft = nright;

		//copy cac key
		newChild->nKeys = nright;
		for (int i = 0; i < newChild->nKeys; i++)
			newChild->arrKey[i] = child->arrKey[mid + 1 + i];//bo phan tu mid=>chay tu mid + 1
		//copy cac child cua node child
		for (int i = 0; i <= newChild->nKeys; i++)
			newChild->arrChild[i] = child->arrChild[mid + 1 + i];

		//cap nhat child
		child->nKeys = nleft;

		//cap nhat parent
		parent->nKeys++;
		for (int i = parent->nKeys; i > pos + 1; i--)
			parent->arrChild[i] = parent->arrChild[i - 1];
		parent->arrChild[pos + 1] = newChild;//pos la vi tri cua child bi split trong parent

		//doi cac key cua parent ve phai
		for (int i = parent->nKeys - 1; i > pos; i--)
			parent->arrKey[i] = parent->arrKey[i - 1];
		//cap nhat key cua parent tai pos
		//luu y child -> nKeys chinh la mid=(ORDER-1)/2 
		//index cua child sau khi split la 0->(ORDER-1)/2-1
		parent->arrKey[pos] = child->arrKey[mid];
	}
	else{
		mid = (ORDER - 1) / 2 - 1;
		nright= (ORDER - 1) / 2;
		nleft = nright - 1;

		//copy cac key
		newChild->nKeys = nright;
		for (int i = 0; i < newChild->nKeys; i++)
			newChild->arrKey[i] = child->arrKey[mid + 1 + i];//bo phan tu mid=> chay tu mid+1

		//copy cac child cua node child
		for (int i = 0; i <= newChild->nKeys; i++)//<=nKeys vi so con =so key+1
			newChild->arrChild[i] = child->arrChild[mid + 1 + i];

		//cap nhat child
		child->nKeys = nleft;

		//cap nhat parent
		parent->nKeys++;
		for (int i = parent->nKeys; i > pos + 1; i--)
			parent->arrChild[i] = parent->arrChild[i - 1];
		parent->arrChild[pos + 1] = newChild;//pos la vi tri cua child bi split trong parent

		//doi cac key cua parent ve phai
		for (int i = parent->nKeys - 1; i > pos; i--)
			parent->arrKey[i] = parent->arrKey[i - 1];
		//cap nhat key cua parent tai pos
		//luu y child -> nKeys chinh la mid=(ORDER-1)/2 
		//index cua child sau khi split la 0->(ORDER-1)/2-1
		parent->arrKey[pos] = child->arrKey[mid];
	}
}

//tra ve vi tri se chen
int getPosToIns(int val, int arrKey[], int nKeys)
{
	int i;
	for (i = 0; i < nKeys; i++)
		if (val < arrKey[i])
			return i;
	return i;//vi tri cuoi mang
}

//ham de quy dam bao chen phan tu vao nut la khi no chua day
void insertLeafRe(NodeBTr* &node, int val)
{
	int pos = getPosToIns(val, node->arrKey, node->nKeys);
	if (node->isLeaf)//neu la leaf thi chac chan chua day
	{
		for (int i = node->nKeys; i > pos; i--)
			node->arrKey[i] = node->arrKey[i - 1];
		//chen va doi so key
		node->arrKey[pos] = val;
		node->nKeys++;
	}
	else if (!node->isLeaf)
	{
		if (node->arrChild[pos]->nKeys == ORDER - 1)
		{
			splitChild(node, pos, node->arrChild[pos]);
			if (val < node->arrKey[pos])//cap nhat vi tri pos sau khi co nut moi 
				pos = pos;
			else
				pos = pos + 1;
		}
		insertLeafRe(node->arrChild[pos], val);
	}
}

void insert(int val)
{
	if (root == NULL)
	{
		init(root);
		root->nKeys = 1;
		root->arrKey[0] = val;
	}
	else if (root->nKeys == ORDER - 1)
	{
		//neu day nut tao nut moi lam parent  va split nut hien tai
		NodeBTr* temp = NULL; init(temp); temp->arrChild[0] = root;
		splitChild(temp, 0, temp->arrChild[0]);

		//cap nhat nut goc nam tren nut goc cu va khong con la la
		root = temp; root->isLeaf = false;
		if (val <= temp->arrKey[0])
			insertLeafRe(root->arrChild[0], val);
		else
			insertLeafRe(root->arrChild[1], val);
	}
	else
		insertLeafRe(root, val);
}

bool search(NodeBTr* node,int val)
{
	//TH la nut leaf
	if (node->isLeaf)
	{
		for (int i = 0; i < node->nKeys; i++)
		{
			if (val == node->arrKey[i])
				return true;
			else if (val < node->arrKey[i])//vi la leaf nen ko con child de search trong child nen ko tim thay
				return false;
		}
		//da kiem tra het key ma ko tim thay
		return false;
	}
	//TH la nut internal
	for (int i = 0; i < node->nKeys; i++)
	{
		if (val == node->arrKey[i])
			return true;

		//di xuong child[i] de  search vi: node->arrKey[i-1]< val <node->arrKey[i]
		else if (val < node->arrKey[i])
			return search(node->arrChild[i], val);
	}
	//di vao child cuoi de search
	return search(node->arrChild[node->nKeys], val);
}
int main() 
{
	insert(4);
	insert(3);
	insert(100);
	insert(52);
	insert(75);
	insert(12);
	insert(54);
	travesal(root);
	cout << endl;
	if (search(root, 12945) == true)
		cout << "Found !!! " << endl;
	else
		cout << "Not Found !!!" << endl;
}

