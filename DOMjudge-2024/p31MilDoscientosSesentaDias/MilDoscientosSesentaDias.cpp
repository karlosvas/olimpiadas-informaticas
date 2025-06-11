#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Meses en calendario juliano (4 años cíclicos)
    vector<int> months = {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
        31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int cycle_len = months.size();  // 48

    // Precompute todos los sumas consecutivas <= ciclo
    vector<ll> sums;
    for (int i = 0; i < cycle_len; ++i) {
        ll s = 0;
        for (int len = 1; len <= cycle_len; ++len) {
            int idx = (i + len - 1) % cycle_len;
            s += months[idx];
            if (len <= cycle_len)
                sums.push_back(s);
        }
    }

    sort(sums.begin(), sums.end());
    sums.erase(unique(sums.begin(), sums.end()), sums.end());
    unordered_set<ll> base(sums.begin(), sums.end());
    const ll CYCLE_DAYS = 1461;  // 4*365 +1

    ll n;
    while (cin >> n && n != 0) {
        bool ok = false;
        if (base.count(n))
            ok = true;
        else {
            for (ll s : sums) {
                if (n > s && (n - s) % CYCLE_DAYS == 0) {
                    ok = true;
                    break;
                }
            }
        }
        cout << (ok ? "SI" : "NO") << "\n";
    }
    return 0;
}
