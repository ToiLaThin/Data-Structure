#pragma once
#include<iostream>
using namespace std;
#define MAX_SIZE 100

template <class T>
class ArrayList
{
private:
	bool isValidIndex(int idx)
	{
		if (idx >= 0 && idx < nItems)
			return true;
		return false;
	}
public:
	T arrItems[MAX_SIZE];//khong duoc delete gi het
	int nItems;
	ArrayList()
	{
		nItems = 0;
	}
	//giai phong vung nho
	~ArrayList(){
		nItems = 0;
	}
	//xuat tung phan tu List
	void print()
	{
		for (int i = 0; i < nItems; i++)
			cout << arrItems[i] << " ";
		cout << endl;
	}
	//them phan tu vao cuoi List
	void addLast(T newItem)
	{
		arrItems[nItems] = newItem;
		nItems++;
	}
	//them phan tu vao dau List
	void addFirst(T newItem)
	{
		nItems++;
		for (int i = nItems - 1; i >= 1; i--)
			arrItems[i] = arrItems[i - 1];
		arrItems[0] = newItem;
	}
	//chen phan tu vao 1 vi tri trong List
	void insert(int pos, T newItem)
	{
		if (isValidIndex(pos))
		{
			nItems++;
			for (int i = nItems - 1; i >= pos + 1; i--)
				arrItems[i] = arrItems[i - 1];
			arrItems[pos] = newItem;
		}
		else
			cout << "Invalid position" << endl;
	}
	//xoa phan tu dau
	void removeFirst()
	{
		for (int i = 0; i < nItems - 1; i++)
			this->arrItems[i] = this->arrItems[i + 1];
		nItems--;
	}
	//xoa phan tu cuoi
	void removeLast()
	{
		nItems--;
	}
	//xoa ptu tai vtri pos
	void del(int pos)
	{
		if (isValidIndex(pos)){
			for (int i = pos; i < nItems - 1; i++)
				this->arrItems[i] = this->arrItems[i + 1];
			nItems--;
		}
	}
	
	//sap xep Selection
	static void SelectionSort(ArrayList<T>& someList)//ArrayList<T> du la class nhung van phai co & thi moi doi ? Co the dieu nay chi dung voi C++
	{
		for (int i = 0; i < someList.nItems - 1; i++)
			for (int j = i + 1; j < someList.nItems; j++)
				if (someList.arrItems[i]>someList.arrItems[j])
				{
					int temp = someList.arrItems[i];
					someList.arrItems[i] = someList.arrItems[j];
					someList.arrItems[j] = temp;
				}
	}
	//copy 1 list khac
	static ArrayList<T>& copy(ArrayList<T> someList)
	{
		//tra ve arrayList<T> duoc
		//nhung khong the return this duoc vi la con tro const
		return someList;
	}
	template <class T>
	static ArrayList<T>& combine(const ArrayList<T> li1, const ArrayList<T> li2)
	{
		//cu phap nhu sau van duoc ArrayList<T> li = ArrayList();
		ArrayList<T> li = ArrayList<T>();
		int idx = 0;
		for (int i = 0; i < li1.nItems; i++)
			li.arrItems[idx++] = li1.arrItems[i];
		for (int j = 0; j < li2.nItems; j++)
			li.arrItems[idx++] = li2.arrItems[j];
		li.nItems = li1.nItems + li2.nItems;
		return li;
	}
	template <class T>
	static ArrayList<T>& reverse(const ArrayList<T> li1)
	{
		//cu phap nhu sau van duoc ArrayList<T> li = ArrayList();
		ArrayList<T> li2 = ArrayList<T>();
		int idx = 0;
		for (int i = li1.nItems - 1; i >= 0; i--)
			li2.arrItems[idx++] = li1.arrItems[i];
		li2.nItems = idx;
		return li2;
	}

	//ko can template<class T>
	T operator [](int idx)
	{
		if (isValidIndex(idx))
			return arrItems[idx];
	}
};

