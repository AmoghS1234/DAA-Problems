#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<int>& a, int low, int high) {
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    while (true) {
        while (i <= high && a[i] <= pivot) i++;
        while (a[j] > pivot) j--;

        if (i < j) {
            swap(a[i], a[j]);
        } else {
            break;
        }
    }
    swap(a[low], a[j]);

    return j;
}

void quickSort(vector<int>& a, int low, int high) {
    if(low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
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

    quickSort(a, 0, n - 1);

    cout << "\nSorted Array:\n";
    for(int x : a)
        cout << x << " ";

    return 0;
}