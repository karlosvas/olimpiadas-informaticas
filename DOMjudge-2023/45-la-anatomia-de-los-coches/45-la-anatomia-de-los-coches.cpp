#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

struct ufds {
  int numSets;
  vector<int> p;

  ufds(int N) : numSets(N), p(N, -1) {}

  int find(int i) { return (p[i] < 0) ? i : p[i] = find(p[i]); }

  bool related(int i, int j) { return find(i) == find(j); }

  void join(int i, int j) {
    int x = find(i), y = find(j);
    if (x == y)
      return;
    if (p[x] < p[y])
      swap(x, y);
    p[y] += p[x];
    p[x] = y;
    --numSets;
  }

  int size(int i) { return -p[find(i)]; }
};

bool solve() {
  // Número de ciudades(N) y de carreteras(M).
  int N, M;
  cin >> N >> M;

  if (!cin)
    return false;

  // Instancia de ufs con N elementos, y vector de aristas
  ufds UF(N);
  vector<tuple<int, int, int>> aristas;

  // Leemos las aristas y las guardamos en el vector
  for (int m = 0; m < M; ++m) {
    int a, b, l;
    cin >> a >> b >> l;
    --a, --b;
    aristas.push_back({l, a, b});
  }

  // Algoritmo de kruskal MaxMinPath, caminos mínimos con coste maximo
  sort(aristas.begin(), aristas.end());
  int autonomy = 0;

  for (auto arista : aristas) {
    // Destructuramos la arista
    int l = get<0>(arista), a = get<1>(arista), b = get<2>(arista);
    // Si no estan relacionados, los unimos
    if (!UF.related(a, b)) {
      // Guardamos el coste máximo utilizado en el menor de los caminos
      UF.join(a, b);
      // Si la autonomía del coche es suficiente para cubrir la distancia máxima
      // entre ciudades consecutivas en un camino específico, entonces se
      // garantiza que el coche puede moverse entre cualquier par de ciudades en
      // la red
      autonomy = max(autonomy, l);
    }
    // Si solo queda un conjunto, hemos terminado
    if (UF.numSets == 1) {
      cout << autonomy << "\n";
      return true;
    }
  }

  // Si queda más de un conjunto, no se puede llegar a todas las ciudades
  cout << "Imposible\n";

  return true;
}

int main() {
  while (solve())
    ;
  return 0;
}