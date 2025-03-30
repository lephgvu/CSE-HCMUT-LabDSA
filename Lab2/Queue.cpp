#include <iostream>
#include <algorithm>
class StraightSelectionSort {
public:
    static void sort(Complex *list, int length) {
        int current = 0;
        while(current < length - 1) {
            int smallest = current;
            int walker = current + 1;
            while(walker < length) {
                if(list[walker] < list[smallest]) {
                    smallest = walker;
                }
                else walker = walker + 1;
            }
            swap(current, smallest);
            current = current + 1;
        }
    }
    static void sort(Complex *list, int length, int left, int right);
};