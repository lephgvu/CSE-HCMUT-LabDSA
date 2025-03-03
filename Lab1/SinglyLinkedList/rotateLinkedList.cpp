#include <iostream>
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

LLNode* rotateLinkedList(LLNode* head, int k) {
    // STUDENT ANSWER
    if (head == nullptr)
    return nullptr;
    for (int i = 0; i < k; i++)
    {
        LLNode *tmp = head;
        while (tmp -> next -> next != nullptr)
        {
            tmp = tmp -> next;
        }
        LLNode * rotate = tmp -> next;
        tmp -> next = nullptr;
        rotate -> next = head;
        head = rotate;
    }
    return head;
}

int main(){
    int arr[] = {2, 4, 6, 6, 3};
    int k = 3;
    LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
    LLNode::printList(head);
    cout << "\n";
    LLNode* newhead = rotateLinkedList(head, k);
    LLNode::printList(newhead);
// [2, 4, 6, 6, 3]
// [6, 6, 3, 2, 4]
    return 0;
}