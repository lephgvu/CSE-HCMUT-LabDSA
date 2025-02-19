#include<iostream>

using namespace std;

// ---------------------------Cai dat ngan xep bang mang 1 chieu-----------------------------------------------
// int n = 0, stack[10001];

// void push(int x){
//     stack[n] = x;
//     ++n;
// }

// void pop(){
//     if(n >= 1) --n;
// }

// int top(){
//     return stack[n-1];
// }

// int size(){
//     return n;
// }

// -----------------------------Cai dat ngan xep bang DSLK------------------------------------------------------
struct node{
    int data;
    struct node *next;
};

node *makeNode(int x){
    node *newNode = new node();
    newNode->data = x;
    newNode->next = nullptr;
    return newNode;
}

// push(): nhap vao
void push(node **top, int x){
    node *newNode = makeNode(x);
        newNode->next = *top;
        *top = newNode;
}

// pop(): lay ra
void pop(node **top){
    if(*top != nullptr){
        node *temp = *top;
        *top = (*top)->next;
        delete temp;
    }
}

//Top(): Lay thang tren cung ma khong xoa
int Top(node *top){
    if(top != nullptr){
        return top->data;
    }
}

//size()
int size(node *top){
    int ans = 0;
    while(top != nullptr){
        ++ans;
        top = top->next;
    }
    return ans;
}
int main(){

    return 0;
}