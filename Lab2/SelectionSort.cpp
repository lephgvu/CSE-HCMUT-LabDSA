#include <iostream>
using namespace std;

template <class T>
class Sorting
{
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        int size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    static void selectionSort(T *start, T *end);
    static void sortSegment(T* start, T* end, int segment_idx, int cur_segment_total);
    static void ShellSort(T* start, T* end, int* num_segment_list, int num_phases);
};

template <class T>
void Sorting<T>::selectionSort(T *start, T *end) {
    int size = end - start;

    for(int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < size; j++) {
            if(start[j] < start[minIndex])
            minIndex = j;
        }
        if(minIndex != i) 
        std::swap(start[i], start[minIndex]);
        
        printArray(start, end);
    }
}

template <class T>
void Sorting<T>::sortSegment(T* start, T* end, int segment_idx, int cur_segment_total) {
    int n = end - start;
    for(i = segment_idx; i < n; i+= cur_segment_total) {
        for(j = i + cur_segment_total; j < n; j += cur_segment_total) {
            if(start[j] < start[i]) {
                int temp = start[j];
                start[j] = start[i];
                start[i] = temp;
            }
        }
    }
}

void Sorting<T>::ShellSort(T* start, T* end, int* num_segment_list, int num_phases) {
    for(int i = num_phases - 1; i >= 0; i--) {
        for(int j = 0; j < num_segment_list; j++) {
            sortSegment(start, end, j, num_segment_list[i]);
        }
        printArray(start, end);
    }
}

int main() {
    int arr[] = {9, 2, 8, 1, 0, -2};
    Sorting<int>::selectionSort(&arr[0], &arr[6]);
    return 0;
}