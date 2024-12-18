#include "node.h"

template<typename T>
class ListIterator
{
private:
    Node<T>* current;
public:
    ListIterator(Node<T>* ptr = nullptr): current(ptr){};

    bool operator==(const ListIterator& iterator) const;
    bool operator!=(const ListIterator& iterator) const;

    ListIterator operator++();
    T& operator*();

};

template<typename T>
bool ListIterator<T>::operator==(const ListIterator& iterator) const
{
    return (current == iterator.current);
}

template <typename T>
bool ListIterator<T>::operator!=(const ListIterator& iterator) const
{
    return (current != iterator.current);
}

template <typename T>
ListIterator<T> ListIterator<T>::operator++()
{
    current = current->next;
    return *this;
}

template <typename T>
T& ListIterator<T>::operator*()
{
    return current->data;
}
