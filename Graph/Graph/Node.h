#pragma once
template<class T>
class Node
{
public:
	Node();
	Node(T);
	~Node();
	Node* next;
	T data;

};

template<class T>
Node<T>::Node()
{
	data = 0;
	next = nullptr;
}
template<class T>
Node<T>::Node(T data)
{
	this->data = data;
	this->next = nullptr;
}
template<class T>
Node<T>::~Node()
{
}