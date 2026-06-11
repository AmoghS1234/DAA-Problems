#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> shiftTable(string pattern) {
    int m = pattern.length();
    vector<int> table(256, m);

    for(int j = 0; j < m - 1; j++)
        table[(unsigned char)pattern[j]] = m - 1 - j;

    return table;
}

int horspool(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    vector<int> table = shiftTable(pattern);

    int i = m - 1;

    while(i < n) {
        int k = 0;

        while(k < m && pattern[m - 1 - k] == text[i - k]) {
            k++;
        }

        if(k == m)
            return i - m + 1;

        i += table[(unsigned char)text[i]];
    }

    return -1;
}

int main() {
    string text, pattern;

    cout << "Enter Text: ";
    getline(cin, text);

    cout << "Enter Pattern: ";
    getline(cin, pattern);

    int pos = horspool(text, pattern);

    if(pos == -1)
        cout << "\nPattern Not Found";
    else
        cout << "\nPattern Found at Position " << pos;

    return 0;
}