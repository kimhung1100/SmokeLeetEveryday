#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> intToBin(int n){
        vector<int> res;
        while(n){
            res.push_back(n%2);
            n/=2;
        }
        return res;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> cur;
        int k = 0;
        while(k < pow(2,nums.size())){
            vector<int> tmp = intToBin(k);
            vector<int> temp2;
            tmp.resize(n);
            for(int i = 0; i < n; i++){
                if(tmp[i] == 1){
                    temp2.push_back(nums[i]);
                }
                else{
                    tmp[i] = 0;
                }
            }
            res.push_back(temp2);
        }
        return res;
    }
};
int main(){

}