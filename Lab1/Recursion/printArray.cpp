#include <iostream>

using namespace std;

void printArray(int n){
    if (n == 0) {
        cout << 0;
    } else {
        printArray(n - 1);
        cout <<", "<< n;
    }
}

int main(){
    printArray(5);
    printArray(10);
    return 0;
}