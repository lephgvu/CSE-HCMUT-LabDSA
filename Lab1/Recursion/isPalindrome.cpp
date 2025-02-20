#include <iostream>
#include <string.h>
using namespace std;

bool isPalindrome(string str){
    int len = str.length();
    
    if(len == 0 || len == 1) return true;
    
    if(str[0] == ' ') return isPalindrome(str.substr(1, len));
    if(str[len - 1] == ' ') return isPalindrome(str.substr(0, len - 1));

    if(str[0] != str[len - 1]) return false;
    else return isPalindrome(str.substr(1, len - 2));
}

int main(){
    cout << isPalindrome("mom") << endl;
    cout << isPalindrome("do geese see god");
    return 0;
}