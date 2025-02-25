#include <iostream>
#include <vector>

using namespace std;

bool consecutiveOnes(vector<int>& nums) {
    if (nums.empty()) return true; // Nếu mảng rỗng thì trả về true
    int first = -1, last = -1; // Vị trí đầu và cuối xuất hiện số 1

    // Xác định vị trí của số 1 đầu tiên và cuối cùng
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
            if (first == -1) first = i; // Lưu vị trí số 1 đầu tiên
            last = i; // Cập nhật vị trí số 1 cuối cùng
        }
    }

    // Nếu không tìm thấy số 1 nào, trả về true
    if (first == -1) return true;

    // Kiểm tra xem từ first đến last có bị gián đoạn không
    for (int i = first; i <= last; i++) {
        if (nums[i] != 1) return false;
    }

    return true;
}

int main(){
    vector<int> nums {0, 1, 1, 1, 9, 8};
    cout << consecutiveOnes(nums);
    //1
    return 0;
}