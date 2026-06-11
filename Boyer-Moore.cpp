#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> badCharacterTable(string pattern) {
    int m = pattern.length();
    vector<int> BC(256, -1);

    for(int i = 0; i < m; i++)
        BC[(unsigned char)pattern[i]] = i;

    return BC;
}

int boyerMoore(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    vector<int> BC = badCharacterTable(pattern);

    int s = 0;
    while(s <= n - m) {
        int j = m - 1;

        while(j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }

        if(j < 0) {
            return s;
        }

        s += max(1, j - BC[(unsigned char)text[s + j]]);
    }

    return -1;
}

int main() {
    string text, pattern;

    cout << "Enter Text: ";
    getline(cin, text);

    cout << "Enter Pattern: ";
    getline(cin, pattern);

    int pos = boyerMoore(text, pattern);

    if(pos == -1)
        cout << "\nPattern Not Found";
    else
        cout << "\nPattern Found at Position " << pos;

    return 0;
}