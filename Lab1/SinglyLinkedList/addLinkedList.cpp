#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <algorithm>
#include <cstring>
#include <utility>
#include <climits>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
using namespace std;

class LLNode {
public:
    int val;
    LLNode* next;
    LLNode(){
        this->next = nullptr;
    }
    LLNode(int val, LLNode* next){
        this->val = val;
        this->next = next;
    }

    static LLNode* createWithIterators(int* begin, int* end);
    static void printList(LLNode* head);
    void clear(){
        LLNode * head = this;
        while(head != nullptr){
            LLNode * temp = head;
            head = head->next;
            delete temp;
        
        }
    }
};

//! hàm tạo ra danh sach node
LLNode* LLNode::createWithIterators(int* begin, int* end){
    LLNode * head = nullptr;
    LLNode * curr = nullptr;
    for(int * ptr = begin; ptr!= end; ++ptr){
        //! lưu lại node đầu để trả danh sách về lại
        LLNode *p = new LLNode(*ptr , nullptr);
        if(head == nullptr) {
           head = p;
           curr = head;
        }
        else{
           curr->next = p;
           curr = curr->next;
        } 
    }
    return head;
}

void LLNode::printList(LLNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

LLNode* addLinkedList(LLNode* l0, LLNode* l1) {
    LLNode* tmp = new LLNode(1,NULL);  // duy trì phần tử dư
    LLNode* result = tmp;

    int number = 0;  // lưu giá trị dư
    while(l0 && l1){
        int k = l0->val + l1->val;
//! chia để lấy 1 phần tử 
        tmp->next = new LLNode(((k + number) % 10),NULL);
        tmp = tmp->next;
//! lưu phép dư 
        number = (k + number) / 10;
        l0 = l0->next;
        l1 = l1->next;
        
    }
//! làm tương tự ở trên 
    while(l0){
        int k = l0->val;
        tmp->next = new LLNode((k + number) % 10,NULL);
        tmp = tmp->next;
        number = (k + number) / 10;
        l0 = l0->next;
        
    }
//! làm tương tự ở trên
    while(l1){
        int k = l1->val;
        tmp->next = new LLNode((k + number) % 10,NULL);
        tmp = tmp->next;
        number = (k + number) / 10;
        l1 = l1->next;
        
    }
//! nếu đến cuối còn dư 1 thì thêm 1 node có giá trị là 1
     if(number == 1) tmp->next = new LLNode(1,NULL);
    return result->next;
}

int main(){
    int arr1[] = {2 , 9};  // 92 
    int arr2[] = {0 , 5};  // 50   = 241
    LLNode* head1 = LLNode::createWithIterators(arr1, arr1 + sizeof(arr1) / sizeof(int));
    LLNode* head2 = LLNode::createWithIterators(arr2, arr2 + sizeof(arr2) / sizeof(int));
    LLNode* newhead = addLinkedList(head1, head2);
    LLNode::printList(newhead);
    head1->clear();
    head2->clear();
    newhead->clear();
}