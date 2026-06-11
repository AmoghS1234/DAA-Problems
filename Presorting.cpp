#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& a, int low, int mid, int high) {
    vector<int> temp;
    int i = low;
    int j = mid + 1;

    while(i <= mid && j <= high) {
        if(a[i] <= a[j]) {
            temp.push_back(a[i]);
            i++;
        } else {
            temp.push_back(a[j]);
            j++;
        }
    }

    while(i <= mid) {
        temp.push_back(a[i]);
        i++;
    }

    while(j <= high) {
        temp.push_back(a[j]);
        j++;
    }

    for(int k = low; k <= high; k++)
        a[k] = temp[k - low];
}

void mergeSort(vector<int>& a, int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

bool ElementUniqueness(vector<int>& A) {
    if (A.empty()) return true;

    mergeSort(A, 0, (int)A.size() - 1);

    for(int i = 0; i < (int)A.size() - 1; i++) {
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