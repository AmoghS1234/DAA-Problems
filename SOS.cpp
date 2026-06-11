#include <iostream>
#include <vector>

using namespace std;

int n, M;
vector<int> w;
vector<int> x;

void printSolution() {
    cout << "{ ";
    for(int i = 0; i < n; i++) {
        if(x[i] == 1)
            cout << w[i] << " ";
    }
    cout << "}\n";
}

void SumOfSub(int s, int k, int r) {
    x[k] = 1;

    if(s + w[k] == M) {
        printSolution();
    } else if(k < n - 1 && s + w[k] + w[k + 1] <= M) {
        SumOfSub(s + w[k], k + 1, r - w[k]);
    }

    if(k < n - 1 && s + r - w[k] >= M && s + w[k + 1] <= M) {
        x[k] = 0;
        SumOfSub(s, k + 1, r - w[k]);
    }
}

int main() {
    cout << "Enter number of elements: ";
    cin >> n;

    w.resize(n);
    x.resize(n);

    cout << "Enter elements in ascending order:\n";
    int total = 0;

    for(int i = 0; i < n; i++) {
        cin >> w[i];
        total += w[i];
    }

    cout << "Enter target sum: ";
    cin >> M;

    cout << "\nSolutions:\n";
    SumOfSub(0, 0, total);

    return 0;
}