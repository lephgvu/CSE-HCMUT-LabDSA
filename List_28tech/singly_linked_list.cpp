#include <iostream>

using namespace std;

class IntSLinkedList {

public:
class Node {
public:
    int data;
    Node* next;
    
public:
    Node(): next(nullptr) {};
    Node(int data) : data(data), next(nullptr) {};
};

private:
    Node* head;
    Node* tail;
    int count;

public:
    IntSLinkedList(): head(nullptr), tail(nullptr), count(0) {};
    void add(int element) {
        Node* tmp = new Node(element);
        if(this->empty()) {
            this->head = this->tail = tmp;
            count++;
        }
        else {
            this->tail->next = tmp;
            this->tail = tmp;
            count++;
        }
    }
    
    void add(int index, int element) {
        if(index < 0 || index >= this->count)
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

    int get(int index) { 
        if(index < 0 || index > this->count)
            throw out_of_range("Index is out of range");
        
        Node* current = this->head;
        for(int i = 0; i < index; i++){
            current = current->next;
        }
            
        return current->data; 
    }

    void set(int index, int element){
        if(index < 0 || index > this->count)
            throw out_of_range("Index is out of range");
        
        Node* current = this->head;
        for(int i = 0; i < index; i++){
            current = current->next;
        }
            
        current->data = element;
    }

    int indexOf(int item){
        Node* tmp = this->head;
        for(int i = 0; i < this->count; i++){
            if(tmp->data == item) return i;
            tmp = tmp->next;
        }
        return -1;
    }
    
    bool contains(int item){
        return this->indexOf(item) >= 0;
    }
};

int main(){

    return 0;
}