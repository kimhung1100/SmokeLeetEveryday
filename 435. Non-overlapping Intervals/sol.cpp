#include <bits/stdc++.h>
using namespace std;
// T.C: O(nlog(n) + n)
class Solution {
public:

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int ans = 0;
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < end) { // overlap
                ans++;
                end = min(end, intervals[i][1]); // cut off the longer one
            } else {
                end = intervals[i][1]; // update end
            }
        }
        return ans;
    }
    
           
        
    
};

int main(){
    vector<vector<int>> intervals = {{-52,31},{-73,-26},{82,97},{-65,-11},{-62,-49},{95,99},{58,95},{-31,49},{66,98},{-63,2},{30,47},{-40,-26}};
    Solution s;
    cout << s.eraseOverlapIntervals(intervals) << endl;
    return 0;
}