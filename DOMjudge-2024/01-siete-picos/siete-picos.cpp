#include <bits/stdc++.h>

#include <vector>
using namespace std;

int numPicos(vector<int>& v) {
    int picos = 0;
    int n = v.size();

    // Desde el segundo elemento hasta el penúltimo para no salirnos de rango
    for (int i = 1; i < n - 1; ++i) {
        if (v[i - 1] < v[i] && v[i] > v[i + 1])
            ++picos;
    }

    // Comprobamos los extremos
    picos += v[n - 1] < v[0] && v[0] > v[1];
    picos += v[n - 2] < v[n - 1] && v[n - 1] > v[0];

    return picos;
}

bool solve() {
    int n;
    cin >> n;
    if (n == 0) return false;

    vector<int> v(n);

    for (auto& e : v)
        cin >> e;

    int picos = numPicos(v);
    cout << picos << endl;

    return true;
}

int main() {
    while (solve());
    return 0;
}