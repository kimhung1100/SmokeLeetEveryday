<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = (nums[0] ^ nums[0]);
        for(int i = 0; i < nums.size(); i ++){
            for(int j = i; j < nums.size(); j ++){
                int temp = nums[i]^nums[j];
                if(temp > ans) {ans = temp;}
            }
    
        }
        return ans;
    }

};

int main(){
    vector <int> ar = {3,10,5,25,2,8};
    Solution a;
    cout << a.findMaximumXOR(ar);
=======
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = (nums[0] ^ nums[0]);
        for(int i = 0; i < nums.size(); i ++){
            for(int j = i; j < nums.size(); j ++){
                int temp = nums[i]^nums[j];
                if(temp > ans) {ans = temp;}
            }
    
        }
        return ans;
    }

};

int main(){
    vector <int> ar = {3,10,5,25,2,8};
    Solution a;
    cout << a.findMaximumXOR(ar);
>>>>>>> 30ab1405424e301735fbce3f9a5fb163c529c7b9
}