#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int it1 = 0, it2 = 1, it3 = 2;
        for( ;it1 <nums.size() - 2;it1++){
            it2 = it1 + 1;
            it3 = nums.size() - 1;
            if(it1 != 0 && nums[it1] == nums[it1 - 1]) continue;
            while(it2 < it3){
                int sum = nums[it1] + nums[it2] + nums[it3];
                if(sum == 0){
                    if(ans.size() == 0)
                        ans.push_back({nums[it1], nums[it2], nums[it3]});
                    else if(ans[ans.size() - 1][0] != nums[it1] || ans[ans.size() - 1][1] != nums[it2] || ans[ans.size() - 1][2] != nums[it3]){
                        ans.push_back({nums[it1], nums[it2], nums[it3]});
                    }
                    it2++;
                }else if(sum > 0){
                    it3--;
                }else{
                    it2++;
                }
            }
        }
        
        return ans;
    }
};
int main(){
    vector<int> nums = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    Solution s;
    vector<vector<int>> ans = s.threeSum(nums);
    for(auto i: ans){
        for(auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}