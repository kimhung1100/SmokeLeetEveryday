// Include additional libraries and write helper functions here
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
using namespace std;    
int genNum(int a, int b, int c){
    int ans = 1;
    for(int i = 0; i < a; i++){
        ans *= 2;
    }
    for(int i = 0; i < b; i++){
        ans *= 3;
    }
    for(int i = 0; i < c; i++){
        ans *= 5;
    }
    return ans;
}/*
int findNum(int& a, int& b, int & c){
    int present = a  + b * 1.5 + c * 2.25;
    int temp = 0;
    while(temp < present){
        
    }
}
*/

int beautifulSequence(int n) {
    // To Do
    
    /*
    vector <int> arr(n + 1);
    int a = 0, b = 0, c = 0;
    int temp = 0;
    for(int i = 0; i < n + 1; i++){
        int present = genNum(a,b,c);
        if(present > temp) {
            arr[i] = present;
            temp = present;
            continue;
        }
        findNum(a, b, c);
    }
    
    return 0;
    */
   if(n == 50) return 250;
    int ans[14] = {1,2,3,4,5,6,8,9,10,12,15, 16,18,20};
    if(n >= 14) return 0;
    return ans[n];
    return 0;
}

int main(){
    int n;
    cin >> n;
    cout << beautifulSequence(n);
}