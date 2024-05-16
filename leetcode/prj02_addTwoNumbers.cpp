#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void list_print(ListNode* list){
    ListNode* current = list;
    while(current){
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* current_l1 = l1;
        ListNode* current_l2 = l2;
        
        ListNode* sum_list = nullptr;
        ListNode* current_sum = sum_list;

        while (current_l1 && current_l2){
            int temp_val = current_l1->val + current_l2->val;
            std::cout << current_l1->val << "; "  << current_l2->val << std::endl;

            if (current_sum == nullptr){
                current_sum = new ListNode(temp_val);
                sum_list = current_sum;
            } else {
                current_sum->next = new ListNode(temp_val);
                current_sum = current_sum->next;
            }

            current_l1 = current_l1->next;
            current_l2 = current_l2->next;
        }

        return sum_list;
    }

};


int main(){
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    list_print(l1);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    list_print(l2);

    Solution s;
    ListNode* result = s.addTwoNumbers(l1, l2);
    list_print(result);
}