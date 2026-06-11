#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> badCharacterTable(string pattern)
{
    int m = pattern.length();

    vector<int> BC(256, m);

    for(int i = 0; i < m - 1; i++)
        BC[(unsigned char)pattern[i]]
            = m - 1 - i;

    return BC;
}

int boyerMoore(string text,
               string pattern)
{
    int n = text.length();
    int m = pattern.length();

    vector<int> BC =
        badCharacterTable(pattern);

    int s = 0;

    while(s <= n - m)
    {
        int j = m - 1;

        while(j >= 0 &&
              pattern[j] ==
              text[s + j])
        {
            j--;
        }

        if(j < 0)
            return s;

        int shift =
            BC[(unsigned char)
                text[s + m - 1]];

        s += max(1, shift);
    }

    return -1;
}

int main()
{
    string text, pattern;

    cout << "Enter Text: ";
    getline(cin, text);

    cout << "Enter Pattern: ";
    getline(cin, pattern);

    int pos =
        boyerMoore(text, pattern);

    if(pos == -1)
        cout << "\nPattern Not Found";
    else
        cout << "\nPattern Found at Position "
             << pos;

    return 0;
}