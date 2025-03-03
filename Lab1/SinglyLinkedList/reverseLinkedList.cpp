#include<iostream>

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

LLNode* reverseLinkedList(LLNode* head) {
    int cnt = 0; // số lượng Node
    for(LLNode *p = head; p != nullptr; p = p->next) cnt++; 
    // Trường hợp có 1 phần tử hoặc rỗng
    if ( !head || !head->next) return head;
    


    LLNode *cur = head;
    LLNode *prev = head->next;
    for(int i=1;i<= cnt-1;i++){
        LLNode * temp = prev ->next;
        prev ->next = cur;
        cur = prev;
        prev = temp;
    }
    head ->next= nullptr;
    head = cur;
    return head;

}

int main(){
    int arr[] = {13, 88, 2, 1};
    LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
    LLNode::printList(head);
    cout << "\n";
    LLNode* newhead = reverseLinkedList(head);
    LLNode::printList(newhead);
    newhead->clear();
    //! 1 2 88 13
}