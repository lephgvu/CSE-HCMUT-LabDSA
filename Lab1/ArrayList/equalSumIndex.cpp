#include <iostream>
#include <vector>
using namespace std;

int equalSumIndex(vector<int>& nums) {
    int totalSum = 0, leftSum = 0;
    
    // Tính tổng tất cả phần tử trong mảng
    for (int i = 0; i < nums.size(); i++){
        totalSum += nums[i];
    }

    // Duyệt từng phần tử để kiểm tra điều kiện
    for (int i = 0; i < nums.size(); i++) {
        int rightSum = totalSum - leftSum - nums[i]; // Tính tổng bên phải
        if (leftSum == rightSum) {
            return i; // Tìm thấy chỉ số thỏa mãn
        }
        leftSum += nums[i]; // Cập nhật tổng bên trái
    }

    return -1; // Không tìm thấy vị trí nào thỏa mãn
}

int main(){
    vector<int> nums {3, 5, 2, 7, 6, 4};
    cout << equalSumIndex(nums);
    //3
    return 0;
}