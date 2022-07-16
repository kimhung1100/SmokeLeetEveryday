#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    class comp{
        public:
        bool operator()(const vector<int>& a, const vector<int>& b){
            return a[1]-a[0] > b[1]-b[0] || (a[1]-a[0] == b[1]-b[0] && a[0] > b[0]);
        }
    };
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> ans;
        priority_queue<vector<int>,vector<vector<int>>, comp> pq;
        for(int i = 0; i < intervals.size(); i++){
            pq.push(intervals[i]);
        }

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
            priority_queue<vector<int>,vector<vector<int>>, comp> pqTemp = pq;
            while(!pqTemp.empty()){
                if(queries[i] >= pqTemp.top()[0] && queries[i] <= pqTemp.top()[1]){
                    ans.push_back(pqTemp.top()[1]-pqTemp.top()[0] + 1);
                    break;
                }else{
                    pqTemp.pop();
                    if(pqTemp.empty()){
                        ans.push_back(-1);
                        break;
                    }
                }
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
    vector<vector<int>> intervals = {{2,3},{2,5},{1,8},{20,25}};
    vector<int> queries = {2,19,5,22};
    Solution s;
    vector<int> ans = s.minInterval(intervals, queries);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}