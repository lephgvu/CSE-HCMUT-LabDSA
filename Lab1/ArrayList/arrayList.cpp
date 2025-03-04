#include <iostream>

using namespace std;

template<class T>
int ArrayList<T>::get(int index){
    if(index < 0 || index > this->count) throw out_of_range("Index_out_of_range");
    return data[index];
}

template<class T>
void ArrayList<T>::set(int index, T item){
    if(index < 0 || index > this->count) throw out_of_range("Index_out_of_range");
    data[index] = item;
}

template<class T>
void ArrayList<T>::ensureCapacity(int cap){
    if (cap >= this->capacity) {
        int newCapacity = this->capacity * 1.5;
        T* newData = new T[newCapacity];
        for (int i = 0; i < this->count; i++) {
            newData[i] = this->data[i];
        }

        delete[] this->data;
        this->capacity = newCapacity;
        this->data = newData;
    }
}

template <class T>
void ArrayList<T>::add(T e) {
    this->ensureCapacity(this->count + 1);
    this->data[this->count] = e;
    this->count++;
}

template<class T>
void ArrayList<T>::add(int index, T e) {
    if(index < 0 || index >= capacity) 
        throw std::out_of_range("Index is out of range");
    this->ensureCapacity(this->count + 1); 

    for (int i = count; i > index; i--) {
        this->data[i] = this->data[i - 1];
    }

    this->data[index] = e;
    this->count++;
}

template<class T>
int ArrayList<T>::size() {
    /* Return the length (size) of the array */ 
    return this->count;
}

template<class T>
T ArrayList<T>::removeAt(int index){
    if (index < 0 || index >= this->count) 
        throw std::out_of_range("Index is out of range");

    T removeValue = data[index]; 
    for (int i = index; i < count - 1; i++) {
        data[i] = data[i + 1];
    }

    count--; 
    return removeValue;
}

template<class T>
bool ArrayList<T>::removeItem(T item){
    for (int i = 0; i < this->count; i++) {
        if (data[i] == item) {
            // Shift elements to the left to fill the gap
            for (int j = i; j < count - 1; j++) {
                data[j] = data[j + 1];
            }

            this->count--;
            return true;
        }
    }
    return false; 
}

template<class T>
void ArrayList<T>::clear(){
    if(this->data != NULL) delete[] this->data;
    
    this->data = new T[5];
    this->capacity = 5;
    this->count = 0;
}

int main(){
    ArrayList<int> arr;
    int size = 10;
    
    for(int index = 0; index < size; index++){
        arr.add(index);
    }
    
    cout << arr.toString() << '\n'; //[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    cout << arr.size(); //10
    return 0;
}