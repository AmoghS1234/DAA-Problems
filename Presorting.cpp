#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ElementUniqueness(vector<int>& A) {
    sort(A.begin(), A.end());

    for(int i = 0; i < A.size() - 1; i++) {
        if(A[i] == A[i + 1])
            return false;
    }

    return true;
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> A(n);

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin >> A[i];

    if(ElementUniqueness(A))
        cout << "\nAll elements are unique";
    else
        cout << "\nDuplicate elements found";

    return 0;
}