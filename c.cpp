#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    char dup;
    map<char, int> m;
    for (char c: s) {
        m[c]++;
        if (m[c] == 2) dup = c;
    }

    set<char> adj;
    int idx1 = -1, idx2 = -1;
    for (int i = 0; i < 27; i++) {
        char c = s[i];
        if (c == dup) {
            if (idx1 == -1) idx1 = i;
            else {
                adj.insert(s[i - 1]);
                if (i + 1 < 27) adj.insert(s[i + 1]);
                idx2 = i;
            };
        }
    }

    if (idx2 - idx1 == 1) {
        cout << "Impossible" << endl;
        return 0;
    }

    string res;

    auto getPos = [&](int idx) {
        int row = idx / 13;
        int col = idx % 13;

        if (row == 1) col = 38 - col;

        return make_pair(row, col);
    };

    auto getIdx = [&](int row, int col) {
        if (row == 0) {
            return col;
        }
        return 25 - col;
    };

    int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

    auto valid = [&]() {
        for (int i = 0; i < 26; i++) {
            auto pos = getPos(i);
            if (res[i] == dup) {
                int match = 0;
                for (int dir = 0; dir < 8; dir++) {
                    int dx = pos.first + dr[dir];
                    int dy = pos.second + dc[dir];
                    if (dx < 0 || dx >= 2) continue;
                    if (dy < 0 || dy >= 26) continue;
                    if (adj.find(res[getIdx(dx, dy)]) != adj.end()) {
                        match++;
                    }
                }
                if (match == adj.size()) return true;
                return false;
            }
        }
        return false;
    };

    auto rotate = [&]() {
        string temp;
        temp.push_back(res[25]);
        for (int i = 1; i < 26; i++) {
            temp.push_back(res[i - 1]);
        };
        return temp;
    };


    for (int i = 0; i < 27; i++) {
        if (i == idx2) {
            continue;
        }
        res.push_back(s[i]);
    }

    for (int rot = 0; rot < 27; rot++) {
        if (valid()) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 13; j++) {
                    cout << res[getIdx(i, j)];
                }
                cout << endl;
            }
            return 0;
        } else {
            res = rotate();
        }
    }

    return 0;
}
