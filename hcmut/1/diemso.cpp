#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int n; 
    cin >> n;
    vector <string> arr(2*n);
    for(int i = 0; i < n; i++){
        string line;
        cin.ignore();
        getline(cin, line);
    }
}