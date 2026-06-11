#include <iostream>
#include <vector>

using namespace std;

#define INF 99999

void FloydWarshall(vector<vector<int>>& D, int n) {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(D[i][k] != INF && D[k][j] != INF) {
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
                }
            }
        }
    }
}

int main() {
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> D(n, vector<int>(n));

    cout << "Enter weight matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> D[i][j];
        }
    }

    FloydWarshall(D, n);

    cout << "\nShortest Distance Matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(D[i][j] == INF)
                cout << "INF ";
            else
                cout << D[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}