<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
/*
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int array[10001];
        fill_n(array, 10001, 0);
        for(int i = 0; i < intervals.size(); i++){
            array[intervals[i][0]] = 1;//begin
            array[intervals[i][1]] = 2;//end
        }
        array[newInterval[0]] = 1;
        array[newInterval[1]] = 2;
        int begin= -1, end = -1;
        bool remain = false;
        for(int i = 0; i <1001; i++){
            if(array[i] == 1){
                if(remain == false){
                    begin = i;
                    remain = true;
                }
                else if(end == -1) continue;
                else{
                    ans.push_back({begin,end});
                    begin = i;
                    end = -1;
                    remain = false;
                }
            }
            if(array[i] == 2){
                end = i;
            }
        }
        if(begin != -1 && end != -1){
            ans.push_back({begin, end});
        }
        
        return ans;
    }
};
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int array[10001];
        fill_n(array, 10001, 0);
        int begin= -1, end = -1;
        for(int i = 0; i < intervals.size(); i++){
            begin = intervals[i][0];
            end = intervals[i][1];
            if(begin == end){
                array[begin] == 2;
            }else
                for(int j = begin; j <= end; j++){
                    array[j] = 1;
                }
        }
        begin = newInterval[0];
        end = newInterval[1];
        if(begin == end){
            array[begin] = 2;
        }else
            for(int i = newInterval[0]; i <= newInterval[1]; i++){
                array[i] = 1;
            }
        begin = end = -1;
        for(int i = 0; i < 1001; i++){
            if(array[i] == 1 && begin == -1){
                begin = i;
            }else if(array[i] == 1 && begin != -1){
                continue;
            }else if(array[i] == 0 && begin != -1){
                end = i-1;
                ans.push_back({begin, end});
                begin = -1;
                end = -1;
            }else if(array[i] == 0 && begin == -1){
                continue;
            }else if(array[i] == 2 && begin == -1){
                end = i;
                ans.push_back({i, end});
                begin = -1;
                end = -1;
            }
        }
        return ans;
    }
};
int main(){
    vector<vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> newInterval = {4,8};
    Solution s;
    vector<vector<int>> ans = s.insert(intervals, newInterval);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    return 0;
=======
#include <bits/stdc++.h>
using namespace std;
/*
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int array[10001];
        fill_n(array, 10001, 0);
        for(int i = 0; i < intervals.size(); i++){
            array[intervals[i][0]] = 1;//begin
            array[intervals[i][1]] = 2;//end
        }
        array[newInterval[0]] = 1;
        array[newInterval[1]] = 2;
        int begin= -1, end = -1;
        bool remain = false;
        for(int i = 0; i <1001; i++){
            if(array[i] == 1){
                if(remain == false){
                    begin = i;
                    remain = true;
                }
                else if(end == -1) continue;
                else{
                    ans.push_back({begin,end});
                    begin = i;
                    end = -1;
                    remain = false;
                }
            }
            if(array[i] == 2){
                end = i;
            }
        }
        if(begin != -1 && end != -1){
            ans.push_back({begin, end});
        }
        
        return ans;
    }
};
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int array[10001];
        fill_n(array, 10001, 0);
        int begin= -1, end = -1;
        for(int i = 0; i < intervals.size(); i++){
            begin = intervals[i][0];
            end = intervals[i][1];
            if(begin == end){
                array[begin] == 2;
            }else
                for(int j = begin; j <= end; j++){
                    array[j] = 1;
                }
        }
        begin = newInterval[0];
        end = newInterval[1];
        if(begin == end){
            array[begin] = 2;
        }else
            for(int i = newInterval[0]; i <= newInterval[1]; i++){
                array[i] = 1;
            }
        begin = end = -1;
        for(int i = 0; i < 1001; i++){
            if(array[i] == 1 && begin == -1){
                begin = i;
            }else if(array[i] == 1 && begin != -1){
                continue;
            }else if(array[i] == 0 && begin != -1){
                end = i-1;
                ans.push_back({begin, end});
                begin = -1;
                end = -1;
            }else if(array[i] == 0 && begin == -1){
                continue;
            }else if(array[i] == 2 && begin == -1){
                end = i;
                ans.push_back({i, end});
                begin = -1;
                end = -1;
            }
        }
        return ans;
    }
};
int main(){
    vector<vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> newInterval = {4,8};
    Solution s;
    vector<vector<int>> ans = s.insert(intervals, newInterval);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    return 0;
>>>>>>> 30ab1405424e301735fbce3f9a5fb163c529c7b9
}