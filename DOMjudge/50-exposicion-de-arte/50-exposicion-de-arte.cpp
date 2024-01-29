#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool possible(int m, int V, int N, vector<int> &weigths) {
  // Viajes realizados(travels), peso actual(weigth).
  int travels = 0, weight = 1e9;
  for (int i = 0; i < N; ++i) {
    // Si el peso actual + el siguiente peso es menor o igual al tope(m), quiere
    // decir que cabe junto con los demas en el camión.
    if (weight + weigths[i] <= m) {
      weight += weigths[i];
    } else {
      // Si no cabe, se hace un viaje más llevando ese peso.
      travels++;
      weight = weigths[i];
      // Si no cabe para el m no es posible.
      if (weight > m)
        return false;
    }
  }

  // Si se hace menos o igual viajes que los permitidos(V), es posible.
  return travels <= V;
}

bool solve() {
  // Obras de arte(N), numero de viajes que puede hacer el camión como
  // máximo(V).
  int N, V;
  cin >> N >> V;

  // Vector de los pesos, se garantiza que son menores que 10^9.
  vector<int> weigths(N, 0);

  if (N == 0 && V == 0)
    return false;

  // Suma de los pesos y el peso máximo.
  int sumOfWeigths = 0, maxWeigth = 0;
  for (int &x : weigths) {
    cin >> x;
    sumOfWeigths += x;
    maxWeigth = max(maxWeigth, x);
  }

  // Binary Search para el tope de carga.
  // En un rango de [l..r]
  // Máximo peso que puede cargar un camión(l), hasta la suma de los pesos(r).
  int l = maxWeigth - 1, r = sumOfWeigths;
  while (l + 1 < r) {
    // mitad del rango(m).
    int m = (l + r) / 2;
    if (possible(m, V, N, weigths)) {
      // Si es posible, se puede hacer la mudanza en <= V viajes.
      r = m;
    } else {
      // Si no es posible, se necesita un tope de carga mas grande.
      l = m;
    }
  }

  // Tope de carga mas pequeño que permite hacer la mudanza en <= V viajes.
  cout << r << "\n";
  return true;
}

int main() {
  while (solve())
    ;
  return 0;
}