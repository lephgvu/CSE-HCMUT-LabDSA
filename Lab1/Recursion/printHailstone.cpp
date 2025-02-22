#include <iostream>
using namespace std;

void printHailstone(int number)
{   
    cout << number;
    if(number == 1) return;
    
    else if(number % 2 == 0){
        cout << " ";
        printHailstone(number/2);
    }
    else if(number % 2 != 0){
        cout << " ";
        printHailstone(number*3 + 1);
    }
    else return;
}

int main(){
    printHailstone(13); //32 16 8 4 2 1

    return 0;
}