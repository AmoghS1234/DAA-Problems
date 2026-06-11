#include <iostream>
#include <vector>

using namespace std;

void Heapify(vector<int>& A, int i, int n) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && A[left] > A[largest])
        largest = left;

    if(right < n && A[right] > A[largest])
        largest = right;

    if(largest != i) {
        swap(A[i], A[largest]);
        Heapify(A, largest, n);
    }
}

void BuildHeap(vector<int>& A, int n) {
    for(int i = n / 2 - 1; i >= 0; i--) {
        Heapify(A, i, n);
    }
}

void HeapSort(vector<int>& A, int n) {
    BuildHeap(A, n);

    for(int i = n - 1; i > 0; i--) {
        swap(A[0], A[i]);
        Heapify(A, 0, i);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> A(n);

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin >> A[i];

    HeapSort(A, n);

    cout << "\nSorted Array:\n";
    for(int x : A)
        cout << x << " ";

    return 0;
}