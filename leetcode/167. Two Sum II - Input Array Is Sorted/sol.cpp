#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(int i = 0; i <numbers.size(); i++){
            if(m.find(target - numbers[i]) == m.end()) // dont finded
                m.insert({numbers[i],i});
            else{
                ans.push_back(m[target - numbers[i]] +1);
                ans.push_back(i+1);
                break;
            }
        }
        return ans;
    }
};
int main(){
    vector<int> numbers = {2,7,11,15};
    int target = 9;
    Solution sl;
    vector<int> ans = sl.twoSum(numbers,target);
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}