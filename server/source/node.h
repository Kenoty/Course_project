#pragma once

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
