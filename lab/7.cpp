#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
using namespace std;
// Include additional libraries and write helper functions here

vector<int> smallerNumbers(vector<int>& nums) {
    // To Do
    vector <int> ans(nums.size());
    fill_n(ans.begin(),nums.size(),0);
    for(int i = 0; i < (int)nums.size(); i++){
        for(int j = 0; j < (int)nums.size(); j++){
            if(nums[j] < nums[i]){
                ans[i] ++;
            } 
        }
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    vector<int> res = smallerNumbers(nums);
    for(int i : res) cout << i << ' ';
    return 0;
}