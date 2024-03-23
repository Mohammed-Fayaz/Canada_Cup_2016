#include <bits/stdc++.h>

using namespace std;

int main(){
    int c; cin >> c;
    int n; cin >> n;

    vector<int> a(n), best(c + 1, -1);
    unordered_map<int, int> cnt;

    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (cnt.find(a[i]) == cnt.end()) cnt[a[i]] =1;
        else cnt[a[i]]++;
    }

    sort(a.begin(), a.end());

    vector<int> lower(c, -1);
    for (int i = 0; i < n - 1; i++){
        if (a[i] < a[i + 1]) lower[a[i + 1]] = a[i];
    }

    int pos = 0;
    for (int i = 0; i <= c; i++){
        while (pos + 1 < n && a[pos + 1] <= i) pos++;
        if (a[pos] <= i) best[i] = a[pos];
    }


    for (int res = 0; res <= c; res++){
        int lastUsed = -1;
        bool resUsed = false;
        int rem = c;
        while (rem){
            int next = best[rem];
            while (lastUsed!= -1 && lastUsed <= next) {
                next = lower[next];
            }
            if (next == -1){
                cout << res << endl;
                return 0;
            }
            if (!resUsed && res <= rem && res >= next) {
                resUsed = true;
                rem -= res;
                continue;
            }
            rem -= min(cnt[next], rem / next) * next;
            lastUsed = next;
        }
    }

    cout << "Greed is good" << endl;
    return 0;
}
