#include <iostream>
#include <string>
using namespace std;

string expand(string s) {
    
}

int main(){
    cout << expand("2(ab3(cde)x)") << "\n"; //abcdecdecdexabcdecdecdex
    cout << expand("2(x0(y))3(z)") << "\n"; //xxzzz
    return 0;
}