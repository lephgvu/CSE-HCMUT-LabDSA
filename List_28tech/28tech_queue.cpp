#include <iostream>

using namespace std;

// ---------------------------------Cai dat hang doi bang mang 1 chieu -------------------------------------------------
// int a[100000], maxN = 100000;
// int n = 0;

// int size(){
//     return n;
// }

// bool empty(){
//     return n == 0;
// }

// void enQueue(int x){
//     if(n = maxN) return;
//     a[n] = x; 
//     ++n;
// }

// void deQueue(){
//     if(n == 0) return;
//     for(int i = 0; i < n - 1; i++){
//         a[i] = a[i + 1];
//     }
//     --n;
// }

// int front(){
//     return a[0];
// }

// int rear(){
//     return a[n - 1];
// }   




// --------------------------------------------Cai dat hang doi bang DSLK --------------------------------------------
struct node{
    int data;
    struct node* next;
};

node* makeNode(int x){
    node* newNode = new node();
    newNode->data = x;
    newNode->next = nullptr;
    return newNode;
}

void push(node **queue, int x){
    node* temp = *queue;
    node* newNode = makeNode(x);
    if(*queue = nullptr){
        *queue = newNode;
        return;
    }
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}

void pop(node **queue){
    if(*queue = nullptr) return;
    node *temp = *queue;
    *queue = temp->next;
    delete temp;
}

int size(node *queue){
    int ans = 0;
    while(queue != nullptr){
        ++ans;
        queue = queue->next;
    }
    return ans;
}

bool empty(node *queue){
    return queue == nullptr;
}

int front(node *queue){
    return queue->data;
}

int main(){
    node *queue = nullptr;
    
    return 0;
}
 