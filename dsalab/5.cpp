#include <bits/stdc++.h>
using namespace std;

int maximumProduct(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    return max(nums[0] * nums[1] * nums[n - 1],
               nums[n - 1] * nums[n - 2] * nums[n - 3]);
}    

int main(){
    vector<int>nums{-22,-39,48,-24,42,31,-49,-12,43,9,-37,-37,27,-31,-12,-23,-4,38,20,36,-11,22,-20,-17,34,-49,46,-15,-21,38,-29,7,49,21,-15,-7,-46,39,32,48,-2,45,13,-25,16,3,-46,-38,-8,24,0,31,49,30,16,33,-17,13,21,13,1,-6,22,0,-35,10,-4,-30,-1,-22,20,47,25,-17,25,-9,37,29,-45,31,-44,5,12,-45,37,31,-10,-30,-6,-39,-15,-3,-43,10,-1,-27,-30,45,45,19};
    cout << maximumProduct(nums);
}