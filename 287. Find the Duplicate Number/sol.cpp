#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise = 0;
        int hare = 0;;
        for( ; tortoise < nums.size(); tortoise++){
            if(nums[tortoise] == nums[hare] && tortoise != hare)
                return nums[tortoise];
            hare +=2;
            if(hare >= nums.size())
                hare = 0;
            if(nums[tortoise] == nums[hare] && tortoise != hare)
                return nums[tortoise];
            if(tortoise == nums.size() - 1)
                tortoise = -1;
        }
        return -1;
    }
};
int main(){
    vector <int> nums ={1,2,2};
    Solution s;
    cout << s.findDuplicate(nums) << endl;
    return 0;
}