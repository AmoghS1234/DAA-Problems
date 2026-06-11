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

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    mergeSort(a, 0, n - 1);

    cout << "\nSorted Array:\n";
    for(int x : a)
        cout << x << " ";

    return 0;
}