#include <iostream>
#include <vector>

using namespace std;

vector<int> updateArrayPerRange(vector<int> &nums, vector<vector<int>> &operations)
{   
    for(auto op : operations) {
        int op[0] = L, op[1] = R, op[2] = X;
        for(int i = L; i <= R; i++) {
            nums[i] += X;
        }
    }
    return nums;
}


int main(){
    vector<int> nums {13, 0, 6, 9, 14, 16};
    vector<vector<int>> operations {{5, 5, 16}, {3, 4, 0}, {0, 2, 8}};
    printVector(updateArrayPerRange(nums, operations));
    // [21, 8, 14, 9, 14, 32]
    return 0;
}