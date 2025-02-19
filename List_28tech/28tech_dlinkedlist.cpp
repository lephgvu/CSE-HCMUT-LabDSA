#include <iostream>

using namespace std;

struct node{
    int data;
    node *next;
    node *prev;
};

node *makeNode(int x){
    node *newNode = new node;
    newNode->data = x;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void duyet(node *head){
    while(head != nullptr){
        cout << head->data <<' ';
        head = head->next;
    }
    cout << endl;
}

int size(node *head){
    int cnt = 0;
    while(head != nullptr){
        ++cnt;
        head = head->next;
    }
    return cnt;
}

//------------------------ Them node vao dau Doubly-Linked-List ----------------------------//
void pushFront(node **head, int x){
    node *newNode = makeNode(x);
    newNode->next = *head;
    if(*head != nullptr){
        (*head)->prev = newNode;
    }  
    *head = newNode;
}

//------------------------- Them node vao cuoi Doubly-Linked-List ---------------------------//
void pushBack(node **head, int x){
    node *newNode = makeNode(x);
    if(*head == nullptr){
        *head = newNode;
        return;
    }
    node *temp = *head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

//------------------------- Them node vao giua Doubly-Linked-List ---------------------------//
void insert(node **head, int k, int x){
    int n = size(*head);
    if(k < 1 || k > n + 1) return;
    if(k == 1){
        pushFront(head, x);
        return;
    }
    node *temp = *head;
    for(int i = 1; i <= k - 1; i++){
        temp = temp->next;
    }
    node *newNode = makeNode(x);
    //4 dong code sau phai theo thu tu, neu khong thi no se khong luu node k-1
    newNode->next = temp;
    (temp->prev)->next = newNode;
    newNode->prev = temp->prev;
    temp->prev = newNode;
}

int main(){
    return 0;
}