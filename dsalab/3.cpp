#define MAX 100000 + 5

#include <bits/stdc++.h>
using namespace std;
int V, E;
bool visited[MAX];
//vector<int> graph[MAX];

void DFS(int scr, vector<vector<int>>& graph) {
    stack<int> s;
    visited[scr] = true;
    s.push(scr);

    while (!s.empty()) {
        int u = s.top();
        s.pop();

        for (int &v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                s.push(v);
            }
        }
    }
}
int connectedComponents(vector<vector<int>>& edges) {
    // STUDENT ANSWER
    int V = edges.size();
    int count = 0;
    fill_n(visited, V + 1, false);
    for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                count++;
                DFS(i,edges);
            }
        }
    return count;
}
int main(){
    vector<vector<int>> graph {
	{1},
	{0, 4},
	{ },
	{ },
	{1}
};
cout << connectedComponents(graph);
}