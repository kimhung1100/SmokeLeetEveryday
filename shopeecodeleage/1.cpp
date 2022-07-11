#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int mv1[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
vector <vector<pair<int ,int>>> tunnel;
//create bfs funct
int bfs(vector<vector<int>>& map, int n, int m, int x, int y)
{
    queue<pair<int,int>> q;
    vector<vector<int>> step(n, vector<int>(m));
    //fill step with -1
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            step[i][j] = -1;
        }
    }
    //push start point
    q.push({x,y});
    step[x][y] = 0;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + mv1[i][0];
            int ny = y + mv1[i][1];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && step[nx][ny] == -1)
            {
                q.push({nx,ny});
                step[nx][ny] = step[x][y] + 1;
                /*
                if(nx == n - 1 && ny == m - 1)
                {
                    ans = step[nx][ny];
                    return 0;
                }
                */
               if(map[nx][ny] != 0){
                   for(int v = nx; v < n; v++){
                
                       for(int u = ny; u < m; u++)
                       {
                           if(map[v][u] == map[nx][ny] && v!= nx && u != ny){
                               if(step[v][u] < step[nx][ny]){
                                step[v][u] = step[nx][ny];
                                q.push({v,u});
                               }
                           }
                           
                       }
                   }
                   
               }
               
            }
            
        }
    }
    return step[n - 1][m - 1];
}
int main(){
    int n, m;
    cin >> n >> m;
    // create 2d vector array
    vector<vector<int>> arr(n, vector<int>(m));
    // fill the array
    
    tunnel.resize(100);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            if(arr[i][j] != 0){
                tunnel[i+1].push_back({i,j});
            }
        }
    }
    cout << bfs(arr,n,m,0,0);
}