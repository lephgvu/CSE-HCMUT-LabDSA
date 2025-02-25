#include <iostream>
#include <math.h>
using namespace std;

class LLNode {
    public:
        int val;
        LLNode* next;
        LLNode();
        LLNode(int val, LLNode* next);
}

LLNode* addLinkedList(LLNode* l0, LLNode* l1) {
    // STUDENT ANSWER
}

int main(){
    int arr1[] = {2, 9};
    int arr2[] = {0, 5};
    LLNode* head1 = LLNode::createWithIterators(arr1, arr1 + sizeof(arr1) / sizeof(int));
    LLNode* head2 = LLNode::createWithIterators(arr2, arr2 + sizeof(arr2) / sizeof(int));
    LLNode* newhead = addLinkedList(head1, head2);
    LLNode::printList(newhead);
    head1->clear();
    head2->clear();
    newhead->clear();
    
    //[2, 4, 1]

    return 0;
}