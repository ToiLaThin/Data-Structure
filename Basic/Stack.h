#pragma once
#include<iostream>
#include"LinkedList.h"
using namespace std;

template<class T,int SIZE>
class Stack
{
	LinkedList<T> items;
	int capacity=SIZE;
public:	
	//khoi tao khong tham so 
	Stack();
	//phuong thuc huy
	~Stack();
	//kiem tra con phan tu trong STACK
	bool isEmpty();
	//kiem tra stack co vuot qua gioi han khong
	bool isFull();
	//them vao stack theo FIFO
	void push(T);
	//tra ve gia tri phan tu top va loai ra khoi STACK
	T pop();
	//tra ve gia tri phan tu top
	T peek();
	//hien thi cac phan tu cua STACK
	void display();
	//reset lai
	void clear();
	//tra ve kich thuoc hien hanh cua STACK
	int nowSize();

};

template<class T, int SIZE>
Stack<T,SIZE>::Stack(){
	capacity = SIZE;
	items = LinkedList<T>();
}

template<class T, int SIZE>
Stack<T,SIZE>::~Stack(){
	//neu la dynamic memery thi moi delete
	//con static(Ex mang int static) delete bi loi
	capacity = 0;
	items.~LinkedList<T>();
}

template<class T, int SIZE>
bool Stack<T,SIZE>::isEmpty(){
	if (items.length()==0)
	{
		cout << "Stack Underflow!!!" << endl;
		return true;
	}
	return (items.length() == 0);
}

template<class T, int SIZE>
bool Stack<T, SIZE>::isFull(){
	if (items.length() == capacity){
		cout << "Stack Overflow!!!" << endl;
		return true;
	}
	return false;
}

template<class T, int SIZE>
void Stack<T, SIZE>::push(T newItem)
{
	if (!isFull())
		items.addFirst(newItem);
}

template<class T, int SIZE>
T Stack<T, SIZE>::pop(){
	if (!isEmpty()){
		T temp = items[0];
		items.delBeg();
		return temp;
	}
}

template<class T, int SIZE>
T Stack<T, SIZE>::peek(){
	if (!isEmpty())
		return items[0];
}

template<class T, int SIZE>
void Stack<T, SIZE>::display(){
	if (!isEmpty())
		items.printList();
}

template<class T, int SIZE>
void Stack<T, SIZE>::clear(){
	capacity = 0;
	items.~LinkedList<T>();
	items = LinkedList<T>();
}

template<class T,int SIZE>
int Stack<T, SIZE>::nowSize(){
	return items.length();
}