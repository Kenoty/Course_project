#pragma once

#include "node.h"
#include "listiterator.h"

template<typename T>
class List
{
	int size;
	Node<T> *head;
public:
    using Iterator = ListIterator<T>;
public:
	List(int size = 0, Node<T>* head = nullptr)
	{
		this->size = size;
		this->head = head;
	}
    int getSize();
    void pushBack();
    void popFront();
    void removeObject(const int index);
	void clear();
	T& operator[](const int index);
    Iterator begin() {return Iterator(head);}
    Iterator end() {return nullptr;}
};

template<typename T>
inline int List<T>::getSize()
{
	return size;
}

template<typename T>
inline void List<T>::pushBack()
{

    if (head == nullptr)
		head = new Node<T>;
	else
	{
		Node<T>* current = this->head;

		while (current->next != nullptr)
			current = current->next;
		current->next = new Node<T>;
	}
	size++;
}

template<typename T>
inline void List<T>::popFront()
{
	Node<T>* to_delete = this->head;
	head = head->next;
	delete to_delete;
	size--;
}

template<typename T>
inline void List<T>::removeObject(const int index)
{
	if (index == 0)
	{
        popFront();
	}
	else
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
			previous = previous->next;

		Node<T>* to_delete = previous->next;
		previous->next = to_delete->next;
		delete to_delete;
		size--;
	}
}

template<typename T>
inline void List<T>::clear()
{
	while (size != 0)
	{
        popFront();
	}
}

template<typename T>
inline T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter != index)
		{
			current = current->next;
			counter++;
		}
		else return current->data;
	}
}
