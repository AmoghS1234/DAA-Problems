#include <iostream>
#include <vector>

using namespace std;

#define INF 99999

void Prim(vector<vector<int>>& W, int n) {
    vector<int> nearest(n);
    vector<int> distance(n);

    int totalCost = 0;

    for(int i = 1; i < n; i++) {
        nearest[i] = 0;
        distance[i] = W[0][i];
    }

    distance[0] = 0;

    cout << "\nEdges in MST:\n";

    for(int k = 1; k < n; k++) {
        int min = INF;
        int vnear = -1;

        for(int j = 1; j < n; j++) {
            if(distance[j] != 0 && distance[j] < min) {
                min = distance[j];
                vnear = j;
            }
        }

        if(vnear == -1) {
            cout << "\nGraph is disconnected. MST cannot be formed.";
            break;
        }

        cout << "(" << nearest[vnear] << ", " << vnear << ") Cost = " << min << endl;
        totalCost += min;
        distance[vnear] = 0;

        for(int j = 1; j < n; j++) {
            if(W[j][vnear] < distance[j]) {
                distance[j] = W[j][vnear];
                nearest[j] = vnear;
            }
        }
    }

    cout << "\nTotal Cost = " << totalCost;
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

    Prim(W, n);

    return 0;
}