#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int checkHour(vector<int> & piles, int & k, int & h){
        int ans = 0;
        for(int i = 0; i < piles.size(); i++){
            int temp = ceil((double)piles[i]/h);
            ans += temp;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int l = 0, r = piles.back();
        vector <int> array(piles[r] + 1);
        for(int i = 0; i < piles.size(); i++){
            array[i] = i;
        }
        int mid = (l + r) / 2;
        while(l <= r){
            if(checkHour(piles, mid, h) <= h){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return l;
    }
};
int main(){
    Solution s;
    vector<int> piles = {3,6,7,11};
    int h = 8;
    cout << s.minEatingSpeed(piles, h) << endl;
    return 0;
}