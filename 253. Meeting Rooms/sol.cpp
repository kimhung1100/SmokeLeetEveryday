<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int max(int &a, int &b) {
        return a > b ? a : b;
    }
    // T.C = O(n^2)
    // M.C = O(n)
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });
        //int ans = 1;
        vector<int> rooms;
        //int roomsInUsed = 0;
        rooms.push_back(intervals[0][1]);
        //roomsInUsed++;
        for(int i = 1; i < intervals.size(); i++) {
            for(int j = 0; j < rooms.size(); j++)
                if(rooms[j] <= intervals[i][0]) {
                    rooms[j] = -1; // room has been used
                    //roomsInUsed--;
                }
             // must use more room
                for(int j = 0; j < rooms.size(); j++) { // find room
                    if(rooms[j] == -1){ // has a free room
                        rooms[j] = intervals[i][1];
                        break;
                    }else{
                        if(j == rooms.size() - 1) { // no free room
                            rooms.push_back(intervals[i][1]);
                            //roomsInUsed++;
                            break;
                        }
                    }
                }
        }
        return rooms.size();
    }
};
int main(){
    Solution s;
    vector<vector<int>> intervals = {{15, 16}, {10, 15}, {16, 25}};
    cout << s.minMeetingRooms(intervals) << endl;
    return 0;
=======
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int max(int &a, int &b) {
        return a > b ? a : b;
    }
    // T.C = O(n^2)
    // M.C = O(n)
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });
        //int ans = 1;
        vector<int> rooms;
        //int roomsInUsed = 0;
        rooms.push_back(intervals[0][1]);
        //roomsInUsed++;
        for(int i = 1; i < intervals.size(); i++) {
            for(int j = 0; j < rooms.size(); j++)
                if(rooms[j] <= intervals[i][0]) {
                    rooms[j] = -1; // room has been used
                    //roomsInUsed--;
                }
             // must use more room
                for(int j = 0; j < rooms.size(); j++) { // find room
                    if(rooms[j] == -1){ // has a free room
                        rooms[j] = intervals[i][1];
                        break;
                    }else{
                        if(j == rooms.size() - 1) { // no free room
                            rooms.push_back(intervals[i][1]);
                            //roomsInUsed++;
                            break;
                        }
                    }
                }
        }
        return rooms.size();
    }
};
int main(){
    Solution s;
    vector<vector<int>> intervals = {{15, 16}, {10, 15}, {16, 25}};
    cout << s.minMeetingRooms(intervals) << endl;
    return 0;
>>>>>>> 30ab1405424e301735fbce3f9a5fb163c529c7b9
}