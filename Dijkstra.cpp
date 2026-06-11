#include <iostream>
#include <vector>

using namespace std;

#define INF 99999

int MinVertex(vector<int>& dist, vector<bool>& visited, int n) {
    int minDist = INF;
    int index = -1;

    for(int i = 0; i < n; i++) {
        if(!visited[i] && dist[i] < minDist) {
            minDist = dist[i];
            index = i;
        }
    }

    return index;
}

void Dijkstra(vector<vector<int>>& W, int n, int source) {
    vector<int> dist(n);
    vector<bool> visited(n, false);

    for(int i = 0; i < n; i++)
        dist[i] = W[source][i];

    dist[source] = 0;
    visited[source] = true;

    for(int count = 1; count < n; count++) {
        int u = MinVertex(dist, visited, n);
        visited[u] = true;

        for(int v = 0; v < n; v++) {
            if(!visited[v] && W[u][v] != INF && dist[u] + W[u][v] < dist[v]) {
                dist[v] = dist[u] + W[u][v];
            }
        }
    }

    cout << "\nShortest Distances:\n";
    for(int i = 0; i < n; i++) {
        cout << source << " -> " << i << " = " << dist[i] << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> W(n, vector<int>(n));

    cout << "Enter cost matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> W[i][j];
        }
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    Dijkstra(W, n, source);

    return 0;
}