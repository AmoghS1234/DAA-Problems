#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void DFS(int v,
         vector<vector<int>>& adj,
         vector<bool>& visited,
         stack<int>& st)
{
    visited[v] = true;

    for(int u : adj[v])
    {
        if(!visited[u])
            DFS(u, adj, visited, st);
    }

    st.push(v);
}

void TopologicalSort(vector<vector<int>>& adj, int V)
{
    vector<bool> visited(V, false);

    stack<int> st;

    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
            DFS(i, adj, visited, st);
    }

    cout << "\nTopological Order:\n";

    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);

    cout << "Enter edges (u v):\n";

    for(int i = 0; i < E; i++)
    {
        int u, v;

        cin >> u >> v;

        adj[u].push_back(v);
    }

    TopologicalSort(adj, V);

    return 0;
}