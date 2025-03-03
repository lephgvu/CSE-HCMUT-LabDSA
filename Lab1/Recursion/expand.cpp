#include <iostream>
#include <string>
using namespace std;

string multiply(string part, int count) {
    return (count == 0) ? "" : part + multiply(part, count - 1);
}

int findClosingBracket(string s, int index, int count = 1) {
    if (count == 0) return index - 1;
    return findClosingBracket(s, index + 1, count + (s[index] == '(') - (s[index] == ')'));
}

string expand(string s) {
    if (s.empty()) return "";

    if (islower(s[0])) return s[0] + expand(s.substr(1));

    if (isdigit(s[0]) && s[1] == '(') {
        int repeat = s[0] - '0';
        int closePos = findClosingBracket(s, 2);
        string expandedPart = expand(s.substr(2, closePos - 2));
        return multiply(expandedPart, repeat) + expand(s.substr(closePos + 1));
    }

    return expand(s.substr(1));  // Bỏ qua ký tự không hợp lệ
}

int main(){
    cout << expand("2(ab3(cde)x)") << "\n"; //abcdecdecdexabcdecdecdex
    cout << expand("2(x0(y))3(z)") << "\n"; //xxzzz
    return 0;
}