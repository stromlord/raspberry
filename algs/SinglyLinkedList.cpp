#include <iostream>

// 定义单链表的节点结构体
struct Node{
    int data;       // 节点存储的数据
    Node* next;     // 指向下一个节点的指针

    // 构造函数，初始化节点的值和指针
    Node(int val) : data(val), next(nullptr) {}
};

// 单链表类
class SinglyLinkedList{
private:
    Node* head;     // 链表的头指针

public:
    // 构造函数，初始化头指针为nullptr
    SinglyLinkedList() : head(nullptr) {}

    // 析构函数，释放链表占用的内存
    ~SinglyLinkedList(){
        while (head != nullptr){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // 在链表头部插入新节点
    void push_front(int value){
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // 在链表尾部插入新节点
    void push_back(int value){
        Node* newNode = new Node(value);
        if (head == nullptr)
            head = newNode;
        else{
            Node* current = head;
            while (current->next != nullptr)
                current = current->next;
            current->next = newNode;
        }
    }

    // 打印链表中的所有元素
    void printList() const{
        Node* current = head;
        while (current != nullptr){
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main(){
    SinglyLinkedList list;
    list.push_front(10);
    list.push_back(20);
    list.push_front(30);
    list.printList();

    return 0;
}