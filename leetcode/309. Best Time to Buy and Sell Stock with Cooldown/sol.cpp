#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1) return 0;
        int ans = 0;
        int min = INT_MAX;
        bool cooldown = false;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] > min && cooldown == false){
                ans+=prices[i]-min;
                cooldown = true;
            }else if(cooldown == true){
                min = prices[i];
                cooldown = false;
            }else{
                min = prices[i];
            }
        }
        return ans; 
    }
};
int main(){
    vector<int> prices = {1,2,3,0,2};
    Solution s;
    cout << s.maxProfit(prices) << endl;
    return 0;
}
