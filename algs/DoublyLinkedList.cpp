#include <iostream>

template<typename T>
class DoublyLinkedList{
private:
    struct Node
    {
        T data;
        Node* prev;
        Node* next;

        Node(const T val): data(val), prev(nullptr), next(nullptr){}
    };

    Node* head;
    Node* tail;

public:
    // 构造函数
    DoublyLinkedList(): head(nullptr), tail(nullptr) {}
    
    // 析构函数
    ~DoublyLinkedList(){
        while (head){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // 尾部添加元素
    void push_back(T val){
        Node* newNode = new Node(val);
        if (!head){
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // 在头部添加元素
    void push_front(T val){
        Node* newNode = new Node(val);
        if (!head){
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // 链表输出显示
    void print() const{
    	Node* current = head;
        while(current){
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

};

int main(){
    DoublyLinkedList<int> Dlist;

    Dlist.push_back(1);
    Dlist.push_back(2);
    Dlist.push_front(0);
    Dlist.print();

    return 0;
}