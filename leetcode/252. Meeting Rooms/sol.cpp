<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < intervals[i-1][1]) return false;
        }
        return true;
    }
=======
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < intervals[i-1][1]) return false;
        }
        return true;
    }
>>>>>>> 30ab1405424e301735fbce3f9a5fb163c529c7b9
};