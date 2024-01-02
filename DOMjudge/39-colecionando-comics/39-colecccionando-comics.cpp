#include <iostream>
#include <vector>
#include <limits>
#include <stack>
#include <queue>
using namespace std;

bool solve() {
    // Números de pilas de cómics.
    int N; cin >> N;

    if (!cin) return false;

    // Priority queue de pilas, y puntero al cómic con menor id.
    int puntero_min = numeric_limits<int>::max();
    auto comp = [](const pair<int, stack<int>>& a, const pair<int, stack<int>>& b) {
    return a.first > b.first;
    };
    priority_queue<pair<int, stack<int>>, vector<pair<int, stack<int>>>, decltype(comp)> minHeap(comp);

    bool count = false, found = false;

    for (int n = 0; n < N; n++) {
        // Cantidad de elementos en los stack(K).
        int K; cin >> K;

        stack<int> pila;
        for (int k = 0; k < K; k++) {
            int id; cin >> id;
            if(id < puntero_min) puntero_min = id;
            // Si el id actual es menor que el puntero lo guardamos y vaciamos o creamos una nueva pq.
            pila.push(id);
        }
        minHeap.push({pila.top(), pila});
    }

    int wait = 1;
    while (!minHeap.empty()) {
        pair<int, stack<int>> pila = minHeap.top(); // Obtiene la pila con el elemento superior más pequeño
        if(pila.second.top() == puntero_min) break; // Si es igual al puntero deja de buscar.

        minHeap.pop(); // Elimina la pila de la cola de prioridad, para el siguuiente caso
        pila.second.pop(); // Elimina el elemento superior de la pila

        // Si la pila aún tiene elementos, vuelve a insertarla en la cola de prioridad con su nuevo elemento superior
        if (!pila.second.empty()) minHeap.push({pila.second.top(), pila.second});

        wait++; // Deve esperar 1 turno más.
    }

    // Mostramos la cantidad de personas en la cola que deveremos esperar hasta obtener el cómic con la menor id.
    cout<<wait<<"\n";

    return true;
}

int main() {
    while (solve());
    return 0;
}

