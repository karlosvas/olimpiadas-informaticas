#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using info = pair<double, pair<int, int>>;

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

bool solve() {
  // Número de platos (P), número de coronas (C)
  int P, C;
  cin >> P >> C;
  if (P == 0 && C == 0)
    return false;

  vector<int> V;
  while (P--) {
    // Número de dientes en cada plato (d)
    int d;
    cin >> d;
    // Vector de platos.
    V.push_back(d);
  }

  // Cola de prioridad para ordenar las relaciones entre platos y coronas.
  priority_queue<info, vector<info>, greater<info>> pq;
  while (C--) {
    // Cantidad de dientes en cada corona (q)
    int q;
    cin >> q;
    // Recorremos cada plato y calculamos la relación entre plato y corona.
    for (auto &d : V) {
      // Máximo común divisor entre plato y corona.
      int MCD = gcd(d, q);
      double relacion_d = d / MCD;
      double relacion_q = q / MCD;

      // Calculamos el esfuerzo de pedaleo.
      double f = relacion_d / relacion_q;

      // Insertamos la relación en la cola de prioridad.
      pq.push({f, {d, q}});
    }
  }

  // Imprimimos la cola de prioridad.
  while (!pq.empty()) {
    auto [f, pair] = pq.top();
    auto [d, q] = pair;

    if (pq.size() == 1)
      cout << d << "-" << q << "\n";
    else
      cout << d << "-" << q << " ";

    pq.pop();
  }
  return true;
}

int main() {
  while (solve())
    ;
  return 0;
}