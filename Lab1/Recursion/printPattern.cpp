#include <iostream>

using namespace std;

void printPattern(int n) 
{ 
    if(n <= 0){
        cout<<n;
        return;
    }
    cout<<n<<" ";
    printPattern(n-5);
    cout<<" "<<n;
}

int main(){
    printPattern(14); //14 9 4 -1 4 9 14
    return 0;
}