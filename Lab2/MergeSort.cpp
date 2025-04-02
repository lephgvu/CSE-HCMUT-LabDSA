#ifndef SORTING_H
#define SORTING_H
#include <iostream>
using namespace std;
template <class T>
class Sorting {
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        long size = end - start + 1;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }
    
    static void merge(T* left, T* middle, T* right){
        /*TODO*/
        Sorting::printArray(left, right);
    }
    static void mergeSort(T* start, T* end) {
       /*TODO*/
    }
};

int main() {
    int arr[] = {0,2,4,3,1,4};
    Sorting<int>::mergeSort(&arr[0], &arr[5]);

    // int arr[] = {1};
    // Sorting<int>::mergeSort(&arr[0], &arr[0]);

    return 0;
}

#endif /* SORTING_H */