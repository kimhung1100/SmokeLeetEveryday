#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> ans;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1]-a[0] < b[1]-b[0] || (a[1]-a[0] == b[1]-b[0] && a[0] < b[0]);
        });
        vector<int> queries_unsorted(queries.begin(), queries.end());
        vector<int> queries_loc(queries.size(),-1);
        vector<bool> loc(queries.size(),false);
        sort(queries.begin(), queries.end());
        for(int i = 0; i < queries.size(); i++){
            for(int j = 0; j < queries.size(); j++){
                if(queries[i] == queries_unsorted[j] && loc[j] == false){
                    queries_loc[i] = j;loc[j] = true; break;
                     // save the location of the query in the unsorted queries
                }
            }
        }
        int begin = 0;
        for(int i = 0; i < queries.size(); i++){
            int minI = INT_MAX;
            int j = begin;
            for(; j < intervals.size(); j++){
                if(queries[i] >= intervals[j][0] && queries[i] <= intervals[j][1]){
                    minI = min(minI, intervals[j][1]-intervals[j][0] + 1);
                    break;
                }
            }
            minI == INT_MAX ? ans.push_back(-1) : ans.push_back(minI);
            if(minI != INT_MAX){
                begin = j;
            }
        }
        vector<int> realAns(queries.size());
        for(int i = 0; i < queries.size(); i++){
            realAns[queries_loc[i]] = ans[i];
        }
        return realAns;
    }
};
int main(){
    vector<vector<int>> intervals = {{4,5},{5,8},{1,9},{8,10},{1,6}};
    vector<int> queries = {7,9,3,9,3};
    Solution s;
    vector<int> ans = s.minInterval(intervals, queries);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}