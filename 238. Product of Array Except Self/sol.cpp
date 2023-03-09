#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixProduct(nums.size(), 1);
        vector<int> postfixProduct(nums.size(), 1);
        for(int i = 0; i < nums.size(); i++)
            prefixProduct[i] = (i == 0) ? 1 : prefixProduct[i - 1] * nums[i - 1];
        for(int i = nums.size() - 1; i >= 0; i--)
            postfixProduct[i] = (i == nums.size() - 1) ? 1 : postfixProduct[i + 1] * nums[i + 1];
        vector<int> result(nums.size());
        for(int i = 0; i < nums.size(); i++){
            result[i] = prefixProduct[i] * postfixProduct[i];
        }
        return result;
    }
};
int main(){
    Solution s;
    vector<int> nums = {1,2,3,4};
    vector<int> result = s.productExceptSelf(nums);
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}