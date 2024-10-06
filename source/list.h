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
	List()
	{
		size = 0;
		head = nullptr;
	}
	int get_size();
	void push_back();
	void pop_front();
	T& operator[](const int index);
};
