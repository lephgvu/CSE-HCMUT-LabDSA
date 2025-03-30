#include <iostream>
using namespace std;

template <class T>
class DLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    DLinkedList();
    ~DLinkedList();
    void    add(const T &e);
    void    add(int index, const T &e);
    int     size();
    bool    empty();
    T       get(int index);
    void    set(int index, const T &e);
    int     indexOf(const T &item);
    bool    contains(const T &item); 
    T       removeAt(int index);
    bool    removeItem(const T &item);
    void    clear();
public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;

    public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };

};

template <class T>
void DLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    Node* pNew = new Node(e);
    if(this->count == 0) {
        this->head = this->tail = pNew;
        this->count++;
    }
    else {
        this->tail->next = pNew;
        pNew->previous = this->tail;
        this->tail = pNew;
        this->count++;
    }
    return;
}

template<class T>
void DLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */ 
    if(index < 0 || index > this->count)
        return;
    
    Node* newNode = new Node(e);    
    if(index == 0) {
        if(head) {
            newNode->next = this->head;
            this->head->previous = newNode;
            this->head = newNode;
            this->count++;
        }
        else this->add(e);
    }

    else if(index == this->count) {
        this->add(e);
    }

    else {
        Node* pre = this->head;
        for(int i = 0; i < index - 1; i++) 
            pre = pre->next;
        newNode->next = pre->next;
        pre->next->previous = newNode;
        pre->next = newNode;
        newNode->previous = pre;
        this->count++;
    }
    return;
}

template<class T>
int DLinkedList<T>::size() {
    /* Return the length (size) of list */ 
    return this->count;
}

template<class T>
T DLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    Node* current = this->head;
    for(int i = 0; i < index; i++){
        current = current->next;
    }
    return current->data;
}

template <class T>
void DLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
    Node* current = this->head;
    for(int i = 0; i < index; i++){
        current = current->next;
    }
    current->data = e;
}

template<class T>
bool DLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    return this->count == 0;
}

template<class T>
int DLinkedList<T>::indexOf(const T& item) {
    /* Return the first index wheter item appears in list, otherwise return -1 */
    Node* current = this->head;
    for(int i = 0; i < this->count; i++) {
        if(current->data == item) 
            return i;
        current = current->next;
    }
    return -1;
}

template<class T>
bool DLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
    return indexOf(item) != -1;
}

template <class T>
T DLinkedList<T>::removeAt(int index)
{
    /* Remove element at index and return removed value */
    Node *current = this->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    T data = current->data;
    
    if (current->previous != nullptr) {
        current->previous->next = current->next;
    }

    else {
        // current is head
        this->head = current->next;
    }
    
    if (current->next != nullptr) {
        current->next->previous = current->previous;
    }
    
    else {
        // current is tail
        this->tail = current->previous;
    }
    this->count--;
    return data;
}

template <class T>
bool DLinkedList<T>::removeItem(const T& item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    Node *current = this->head;
    for (int i = 0; i < this->count; i++) {
        if (current->data == item) 
            return this->removeAt(i)>=0; 
        current = current->next;
    }
    return false;
}

template<class T>
void DLinkedList<T>::clear(){
    /* Remove all elements in list */
    while (this->count > 0) {
        removeAt(0);
    }
}

int main() {

    return 0;
}