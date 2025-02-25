#include <iostream>
#include <vector>

using namespace std;

vector<int> updateArrayPerRange(vector<int> &nums, vector<vector<int>> &operations)
{   
    for(auto op : operations) 
    {
        int L = op[0], R = op[1], X = op[2]; 
        for (int j = L; j <= R; j++) 
            nums[j] += X;
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