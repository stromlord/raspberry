#include <iostream>

template<typename T>
struct Node
{
    T data;
    Node<T>* prev;
    Node<T>* next;

    Node(const T& val): data(val), prev(nullptr), next(nullptr){}
};

template<typename T>
class DoublyLinkedList{
private:

public:

};