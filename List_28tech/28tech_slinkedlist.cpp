#include<iostream>

using namespace std;

//Dinh nghia mot node
struct node{
    int data;
    node* next;
};

//Tao mot node moi
node *makeNode(int x){
    node *newNode = new node();
    newNode->data = x;
    newNode->next = nullptr;
    return newNode;
}

//Duyet cac node trong DSLK
void duyet(node *head){
    while(head != nullptr){
        cout << head->data << ' ';
        head = head->next;
    }
}

//Dem so node trong DSLK
int size(node *head){
    int dem = 0;
    while(head != nullptr){
        dem++;
        head = head->next;
    }
    return dem;
}

//Them node moi vao dau DSLK
void pushFront(node **head, int x){
    node *newNode = makeNode(x);
    //Buoc 1: phan next cua newNode => head
    newNode->next = *head;
    //Buoc 2: cap nhat node head => newNode
    *head = newNode;
}

//Them node moi vao cuoi DSLK
void pushBack(node **head, int x){
    node *temp = *head; //Tao mot bien tam gan bang head
    node *newNode = makeNode(x); //Tao mot node moi
    if(*head == nullptr){
        *head = newNode;
        return; 
    }
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}

//Chen node vao giua DSLK
void insert(node **head, int k, int x){
    int n = size(*head);
    if(k < 1 || k > n + 1) return;
    if(k == 1){
        pushFront(head, x); return;
    }

    node *temp = *head;
    
    for(int i = 1; i <= k - 2; i++){
        temp = temp->next;
    }
    //temp: k - 1
    node *newNode = makeNode(x);
    newNode->next = temp->next;
    temp->next = newNode;
}

//Xoa node dau khoi DSLK
void popFront(node **head){
    if(*head == nullptr) return;
    node *temp = *head;
    *head = temp->next; //tai sao khong gan *head = *head->next duoc con gan *head = *temp->next duoc?
    //*head = *head->next;
    //*head = *temp->next;
    delete temp;
}

//Xoa node cuoi khoi DSLK
void popBack(node **head){
    if(*head == nullptr) return;
    node *temp = *head;
    if(temp->next == nullptr){
        *head = nullptr;
        delete temp;
        return;
    }
    while(temp->next->next != nullptr){
        temp = temp->next;  
    }
    node *last = temp->next;
    temp->next = nullptr;
    delete last;
}

//Xoa node giua khoi DSLK
void eraseNode(node **head, int k){
    int n = size(*head);
    if(k < 1 || k > n) return; // Khong xoa
    if(k == 1) popFront(head);
    else{
        node *temp = *head;
        for(int i = 1; i <= k - 2; i++){
            temp = temp->next;
        }
        //temp dang o k - 1
        node *kth = temp->next;
        temp->next = kth->next;
        delete kth;
    }
}

//Selection sort DSLK
void sort(node **head){
    for(node *i = *head; i != nullptr; i = i->next){
        node *minNode = i;
        for(node *j = i->next; j != nullptr; j = j->next){
            if(minNode->data > j->data) minNode = j;
        }
    int temp = minNode->data;
    minNode->data = i->data;
    i->data = temp;
    }
}
int main(){
    node *head = nullptr;
    for(int i = 1; i <= 5; i++){
        pushBack(&head, i);
    }
    // insert(&head, 6, 100);
    // duyet(head); cout<<endl;
    // popFront(&head);
    // duyet(head); cout<<endl;
    // popBack(&head);
    // duyet(head);
    duyet(head); cout<<endl;
    eraseNode(&head, 2);
    duyet(head);

    return 0;
}