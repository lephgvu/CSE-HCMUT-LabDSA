#include <iostream>

using namespace std;

class IntSLinkedList {
public:
    class Node;

private:
    Node* head;
    Node* tail;
    int count;

public:
    IntSLinkedList(): head(nullptr), tail(nullptr), count(0) {};
    void add(int element) {
        if(this->empty()) {
            Node* tmp = new Node(element);
            this->head = this->tail = tmp;
            count++;
        }
        else {
            Node* tmp = new Node(element);
            this->tail->next = tmp;
            this->tail = tmp;
            count++;
        }
    }
    
    void add(int index, int element) {
        if(index < 0 || index > this->count)
            throw out_of_range("Index is out of range");
        
        if(this->empty()) return this->add(element);
        
        //Add depend
        if(index == this->count) return this->add(element);

        //Add prepend
        if(index == 0) {
            Node* tmp = new Node(element);
            tmp->next = this->head;
            this->head = tmp;
            count++;
            return;
        }

        //Add middle
        Node* tmp = new Node(element);
        Node* prev = head;
        for(int i = 0; i < index - 1; i++) {
            prev = prev->next;    
        }
        tmp->next = prev->next;
        prev->next = tmp;
        count++;
        return;
    }

    int removeAt(int index) { 
        
        return 0; 
    }

    bool removeItem(int item) { 
    
        return false; 
    }

    bool empty(){ return this->count == 0; }

    int size(){ return this->count; }

    int get(int index) { return -1; }



    
public:
    class Node {
    public:
        int data;
        Node* next;
        
    public:
        Node(): next(nullptr) {};
        Node(int data) : data(data), next(nullptr) {};
    };
};

int main(){

    return 0;
}