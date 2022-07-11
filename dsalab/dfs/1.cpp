#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
bool visited[MAX];
class Adjacency
{
private:
	list<int> adjList;
	int size;
public:
	Adjacency() {}
	Adjacency(int V) {}
	void push(int data)
	{
		adjList.push_back(data);
		size++;
	}
	void print()
	{
		for (auto const &i : adjList)
			cout << " -> " << i;
	}
	void printArray()
	{
		for (auto const &i : adjList)
			cout << i << " ";
	}
	int getSize() { return adjList.size(); }
	int getElement(int idx) 
	{
		auto it = adjList.begin();
		advance(it, idx);
		return *it;
	}
};
class Graph
{
private:
	int V;
	Adjacency *adj;

public:
	Graph(int V)
	{
		this->V = V;
		adj = new Adjacency[V];
	}
	
	void addEdge(int v, int w)
	{
		adj[v].push(w);
		//adj[w].push(v);
	}
	
    void printGraph()
	{
		for (int v = 0; v < V; ++v)
		{
			cout << "\nAdjacency list of vertex " << v << "\nhead ";
			adj[v].print();
		}
	}
	void DFSrecur(Adjacency* ans, int point){
	    ans->push(point);
        visited[point] = true;
        for(int i = 0; i < adj[point].getSize(); i++){
            int neighbor = adj[point].getElement(i);
            if(visited[neighbor] == false){
                DFSrecur(ans, neighbor);
            }
        }
	}
	Adjacency *DFS(int v)
    {
        // v is a vertex we start DFS
        Adjacency* ans = new Adjacency();
        fill_n(visited, V, false);
        visited[v] = true;
        DFSrecur(ans, v);
        return ans;
	}
    Adjacency *DFSstack(int v)
    {
        // v is a vertex we start DFS
        Adjacency* ans = new Adjacency();
        fill_n(visited, V, false);
        //visited[v] = true;
        stack <int> st;
        st.push(v);
        while(!st.empty()){
            int p = st.top();
            st.top();
            if(visited[p] == true) continue;
            ans->push(p);
            visited[p] = true;
            cout << p << " ";
            for(int i = 0; i < adj[p].getSize(); i++){
                int neighbor = adj[p].getElement(i);
                if(visited[neighbor] == false){
                    st.push(neighbor);
                    //visited[neighbor] = true;
                }
            }
        }
        return ans;
	}
};
int main(){
    int V = 9, visited = 0;

Graph g(V);
Adjacency *arr;
int edge[][2] = {{0,1}, {0,2}, {1,4}, {4,1}, {4,0}, {2,4}, {2,3}, {3,4}, {3,5}};
for(int i = 0; i < 9; i++)
{
	g.addEdge(edge[i][0], edge[i][1]);
}

// g.printGraph();
// cout << endl;
/*
arr = g.DFS(visited);
arr->printArray();
*/
arr = g.DFSstack(visited);
//arr->printArray();
delete arr;
}