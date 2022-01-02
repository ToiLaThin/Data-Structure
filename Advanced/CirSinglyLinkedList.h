#pragma once
#include<iostream>
#include"Node.h"
using namespace std;

template<class T>
class CirSinglyLinkedList
{
public:
	//ko co head vi khien cho cac method phuc tap hon
	Node<T>* tail;
	CirSinglyLinkedList();
	//~CirSinglyLinkedList();
	void addFirst(T data);
	void addLast(T data);
	void delFirst();
	void delLast();
	void delInterByIdx(int pos);
	void delInterByData(T data);
	void printList();
	T operator[](int idx);
	int Length();
};

template<class T>
CirSinglyLinkedList<T>::CirSinglyLinkedList()
{
	this->tail = nullptr;
}

template<class T>
void CirSinglyLinkedList<T>::addFirst(T data)
{
	if (this->tail == nullptr)
	{
		Node<T>* newNode = new Node<T>(data);
		this->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		Node<T>* newNode = new Node<T>(data);
		newNode->next = this->tail->next;
		this->tail->next = newNode;
	}
}

template<class T>
void CirSinglyLinkedList<T>::addLast(T data)
{
	if (this->tail == nullptr)
	{
		Node<T>* newNode = new Node<T>(data);
		this->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		Node<T>* newNode = new Node<T>(data);
		newNode->next = this->tail->next;
		this->tail->next = newNode;
		this->tail = newNode;
	}
}

template<class T>
void CirSinglyLinkedList<T>::delFirst()
{
	//ko co phan tu
	if (this->Length() == 0)
		return;
	// th khac nhung phai xet cho tuong hop co 1 phan tu cho this->tail = nullptr
	if (this->Length() == 1)
	{
		free(this->tail);
		this->tail = nullptr;
	}
	else
	{
		Node<T>* head = this->tail->next;
		this->tail->next = head->next;
		delete head;
	}
}

template<class T>
void CirSinglyLinkedList<T>::delLast()
{
	//ko co phan tu
	if (this->Length() == 0)
		return;

	//th khac nhung phai xet cho tuong hop co 1 phan tu cho this->tail=nullptr
	if (this->Length() == 1)
	{
		free(this->tail);
		this->tail = nullptr;
	}
	else
	{
		Node<T>* newTail = this->tail->next;
		while (newTail->next != this->tail)
			newTail = newTail->next;
		newTail->next = this->tail->next;
		free(this->tail);
		this->tail = newTail;
	}
}

template<class T>
void CirSinglyLinkedList<T>::delInterByIdx(int idx)
{
	if (idx >= 0 && idx <= this->Length() - 1)
	{
		if (idx == 0)
			this->delFirst();
		else if (idx == this->Length() - 1)
			this->delLast();
		else
		{
			//O(n)
			int tempPos = 0;
			Node<T>* tempNode = this->tail->next;
			while (tempPos < idx - 1)//den idx-1
			{
				tempNode = tempNode->next;
				tempPos++;
			}

			Node<T>* delNode = tempNode->next;
			tempNode->next = delNode->next;
			free(delNode);
			delNode = nullptr;
		}
	}
}

template<class T>
void CirSinglyLinkedList<T>::delInterByData(T data)
{
	Node<T>* tempNode = this->tail->next;
	if (tempNode->data == data)
		this->delFirst();
	else if (this->tail->data == data)
		this->delLast();
	else
	{
		//tim va xoa 
		while (tempNode->next->data != data && tempNode != this->tail)
			tempNode = tempNode->next;
		if (tempNode == this->tail)
			return;

		//xoa
		Node<T>* delNode = tempNode->next;
		tempNode->next = delNode->next;
		free(delNode);
		delNode = nullptr;
	}
}

template<class T>
void CirSinglyLinkedList<T>::printList()
{
	//la head
	if (this->Length() == 0)
		return;
	Node<T>* head = this->tail->next;
	Node<T>* temp = head;
	do{
		cout << temp->data << " ";
		temp = temp->next;
	} while (temp != head);
}

template<class T>
int CirSinglyLinkedList<T>::Length()
{
	if (this->tail == nullptr)
		return 0;
	else
	{
		Node<T>* temp = this->tail->next;
		int count = 1;
		while (temp != this->tail)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}
}

template<class T>
T CirSinglyLinkedList<T>::operator[](int idx)
{
	if (idx >= 0 && idx < Length())
	{
		Node<T>* head = this->tail->next;
		Node<T>* temp = head;
		int count = 0;
		while (count != idx)
		{
			temp = temp->next;
			count++;
		}
		return temp->data;
	}
	else
		return NULL;
}
