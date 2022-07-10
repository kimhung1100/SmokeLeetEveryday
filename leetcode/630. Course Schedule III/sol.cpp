#include<bits/stdc++.h>
using namespace std;
class Compare{
public:
    bool operator()(vector<int>& a, vector<int>& b){
        return a[1] > b[1];
    }
};
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<pair<int,int>, Compare> pq;
        for(int i = 0; i < courses.size(); i++){
            pq.push(courses[i]);
        }
        int time = 0;
        int ans = 0;
        while(!pq.empty()){
            if(time + pq.top()[0] <= pq.top()[1]){
                time += pq.top()[0];
                ans++;
                pq.pop();
            }
            else{
                pq.pop();
            }
        }
        return ans;
        return -1;
    }
};
int main(){
    Solution s;
    vector<vector<int>> courses = {{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
    int ans = s.scheduleCourse(courses);
    cout << ans;
    return 0;
}