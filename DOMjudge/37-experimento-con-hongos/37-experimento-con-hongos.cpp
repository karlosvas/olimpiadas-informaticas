#include <iostream>
#include <map>
using namespace std;

bool solve() {
    int N, M, T; // Hongos adultos(N), yema(M), tiempo(T).
    cin >> N >> M >> T; 

    if (!cin) return false;

    // Contador de hongos, incluyendo el inicial.
    // Map de tiempo en el que se van a reproducir y el número de hongos que se van a reproducir en ese tiempo.
    int count = 1;
    map<int, int> fungs;

    // El primer hongo desde el que se pueden crear otras yemas u hongos esta en N.
    fungs[N] = 1;

    for (int t = 0; t <= T; t++) {
        // Crea su primera yema.
        if (t == N) count++;

        if (fungs.count(t) > 0) {
            // Si existe en el map, se crea una yema en t + M y otra en t + N.
            if (t + M <= T) count += fungs[t], fungs[t + M] += fungs[t];
            if (t + N <= T) count += fungs[t], fungs[t + N] += fungs[t];
        }
    }

    // Imprime el número de hongos.
    cout<<count<<"\n";

    return true;
}

int main() {
    while (solve());
    return 0;
}