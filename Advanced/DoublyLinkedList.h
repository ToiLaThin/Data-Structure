#pragma once
/*original idea: https://www.geeksforgeeks.org/delete-a-node-in-a-doubly-linked-list/ 
                                                                                      */
#include<iostream>
using namespace std;

template<class T>
class Node
{
public:
	T data;
	Node* prev;
	Node* next;
	Node()
	{
		this->data = NULL;
		this->next = NULL;
		this->prev = NULL;
	}
	Node(T dat)
	{
		this->data = dat;
		this->next = NULL;
		this->prev = NULL;
	}
};

template<class T>
class DoublyLinkedList
{
public:
	Node<T>* head;
	Node<T>* tail;

	DoublyLinkedList();
	
	void addFirst(T data);
	void addLast(T data);
	void delFirst();
	void delLast();
	void delNode(Node<T>* del);
	void delAt(int idx);
	int count();
	void displayForward();
	void displayReverse();
};

template<class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	this->head = NULL;
	this->tail = NULL;
}

template<class T>
void DoublyLinkedList<T>::addFirst(T data)
{
	Node<T>* newNode = new Node<T>(data);
	if (this->head == NULL && this->tail == NULL)
	{
		this->head = newNode;
		this->tail = newNode;
	}
	else
	{
		this->head->prev = newNode;
		newNode->next = this->head;
		this->head = newNode;
	}
}

template<class T>
void DoublyLinkedList<T>::addLast(T data)
{
	Node<T>* newNode = new Node<T>(data);
	if (this->head == NULL && this->tail == NULL)
	{
		this->head = newNode;
		this->tail = newNode;
	}
	else
	{
		newNode->prev = this->tail;//neu co 1 phan tu thi newNode se tro den head luon
		this->tail->next = newNode;
		this->tail = newNode;
	}
}

template<class T>
void DoublyLinkedList<T>::delFirst()
{
	if (this->head == NULL && this->tail == NULL)//0
		return;
	else if (this->head == this->tail)//1 element
	{
		delete this->head;//xoa cac pointee cua ca tail(vi head==tail)
		this->head = NULL;
		this->tail = NULL;
	}
	else
	{
		//DOI
		Node<T>* delNode = this->head;
		this->head = this->head->next;
		this->head->prev = NULL;

		//XOA 
		delete delNode;
		delNode = NULL;
	}
}

template<class T>
void DoublyLinkedList<T>::delLast()
{
	if (this->head == NULL && this->tail == NULL)//0
		return;
	else if (this->head == this->tail)//1 element
	{
		delete this->head;//xoa cac pointee cua ca tail(vi head==tail)
		this->head = NULL;
		this->tail = NULL;
	}
	else
	{
		//DOI
		Node<T>* delNode = this->tail;
		this->tail = this->tail->prev;
		this->tail->next = NULL;

		//XOA 
		delete delNode;
		delNode = NULL;
	}
}

template<class T>
//when you use this you have to make sure the del is inside the DLL
void DoublyLinkedList<T>::delNode(Node<T>* del)
{
	if (del == NULL)
		return;
	else if (del == this->head)
		this->delFirst();
	else if (del == this->tail)
		this->delLast();
	else
	{
		del->prev->next = del->next;
		del->next->prev = del->prev;
		delete del;
		del = NULL;
	}
}

template<class T>
void DoublyLinkedList<T>::delAt(int idx)
{
	//co the di tu tail
	if (idx < 0)
		return;
	int count = 0; Node<T>* temp = this->head;
	while (count < idx)
	{
		temp = temp->next;
		count++;

	}
	delNode(temp);
	//delNode ne de private
}

template<class T>
int DoublyLinkedList<T>::count()
{
	int dem = 0; Node<T>* temp = this->head; 
	while (temp != NULL)
	{
		temp = temp->next;
		dem++;
	}
	return dem;
}

template<class T>
void DoublyLinkedList<T>::displayForward()
{
	Node<T>* temp = this->head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

template<class T>
void DoublyLinkedList<T>::displayReverse()
{
	Node<T>* temp = this->tail;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->prev;
	}
	cout << endl;
}

