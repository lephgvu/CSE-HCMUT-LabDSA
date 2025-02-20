#include <iostream>

using namespace std;

int findMax(int* arr, int length)
{
    if(length == 1) return arr[0];
    
    int max = findMax(arr + 1, length - 1);
    return (arr[0] >= max) ? arr[0] : max;
}

int main(){
    	
int arr[] = {291,-444,-456,199,465,31,118,-16,103,-23,
            199,342,291,374,-206,-383,-15,-286,-216,-287,
            155,310,-345,-444,-254,-7,304,-99,-143,-456,-349,
            154,-38,-60,166,-40,256,-107,-31,-454,486,270,-458,
            -367,258,310,-342,-405,-361};
cout << findMax(arr, 49);
    return 0;
}