#include <bits/stdc++.h>
using namespace std;
// Time: O(n)
// Space: O(n)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        bool inserted = false;
        if(intervals.size() == 0){
            ans.push_back(newInterval);
            return ans;
        }
        for(int i =0 ; i < intervals.size(); i++){
            if(intervals[i][1] < newInterval[0]){
                ans.push_back(intervals[i]);
            } // not merge
            else if(intervals[i][0] > newInterval[1]){
                if(!inserted){
                    ans.push_back(newInterval);
                    inserted = true;
                }
                ans.push_back(intervals[i]);
            }
            else{
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
                if(intervals[i][0] >= newInterval[0] && intervals[i][1] <= newInterval[1]){
                    continue; // | |  |  |
                }
                ans.push_back(newInterval);
                inserted = true;
            }
        }
        if(ans.empty() || !inserted){
            ans.push_back(newInterval);
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<vector<int>> intervals = {{1,5}};
    vector<int> newInterval = {6,8};
    vector<vector<int>> ans = s.insert(intervals, newInterval);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}