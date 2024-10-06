#include <iostream>

template<typename T>
class List
{
	int size;
	template<typename T>
	class Node
	{
	public:
		Node *next;
		T data;

		Node(T data = T(), Node* next = nullptr)
		{
			this->next = next;
			this->data = data;
		}
	};
	Node<T> *head;
public:
	List(int size = 0, Node<T>* head = nullptr)
	{
		this->size = size;
		this->head = head;
	}
	~List()
	{
		clear();
	}
	int get_size();
	void push_back();
	void pop_front();
	void remove_object(const int index);
	void clear();
	T& operator[](const int index);
};

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
		Node<T>* current = this->head;

		while (current->next != nullptr)
			current = current->next;
		current->next = new Node<T>;
	}
	size++;
}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* to_delete = this->head;
	head = head->next;
	delete to_delete;
	size--;
}

template<typename T>
void List<T>::remove_object(const int index)
{
	if (index == 0)
	{
		pop_front();
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
		pop_front();
	}
}

template<typename T>
T& List<T>::operator[](const int index)
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