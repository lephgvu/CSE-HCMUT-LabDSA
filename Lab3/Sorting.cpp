#ifndef SORTING_H
#define SORTING_H
#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;
template <class T>
class Sorting {
private:
    static T* Partition(T* start, T* end) ;
    static void merge(T* left, T* middle, T* right);
public:
    static void QuickSort(T* start, T* end) ;
    static void mergeSort(T* start, T* end);
};

template <class T>
static T* Partition(T* start, T* end) {
    // TODO: return the pointer which points to the pivot after rearrange the array.
    T pivot = *start;
    T* i = start + 1;
    T* j = end - 1;

    while (true) {
        while (i <= j && *i <= pivot) ++i;
        while (i <= j && *j > pivot) --j;
        if (i >= j) break;
        swap(*i, *j);
    }

    swap(*start, *j);
    return j;
}

template <class T>
static void QuickSort(T* start, T* end) {
    // TODO
    // In this question, you must print out the index of pivot in subarray after everytime calling method Partition.
    if (start < end) {
        T* index = Partition(start, end);
        cout << (index - start) << " ";
        QuickSort(start, index);
        QuickSort(index + 1, end);
    }
}

template <class T>
static void merge(T* left, T* middle, T* right){
    /*TODO*/
     //! Khai báo mảng tạm thời
    T* arr = left;
    int l = 0, m = middle - left, r = right - left;
    //! Kích thước mảng con thứ nhất
    int n1 = m - l + 1; 
    //! Kích thước mảng con thứ hai
    int n2 = r - m; 
  
    // Create temp arrays 
    //! Tạo mảng tạm thời  
    int L[n1], R[n2]; 
  
    //* Copy data to temp arrays L[] and R[]  
 //! Sao chép dữ liệu vào mảng tạm thời L[] và R[]
    for(int i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for(int j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    // Merge the temp arrays back into arr[l..r] 
      int i = 0;
    //* Initial index of second subarray 

    int j = 0;  
      
    //* Initial index of merged subarray 
    int k = l; 
      
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j])  
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else 
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    //* Copy the remaining elements of 
    //* L[], if there are any  
    while (i < n1)  
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    //* Copy the remaining elements of 
    //* R[], if there are any  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    }
    Sorting::printArray(left, right);
}

template <class T>
static void mergeSort(T* start, T* end){
    /*TODO*/
    if(start < end){
       T* mid = (end - start) / 2 + start;
       mergeSort(start, mid);
       mergeSort(mid+1,end);
       merge(start, mid, end);
   }
}

#endif /* SORTING_H */