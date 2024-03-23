#include <bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;

    string s1 = s.substr(0, (int)s.size() - 1);
    char seat = *s.rbegin();

    long long n = stoll(s1);

    long long block = (n - 1) / 4;
    long long row = (n - 1) % 4;

    map<char, int> m;

    m['a'] = 3;
    m['b'] = 4;
    m['c'] = 5;
    m['d'] = 2;
    m['e'] = 1;
    m['f'] = 0;

    cout << 16 * block + 1 + ((row & 1) ? 7 : 0) + m[seat];
    return 0;
}
