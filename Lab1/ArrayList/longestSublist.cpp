#include <iostream>
#include <vector>
using namespace std;

int longestSublist(vector<string>& words) {
    if (words.empty()) return 0; // Mảng rỗng thì trả về 0

    int maxLength = 1, currentLength = 1;

    for (size_t i = 1; i < words.size(); i++) {
        if (words[i][0] == words[i - 1][0]) {
            currentLength++;
        } else {
            if (currentLength > maxLength) maxLength = currentLength;
            currentLength = 1; // Reset lại dãy con mới
        }
    }

    return max(maxLength, currentLength); // So sánh lần cuối trước khi trả về kết quả
}

int main(){
    vector<string> words {"faction", "fight", "and", "are", "attitude"};
    cout << longestSublist(words);
    //3
    return 0;
}