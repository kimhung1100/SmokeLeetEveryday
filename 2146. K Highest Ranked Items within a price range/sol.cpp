#include <bits/stdc++.h>
using namespace std;
vector <int> mv1 = {0,0,1,-1};
vector <int> mv2 = {1,-1,0,0};
vector<vector<int>> dis;
struct Point{
    int x, y, point;
    Point(int x, int y, int point){
        this->x = x;
        this->y = y;
        this->point = point;
    }
    friend bool operator < (const Point& a, const Point& b){
        return a.point < b.point;
    }
    friend bool operator > (const Point& a, const Point& b){
        return a.point > b.point;
    }

};

class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        dis.resize(grid.size(), vector<int>(grid[0].size(), 0));
        priority_queue <Point> pq;
        // point and position
        // point = 1000 * dis[a][b] + 100*grid[a][b] + 10*a + 1*b;
        // lesser point higher rank
        // dfs
        queue <pair<int, int>> q;
        q.push(make_pair(start[0], start[1]));
        while(!q.empty()){
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            if(grid[a][b] >= pricing[0] && grid[a][b] <= pricing[1]){
                int point = 1000 * dis[a][b] + 100*grid[a][b] + 10*a + 1*b;
                pq.push(Point(a, b, point));
            }
            for(int i = 0; i < 4; i++){
                int x = a + mv1[i];
                int y = b + mv2[i];
                if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] != 0 && dis[x][y] == 0){
                    dis[x][y] = dis[a][b] + 1;
                    q.push(make_pair(x, y));
                }
            }
        }
        // end dfs
        vector<vector<int>> ans;
        while(pq.size() > k)
            pq.pop();
        while(!pq.empty()){
            ans.push_back({pq.top().x, pq.top().y});
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    vector<vector<int>> grid = {{1,2,0,1},{1,3,3,1},{0,2,5,1}};
    vector<int> pricing = {2,3};
    vector<int> start = {2,3};
    int k = 2;
    Solution s;
    vector<vector<int>> ans = s.highestRankedKItems(grid, pricing, start, k);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    return 0;
}