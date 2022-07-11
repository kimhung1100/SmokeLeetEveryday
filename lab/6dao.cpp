// Include additional libraries and write helper functions here
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
using namespace std;
int mv1[4] = {-1,1,0,0};
int mv2[4] = {0,0,-1,1};
bool vis[100 + 1][100 + 1];
bool inGrid(pair<int,int>point, int n, int m){
    int x = point.first;
    int y = point.second;
    if(x >= 0 && x <= n - 1 && y >= 0 && y <= m - 1)
        return true;
    else return false;
}
void dfs(pair<int,int>point, vector<vector<int>>& matrix){
    stack <pair<int, int>> q;
    q.push(point);
    while(!q.empty()){
        pair <int, int> present = q.top();
        q.pop();
        if(vis[present.first][present.second] != false){
            continue;
        }
        vis[present.first][present.second] = true;
        for(int i = 0; i < 4; i++){
            pair<int ,int> neighbor = make_pair(present.first + mv1[i],present.second +mv2[i]);
            if(!inGrid(neighbor,matrix.size(),matrix[0].size()) || matrix[neighbor.first][neighbor.second] == 0)
                continue;
            q.push(neighbor);
        }
    }
}
int islandsInTheOcean(vector<vector<int>>& matrix)  {
    // To Do
    queue <pair<int ,int>> q;
    int count = 0;
    for(unsigned int i = 0; i < matrix.size(); i++){
        for(unsigned int j = 0; j < matrix[i].size(); j++){
            vis[i][j] = false;
            if(matrix[i][j] == 1) 
                q.push(make_pair(i,j));
        }
    }
    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        if(vis[p.first][p.second] == true)
            continue;
        count ++;
        dfs(p,matrix);
    }
    
    return count;
}
int main(){
    int n, m;
cin >> n >> m;
vector<vector<int>> matrix(n, vector<int>(m));
for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) cin >> matrix[i][j];
}
cout << islandsInTheOcean(matrix);
}