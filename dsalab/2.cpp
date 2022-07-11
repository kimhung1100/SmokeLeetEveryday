#include <bits/stdc++.h>
using namespace std;
int boxRequire(vector<int>& piles, int k) {
    int ans = 1;
    vector <int> temp = piles;
    for (int i = 0; i < k; i++){
        for(unsigned int j = 0; j < piles.size(); j++){
            temp[j] -= ans;
        }
    }
}
int main(){
    int k = 11;
    vector<int> piles{5,1,4,3,5};
    cout << boxRequire(piles, k);
}