class Solution {
public:
// T.C = O(n^2)
    int lengthOfLIS(vector<int>& nums) {
        int array[nums.size()];
        int max_len = 1;
        for(int i = 0; i < nums.size(); i++){
            array[i] = 1;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    array[i] = max(array[i], array[j] + 1);
                }
            }
            max_len = max(max_len, array[i]);
        }
        return max_len;
    }
};