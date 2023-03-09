#include<bits/stdc++.h>
using namespace std;
// thay vi bruteforce tu 1, bin search tu 1 den max, tim min

// time : n log m -> n # piles, m max of piles
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 0; // min and max of k
        for(auto k : piles){
            r = max (r, k);
        }
        int res = r;
        while(l <= r){
            int k = l + (r-l)/2;
            int cnt = 0;
            for(int i = 0;  i < piles.size(); i++){
                cnt += ceil((double)piles[i]/k);
            }
            if(cnt <= h){
                res = min(res, k);
                r = k - 1;
            }
            else
                l = k + 1;
        }
        return res;
    }
};
int main(){
    Solution s;
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    cout << s.minEatingSpeed(piles, h) << endl;
    return 0;
}