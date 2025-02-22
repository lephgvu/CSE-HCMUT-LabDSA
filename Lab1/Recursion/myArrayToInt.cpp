#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int myArrayToInt(char *str, int n) 
{ 
    if (n == 0) {
        return 0;
    } else {
        return (str[0] - '0') * pow(10, n - 1) + myArrayToInt(str + 1, n - 1);
    }
}

int main(){
    char str[] = "2020";
    printf("%d", myArrayToInt(str, 4));
    return 0;
}