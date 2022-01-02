#pragma once
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include"Node.h"
template<class T>
class LinkedList
{
	Node<T>* head;
	//phai viet nhu vay
	Node<T>* tail;
	void swap(T& a, T&b){
		T temp = a;
		a = b;
		b = temp;
	}
public:
	LinkedList(){
		head = NULL;
		tail = NULL;
	}
	~LinkedList()
	{
		Node<T> *temp;
		while (head != NULL){
			temp = head;
			head = head->next;
			delete(temp);
		}
	}
	//them phan tu vao dau LinkedList
	void addFirst(T val)
	{
		//phai la new Node<T>()
		Node<T>* newNode = new Node<T>(val);
		if (head == NULL){
			head = tail = newNode;
			return;
		}
		newNode->next = head;
		head = newNode;
	}
	//them phan tu vao cuoi LinkedList
	void addLast(T val)
	{
		//phai la new Node<T>()
		Node<T>* newNode = new Node<T>(val);
		if (head == NULL){
			head = tail = newNode;
			return;
		}
		tail->next = newNode;
		tail = newNode;
	}
	//chen vao sau mot con tro p
	void insertAfter(Node<T>* p, T val)
	{
		Node<T>* newNode = new Node<T>(val);
		newNode->next = p->next;
		p->next = newNode;
		if (newNode->next == NULL)
			tail = newNode;
	}
	//xoa phan tu o dau LinkedList
	void delBeg()
	{
		//rong
		if (head == NULL)
			return;
		//1 phan tu 
		if (head == tail){
			free(head);//khong goi destructor dung free
			head = tail = NULL;
			return;
		}
		Node<T>* temp = head;
		head = head->next;
		delete temp;
	}
	//xoa phan tu o cuoi LinkedList
	void delEnd(){
		if (head == NULL)
			return;
		if (head == tail){
			delBeg(); return;
		}
		Node<T>* temp;
		for (temp = head; temp->next != tail; temp = temp->next);
		free(tail);
		tail = temp;
		temp->next = NULL;
	}
	//xoa phan tu xac dinh nao do 
	void delMid(Node<T>* delNode)
	{
		if (head == NULL)
			return;
		if (head == tail){
			delBeg(); return;
		}
		Node<T> temp;
		temp = delNode->next;
		*delNode = *temp;//ko dc delNode=temp vi lam gay LinkedList
		delete temp;
	}
	void insertAt(int pos, T val)
	{
		int n = this.length();
		if (pos<0 || pos>n)
			return;
		if (pos == 0) { addFirst(val); return; }
		if (pos == n) { addLast(val); return; }
		Node<T>* temp;
		for (int i = 0, temp = head; i < pos-1; i++, temp = temp->next);//chay den pos-1 roi chen sau
		insertAfter(temp, val);
	}
	void delAt(int pos)
	{
		int n = this.length();
		if (pos<0 || pos>=n)
			return;
		if (pos == 0) { delBeg(); return; }
		if (pos == n-1) { delEnd(); return; }
		Node<T>* temp;
		for (int i = 0, temp = head; i < pos; i++, temp = temp->next);
		if (temp->next == tail)
			tail = temp;
		delMid(temp);
	}
	//xuat ra tuan tu tat ca phan tu trong list
	void printList()
	{
		if (head == NULL){
			cout << "Empty List" << endl;
			return;
		}
		cout << "LinkedList 's size: " << length() << endl;
		for (Node<T>* temp = head; temp; temp = temp->next)
			cout << temp->data << " ";
		cout << endl;
	}
	//tra ve so phan tu hien hanh cua LinkedList
	int length()
	{
		int count = 0;
		Node<T> *temp = head;
		while (temp){
			count++;
			temp = temp->next;
		}
		return count;
	}
	//chong toan tu truy xuat
	T operator  [](int idx)
	{
		if (length() == 0 && idx < 0)
			return NULL;
		int i = 0;
		Node<T>* temp = this->head;
		while (i < idx)
		{
			temp = temp->next;
			i++;
		}
		return temp->data;
	}
	//tra ve index Node co data==val trong LinkedList
	static int searchVal(T val,LinkedList<T>& li)//tai sao co & trc li thi khong error
	{
		for (int i = 0; i < li.length(); i++)
			if (li[i] == val)
				return i;
		return -1;
	}
	//trao hai node(vung nho)
	void swap(Node<T>* x, Node<T>* y)
	{
		//neu x la head thi sao
		if (x == head || y == head)
			return;
		Node<T>* preX;
		Node<T>* preY;
		for (preX = head; preX->next != x; preX = preX->next);
		for (preY = head; preY->next != y; preY = preY->next);

		preX->next = y;
		preY->next = x;
		Node<T>* temp = y->next;
		y->next = x->next;
		x->next = temp;
	}
	//dao LinkedList
	void reverse()
	{
		//luu lai vung nho head tro toi luc dau
		Node<T>* temp = head; 
		Node<T>* pre = NULL;
		Node<T>* curr = head;
		Node<T>* post = head;

		while (curr)
		{
			post = post->next;
			curr->next = pre;
			pre = curr;
			curr = post;
		}
		head = pre;
		tail = temp; tail->next = NULL;
	}
	//void reverse()
	//{
	//	
	//	
	//	tail = head; tail->next = NULL;//Sai vi doi ca head->next(head va tail cung tro den 1 vung nho)tail->next la thay doi vung nho do
	//	Node<T>* pre = NULL;
	//	Node<T>* curr = head;
	//	Node<T>* post = head;

	//	while (curr)
	//	{
	//		post = post->next;
	//		curr->next = pre;
	//		pre = curr;
	//		curr = post;
	//	}
	//	head = pre;
	//}
	//Ham test thoi XOA DI
	void fuck()
	{//chung to swap hoat dong
		Node<T>* p1 = head->next;
		Node<T>* p2 = tail;
		swap(p1, p2);
		this->printList();
	}
	void sort()
	{
		Node<T>* temp = head;
		while (temp)
		{
			Node<T>* min = temp;
			Node<T>* r = temp;
			while (r)
			{
				if (r->data < min->data)
					swap(r->data, min->data);
				r = r->next;
			}
			temp = temp->next;
		}
	}

	void merge(LinkedList<T> &li)//KET QUA DUNG NHUNG CO LOI VE BO NHO
	{
		this->tail->next = li.head;
		this->tail= li.tail;
	}
	
};

#endif

