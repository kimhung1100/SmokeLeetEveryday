#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector <int> count(1000000, 0);
        vector <int> countNeg(1000000, 0);
        int max = -1000000;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= 0){
                count[nums[i]]++;
            }else{
                countNeg[nums[i]*-1]++;
            }
            if(nums[i] > max) max = nums[i];
        }
        if(k == 1) return max;
        // positive
        int i = max;
        if (i>=0){
            for(int i = max; i > -1; i--) {
                if(count[i] == 0) continue;
                else {
                    if(k>count[i]) k -= count[i];
                    else {
                        return i;
                    }
                    
                }
            }
        }
        // negative
        i = 0;
        for(int i = 0; i < 1000000; i++) {
            if(countNeg[i] == 0) continue;
            else {
                if(k>countNeg[i]) k -= countNeg[i];
                else {
                    return i*-1;
                }
                
            }
        }
        return -100;
    }
};

int main(){
    Solution s;
    vector<int> nums = {-1,-1};
    int sol = s.findKthLargest(nums, 2);
    cout << sol;
    return 0;
}