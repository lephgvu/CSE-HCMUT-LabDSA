#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// template<class T>
// class Stack {
// protected:
//     DLinkedList<T> list;
// public:
//     Stack() {}
    
//     void push(T item) {
//         list.add(item);
//     }
    
//     T pop() {
//         if (list.empty()) throw "Stack is empty";
//         return list.removeAt(list.size() - 1);
//     }
    
//     T top() {
//         if (list.empty()) throw "Stack is empty";
//         return list.get(list.size() - 1);
//     }
    
//     bool empty() {
//         return list.empty();
//     }
    
//     int size() {
//         return list.size();
//     }
    
//     void clear() {
//         list.clear();
//     }
// };
int baseballScore(string ops){
    stack<int> st;
    
    for (char c : ops) {
        if (isdigit(c)) {
            st.push(c - 48);
        }
        else {
            switch (c) {
                case 'C':
                    st.pop();
                    break;
                case 'D':
                    st.push(st.top() * 2);
                    break;
                case '+':
                    int tmp = st.top();
                    st.pop();
                    int sum = tmp + st.top();
                    st.push(tmp);
                    st.push(sum);
                    break;
            }
        }
    }
    
    int ans = 0;

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    return ans;
}

vector<int> nextGreater(vector<int>& arr){
    int n = arr.size();
    vector<int> newArr(n, -1);
    stack<int> s;
    for(int i = n - 1; i >= 0; --i) {
        while(!s.empty() && arr[i] >= arr[s.top()])
            s.pop();
        
        if(!s.empty()) newArr[i] = arr[s.top()];
        s.push(i);
    }
    return newArr;
}

int main() {
    int N;
    cin >> N;
    vector<int> nums(N);
    for(int i = 0; i < N; i++) cin >> nums[i];
    vector<int> greaterNums = nextGreater(nums);
    for(int i : greaterNums) 
        cout << i << ' ';
    cout << '\n';   
    return 0;
}
#endif
