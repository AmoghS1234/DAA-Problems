#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<vector<int>>& adj, int V, int source) {
    vector<bool> visited(V, false);
    queue<int> q;
    visited[source] = true;
    q.push(source);

    cout << "\nBFS Traversal:\n";

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for(int v : adj[u]) {
            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);

    cout << "Enter edges (u v):\n";
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    BFS(adj, V, source);

    return 0;
}