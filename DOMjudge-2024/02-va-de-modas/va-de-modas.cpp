#include <bits/stdc++.h>

#include <vector>
using namespace std;

int modas(vector<int>& v) {
    // Ordenar el vector
    sort(v.begin(), v.end());

    // Encontrar la moda
    int moda = v[0];
    int max_count = 1, current_count = 1;

    for (size_t i = 1; i < v.size(); ++i) {
        // Si el elemento actual es igual al anterior, incrementar el contador
        if (v[i] == v[i - 1]) {
            current_count++;
        } else {
            // Si el contador actual es mayor que el máximo, actualizar la moda
            if (current_count > max_count) {
                max_count = current_count;
                moda = v[i - 1];
            }
            // Reiniciar el contador
            current_count = 1;
        }
    }

    // Verificar la última secuencia
    if (current_count > max_count)
        moda = v.back();

    return moda;
}

bool solve() {
    int n;
    cin >> n;
    if (n == 0) return false;

    vector<int> v(n);

    for (auto& e : v)
        cin >> e;

    int m = modas(v);
    cout << m << endl;

    return true;
}

int main() {
    while (solve());
    return 0;
}