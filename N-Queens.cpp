#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solutionCount = 0;

bool Place(int k, int col, vector<int>& x) {
    for(int i = 0; i < k; i++) {
        if(x[i] == col)
            return false;

        if(abs(x[i] - col) == abs(i - k))
            return false;
    }

    return true;
}

void printBoard(vector<int>& x, int n) {
    solutionCount++;

    cout << "\nSolution " << solutionCount << ":\n\n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(x[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}

void NQueensRec(int k, int n, vector<int>& x) {
    for(int col = 0; col < n; col++) {
        if(Place(k, col, x)) {
            x[k] = col;

            if(k == n - 1)
                printBoard(x, n);
            else
                NQueensRec(k + 1, n, x);
        }
    }
}

int main() {
    int n;

    cout << "Enter number of queens: ";
    cin >> n;

    vector<int> x(n);

    NQueensRec(0, n, x);

    cout << "\nTotal Solutions = " << solutionCount;

    return 0;
}