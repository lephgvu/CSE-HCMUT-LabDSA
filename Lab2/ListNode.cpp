#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *left;
    ListNode *right;
    ListNode(int x = 0, ListNode *l = nullptr, ListNode* r = nullptr) : val(x), left(l), right(r) {}
};

ListNode* init(int* arr, int size, unordered_map<ListNode*, int>& nodeValue) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    nodeValue[head] = arr[0];
    ListNode* prev = head;
    for (int i = 1; i < size; i++) {
        ListNode* node = new ListNode(arr[i]);
        nodeValue[node] = arr[i];
        prev->right = node;
        node->left = prev;
        prev = node;
    }
    return head;
}

void printList(ListNode* head, unordered_map<ListNode*, int>& nodeValue) {
    while (head) {
        cout << nodeValue[head] << " ";
        head = head->right;
    }
    cout << endl;
}

void freeMem(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->right;
        delete temp;
    }
}

ListNode* reverse(ListNode* head, int a, int b) {
    // Kiểm tra điều kiện nếu danh sách rỗng hoặc a == b
    if (!head || a == b) return head;
    
    // Duyệt từ node head đến vị trí a để tìm node start
    ListNode* start = head;
    for (int i = 1; i < a; i++)
        start = start->right;
    
    // Tìm node end
    ListNode* end = start;
    for(int i = a; i < b; i++){
        end = end->right;
    }
    
    // Xác định các node liền kề với phần đảo ngược 
    ListNode* prev = start->left;
    ListNode* next = end->right;
    
    // Đảo ngược các con trỏ trong đoạn từ start đến end 
    ListNode* curr = start;
    ListNode* temp = nullptr;
    while (curr != next) {
        temp = curr->right;
        curr->right = curr->left;
        curr->left = temp;
        curr = temp;
    }
    
    // Kết nối lại danh sách
    if (prev) prev->right = end;
    else head = end;
    start->right = next;
    if (next) next->left = start;
    
    return head;
}

int main() {
    int size;
    cin >> size;
    int* list = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> list[i];
    }
    int a, b;
    cin >> a >> b;
    unordered_map<ListNode*, int> nodeValue;
    ListNode* head = init(list, size, nodeValue);
    ListNode* reversed = reverse(head, a, b);
    try {
        printList(reversed, nodeValue);
    } catch (char const* err) {
        cout << err << '\n';
    }
    freeMem(reversed);
    delete[] list;
    return 0;
}
