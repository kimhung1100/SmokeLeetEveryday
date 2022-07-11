#include <bits/stdc++.h>
using namespace std;
// T.C : O(nlogn)
// M.C : O(n)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0 || intervals.size() == 1){
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });
        vector <vector<int>> ans;
        for(int i = 0; i < intervals.size()-1; i++){
            if(intervals[i+1][0] <= intervals[i][1]){
                intervals[i+1][1] = max(intervals[i][1], intervals[i+1][1]);
                intervals[i+1][0] = intervals[i][0];
            }else{
                ans.push_back(intervals[i]);
            }
        }
        ans.push_back(intervals[intervals.size()-1]);
        return ans;
    }
};
int main(){
    Solution s;
    vector<vector<int>> intervals = {{1,3},{0,0}};
    vector<vector<int>> ans = s.merge(intervals);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}