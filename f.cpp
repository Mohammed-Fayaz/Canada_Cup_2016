#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n; cin >> n;

    ll res = 0;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++){
        int a1, b1, a2, b2; cin >> a1 >> b1 >> a2 >> b2;
        if (a1 + b1 >= a2 + b2){
            v.push_back({a1, b1});
            v.push_back({a2, b2});
        } else if (a1 > b2) {
            v.push_back({a1 - b2, b2 - a1});
        } else if (b1 > a2) {
            v.push_back({a2 - b1, b1 - a2});
        }
    }

    for (int i = 0; i < (int)v.size(); i++){
        res += (v[i].first - v[i].second);
        v[i] = {(v[i].first + v[i].second), (v[i].first + v[i].second)};
    }

    sort(v.rbegin(), v.rend());

    for (int i = 0; i < v.size(); i++){
        if (i & 1){
            res -= v[i].second;
        }
        else {
            res += v[i].first;
        }
    }

    cout << res / 2 << endl;
    return 0;
}