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
  // Numero de vertices o islas(I), y numero de puenetes(P)
  int I, P;
  cin >> I;
  cin >> P;

  if (!cin)
    return false;

  // Vector de aristas del grafo
  vector<tuple<int, int, int>> aristas;

  for (int p = 0; p < P; p++) {
    // a y b son las islas que conecta el puente, c es el coste de construirlo
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    // Lo guaramos en el vector de aristas
    aristas.push_back({c, a, b});
  }

  // Algoritmo de kruskal, lo ordenamos por coste menor
  sort(aristas.begin(), aristas.end());

  // Instancia de UFDS un nodo por cada isla
  ufds UF(I);
  int cost_min = 0;

  for (auto arista : aristas) {
    // Destructuramos la tupla de la arista
    int c = get<0>(arista), a = get<1>(arista), b = get<2>(arista);

    // Si no estan relacionadas las uniemos y sumamos el coste.
    if (!UF.related(a, b)) {
      UF.join(a, b);
      cost_min += c;
    }
    // Si el numero de sets es 1, ya hemos unido todas las islas de menor coste,
    // si no llegamos es porque no hay camino entre todas las islas.
    if (UF.numSets == 1)
      break;
  }

  if (UF.numSets > 1)
    cout << "No hay puentes suficientes\n";
  else
    cout << cost_min << "\n";

  return true;
}

int main() {
  while (solve())
    ;
  return 0;
}