
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise = 0;
        int hare = 0;
        for(; ;){
            if(tortoise == hare && tortoise != hare != 0){
                break;
            }
            tortoise ++;
            hare = hare + 2;
        }
        int pt = 0;
        while(nums[pt] != nums[tortoise]){
            pt++;
            tortoise++;
        }
        return nums[pt];
        return -1;
    }
};
int main(){
    vector <int> nums ={1,2,2};
    Solution s;
    cout << s.findDuplicate(nums) << endl;
    return 0;
}