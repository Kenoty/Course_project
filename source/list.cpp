#include "list.h"

template<typename T>
int List<T>::get_size()
{
	return size;
}

template<typename T>
void List<T>::push_back()
{
	if (head == nullptr)
		head = new Node<T>;
	else
	{
		Node* current = this->head;
		while (current->next != nullptr)
			current = current->next;
		current->next = new Node<T>;
	}
	size++;
}

//template<typename T>
//T& List<T>::operator[](const int index)
//{
//	int counter = 0;
//
//	Node* current = this->head;
//	while (current != nullptr)
//	{
//		if (counter != index)
//			current = current->next;
//		else return data;
//	}
//}