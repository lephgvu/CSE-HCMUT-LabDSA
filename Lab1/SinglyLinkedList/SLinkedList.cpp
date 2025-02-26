#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

template <class T>
class SLinkedList {
public:
    class Node; // Forward declaration

protected:
    Node* head;
    Node* tail;
    int count;

public:
    SLinkedList(): head(NULL), tail(NULL), count(0);
    ~SLinkedList();
    void add(const T& e);
    void add(int index, const T& e);
    int  size();
    bool empty();
    int  size();
    void clear();
    T    get(int index);
    void set(int index, const T& e);
    int  indexOf(T item);
    bool contains(T item);
    T    removeAt(int index);
    bool removeItem(const T& item);

public:
    class Node {
    private:
        T data;
        Node* next;
        friend class SLinkedList<T>;

    public:
        Node() {
            next = 0;
        }
        Node(Node* next) {
            this->next = next;
        }
        Node(T data, Node* next = nullptr) {
            this->data = data;
            this->next = next;
        }
    };
};

template <class T>
void SLinkedList<T>::add(const T& e) {
    Node* tmp = new Node(e, nullptr);
    if(this->count == 0) {
        this->head = this->tail = tmp;
        count++;
    }
    else {
        this->tail->next = tmp;
        this->tail = tmp;
        count++;
    }
}

template<class T>
void SLinkedList<T>::add(int index, const T& e) {
    if(index == this->count || (this->count == 0 && index == 0)) {
        this->add(e);    
    } 
    else if(index == 0) {
        Node* tmp = new Node(e, nullptr);
        tmp->next = this->head;
        this->head = tmp;
        count++;
    }
    
    else {
        Node* tmp = new Node(e, nullptr);
        Node* prev = head;
        for(int i = 0; i < index - 1; i++) {
            prev = prev->next;    
        }
        tmp->next = prev->next;
        prev->next = tmp;
        count++;
    }
}

template<class T>
int SLinkedList<T>::size() {
    return this->count;
}

template<class T>
T SLinkedList<T>::get(int index) {
    if(index < 0 || index >= this->count) {
        throw std::out_of_range("Index is out of range");
    }
    else {
        Node* current = this->head;
        for(int i = 0; i < index; i++){
            current = current->next;
        }
        return current->data;
    }
}

template <class T>
void SLinkedList<T>::set(int index, const T& e) {
    if(index < 0 || index >= this->count) {
        throw std::out_of_range("Index is out of range");
    }
    else{
        Node* tmp = this->head;
        for(int i = 0; i < index; i++){
            tmp = tmp->next;
        }
        tmp->data = e;
    }
}

template<class T>
bool SLinkedList<T>::empty() {
    return this->count == 0;
}

template<class T>
int SLinkedList<T>::indexOf(const T& item) {
    Node* tmp = this->head;
    for(int i = 0; i < count; i++) {
        if(tmp->data == item) return i;
        tmp = tmp->next;
    }
    return -1;
}

template<class T>
bool SLinkedList<T>::contains(const T& item) {
    return this->indexOf(item) >= 0;
}

template <class T>
T SLinkedList<T>::removeAt(int index)
{
    if(index < 0 || index > this->count)
            throw out_of_range("Index is out of range");

    else if(this->count == 1) {
        Node* tmp = this->head;
        this->head = this->tail = nullptr;
        T value = tmp->data;
        delete tmp;
        count--;
        return value;
    }
    else if(index == 0) {
        Node* tmp = this->head;
        head = head->next;
        tmp->next = nullptr;
        T value = tmp->data;
        delete tmp;
        count--;
        return value;
    }
    else if(index == this->count - 1) {
        Node* tmp = this->head;
        for(int i = 0; i < index - 1; i++) tmp = tmp->next;
        tmp->next = nullptr;
        T value = tail->data;
        delete this->tail;
        this->tail = tmp;
        return value;
    }
    else{
        Node* prev = this->head;
        for(int i = 0; i < index - 1; i++) prev = prev->next;
        Node* cur = prev->next;
        prev->next = cur->next;
        cur->next = nullptr;
        T value = cur->data;
        delete cur;
        count--;
        return value;
    }
}

template <class T>
bool SLinkedList<T>::removeItem(const T& item)
{
    Node* cur = head;
    for (int i = 0; i < this->count; i++) {
        
        if (cur->data == item) { removeAt(i); return true; }
        cur = cur->next;
    }
    return false;
}

template<class T>
void SLinkedList<T>::clear(){
    for (int i = 0; i < this->count; i++) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    this->head = NULL;
    this->tail = NULL;
    this->count = 0;
}

int main(){
    SLinkedList<int> list;
    int size = 10;

    for(int index = 0; index < size; index++){
        list.add(index);
    }

    cout << list.toString();
    //[0,1,2,3,4,5,6,7,8,9]

    //----------------------------
    SLinkedList<int> list;
    int size = 10;

    for(int index = 0; index < size; index++){
        list.add(0, index);
    }

    cout << list.toString();
    //[9,8,7,6,5,4,3,2,1,0]
    
    return 0;
}

