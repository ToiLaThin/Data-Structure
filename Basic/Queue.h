#pragma once
#include<iostream>
#include"ArrayList.h"
using namespace std;

//MACROS duoc define o file khac van co hieu qua o file nay
template<class T>
class Queue
{
	ArrayList<T> items;
	int capacity;
public:
	//khoi tao khong tham so 
	Queue(int size=MAX_SIZE);//default la cap phat MAX_SIZE neu khong
	//phuong thuc huy
	~Queue();
	//kiem tra con phan tu trong Queue
	bool isEmpty();
	//kiem tra Queue co vuot qua gioi han khong
	bool isFull();
	//them vao Queue theo FIFO
	void enqueue(T);
	//tra ve gia tri phan tu top va loai ra khoi Queue
	T dequeue();
	//tra ve gia tri phan tu top
	T peek();
	//hien thi cac phan tu cua Queue
	void display();
	//reset lai
	void clear();
	//tra ve kich thuoc hien hanh cua Queue
	int nowSize();

};

template<class T>
Queue<T>::Queue(int sz){
	items = ArrayList<T>();
	capacity = sz;
}

template<class T>
Queue<T>::~Queue(){
	items.~ArrayList<T>();
	capacity = 0;
}

template<class T>
bool Queue<T>::isEmpty(){
	if (items.nItems==0)
	{
		cout << "Queue Underflow!!!" << endl;
		return true;
	}
	return (items.nItems == 0);
}

template<class T>
bool Queue<T>::isFull(){
	if (items.nItems == capacity){
		cout << "Queue Overflow!!!" << endl;
		return true;
	}
	return false;
}

template<class T>
void Queue<T>::enqueue(T newItem)
{
	if (!isFull())
		items.addLast(newItem);
}

template<class T>
T Queue<T>::dequeue(){
	if (!isEmpty()){
		T temp = items[0];
		items.removeFirst();
		return temp;
	}
}

template<class T>
T Queue<T>::peek(){
	if (!isEmpty())
		return items[0];
}

template<class T>
void Queue<T>::display(){
	if (!isEmpty()){
		items.print();
		cout << endl;
	}
}

template<class T>
void Queue<T>::clear(){
	//items.~ArrayList<T>();
	//items = ArrayList<T>(capacity);
}

template<class T>
int Queue<T>::nowSize(){
	return items.nItems;
}