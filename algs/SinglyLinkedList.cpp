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
        Node* newNode = new Node(value); // 创建一个新节点，包含给定的值
        newNode->next = head; // 新节点的下一个节点是原来的头节点
        head = newNode; // 更新头指针指向新节点
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

    // 删除链表头部
    void pop_front(){
        if (head != nullptr){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // 删除链表尾部
    void pop_back(){
        if ((head == nullptr) || (head->next == nullptr)){
            // 如果链表为空或者只有一个节点，直接删除头节点
            delete head;
            head = nullptr;
        }else{
            // 找到倒数第二个节点
            Node* current = head;
            while (current->next->next != nullptr)
                current = current->next;
            // 删除最后一个节点
            Node* temp = current->next;
            current->next = nullptr;
            delete temp;
        }
    }

    // 反转链表
    void reverse() {
        Node* current = head; // 当前节点，从头节点开始
        Node* prev = nullptr;  // 前一个节点，初始为nullptr

        // 遍历链表直到最后一个节点
        while (current != nullptr) {
            Node* next = current->next; // 保存当前节点的下一个节点
            current->next = prev;       // 反转指针指向前一个节点
            prev = current;             // 前一个节点前移
            current = next;             // 当前节点前移
        }

        head = prev; // 更新头节点为反转后链表的第一个节点
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
    list.push_back(30);

    std::cout << "Original list: ";
    list.printList();

    list.reverse(); // Reverse the list in-place
    std::cout << "Reversed list: ";
    list.printList();
    
    return 0;
}