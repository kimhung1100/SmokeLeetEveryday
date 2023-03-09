#include <bits/stdc++.h>
using namespace std;
// T.C = O(n)
// S.c = O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int>m;
        for(int i = 0; i < nums.size(); i++){
            if(m.find(nums[i]) != m.end()){
                return true;
            }else{
                m[nums[i]] = 1;
            }
        }
        return false;
    }
};
int main(){
    vector<int> nums = {1,2,3,4};
    Solution s;
    cout << s.containsDuplicate(nums) << endl;
    return 0;
}