#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int ans = nums[0];
        int cur = nums[0];
        for(int i = 1; i < nums.size(); i++){
            cur = max(nums[i], cur+nums[i]);
            ans = max(ans, cur);
        }
        return ans;
    }
};
int main(){
    vector<int> nums = {5,4,-1,7,8};
    Solution s;
    cout << s.maxSubArray(nums) << endl;
    return 0;
}