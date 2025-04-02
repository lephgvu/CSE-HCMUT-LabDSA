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
public:
    static void QuickSort(T* start, T* end) ;
};

template <class T>
static T* Partition(T* start, T* end) {
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

int main() {
    int array[] = { 3, 5, 7, 10 ,12, 14, 15, 13, 1, 2, 9, 6, 4, 8, 11, 16, 17, 18, 20, 19 };
    cout << "Index of pivots: ";
    Sorting<int>::QuickSort(&array[0], &array[20]);
    cout << "\n";
    cout << "Array after sorting: ";
    for (int i : array) cout << i << " ";

    return 0;
}
#endif /* SORTING_H */
