#include <iostream>
#include <vector>
using namespace std;
// write counting sort function
void countSort(vector<int> &A, int k, int exp){
    vector<int> count(k+1, 0);
    for(int i = 0; i < A.size(); i++){
        count[A[i]]++;
    }
    for(int i = 1; i <= k; i++){
        count[i] += count[i-1];
    }
    vector<int> B(A.size(), 0);
    for(int i = A.size()-1; i >= 0; i--){
        B[count[A[i]]-1] = A[i];
        count[A[i]]--;
    }
    for(int i = 0; i < A.size(); i++){
        A[i] = B[i];
    }
}
// write radix sort function using counting sort
void radixSort(vector<int> &A, int k){
    int max = A[0];
    for(int i = 1; i < A.size(); i++){
        if(A[i] > max) max = A[i];
    }
    for(int i = 1; max/i > 0; i *= 10){
        countSort(A,k, i);
    }
}
int main(){
    vector <int> arr = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(arr) / sizeof(arr[0]);
     
      // Function Call
      radixSort(arr, 8);
    for (size_t i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    
}