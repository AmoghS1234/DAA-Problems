#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> F;
vector<int> w, p;

int KnapsackMF(int i, int j) {
    if(F[i][j] != -1)
        return F[i][j];

    int value;

    if(j < w[i - 1]) {
        value = KnapsackMF(i - 1, j);
    } else {
        value = max(KnapsackMF(i - 1, j), p[i - 1] + KnapsackMF(i - 1, j - w[i - 1]));
    }

    F[i][j] = value;

    return value;
}

int main() {
    int n, M;

    cout << "Enter number of items: ";
    cin >> n;

    w.resize(n);
    p.resize(n);

    cout << "Enter weights:\n";
    for(int i = 0; i < n; i++)
        cin >> w[i];

    cout << "Enter profits:\n";
    for(int i = 0; i < n; i++)
        cin >> p[i];

    cout << "Enter capacity: ";
    cin >> M;

    F.assign(n + 1, vector<int>(M + 1, -1));

    for(int i = 0; i <= n; i++)
        F[i][0] = 0;

    for(int j = 0; j <= M; j++)
        F[0][j] = 0;

    cout << "\nMaximum Profit = " << KnapsackMF(n, M);

    return 0;
}