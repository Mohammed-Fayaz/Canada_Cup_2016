#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
    int n; cin >> n;

    multiset<ll> g;
    vector<pair<ll, ll>> s;
    vector<pair<ll, ll>> a(n, pair<ll, ll>());
    for (int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
        if (i > 0){
            if (a[i].first > a[0].first){
                g.insert(a[i].second - a[i].first + 1);
            } else {
                s.push_back(a[i]);
            }
        }
    }

    sort(s.begin(), s.end());

    int res = g.size() + 1;
    while (a[0].first && g.size()){
        auto bg = *g.begin();
        if (a[0].first < bg) break;

        g.erase(g.begin());
        a[0].first -= bg;

        while (s.size() && s.back().first > a[0].first){
            auto ng = s.back();
            s.pop_back();
            g.insert(ng.second - ng.first + 1);
        }

        res = min(res, (int)g.size() + 1);
    }

    cout << res << endl;
    return 0;
}