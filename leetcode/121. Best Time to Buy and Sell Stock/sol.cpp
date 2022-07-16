#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int min = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
            ans = max(ans, prices[i]-min);
            if(prices[i] < min){
                min = prices[i];
            }
            
        }
        return ans;
    }
};
int main(){
    vector<int> prices = {2,4,1};
    Solution s;
    cout << s.maxProfit(prices) << endl;
    return 0;
}