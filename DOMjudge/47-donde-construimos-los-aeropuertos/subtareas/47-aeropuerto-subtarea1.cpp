#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

// Estructura ufds para representar conjuntos disjuntos.
struct ufds {
  int numSets;
  vector<int> p;

  ufds(int N) : numSets(N), p(N, -1) {}

  int find(int i) {
    if (p[i] < 0) {
      return i;
    } else {
      p[i] = find(p[i]);
      return p[i];
    }
  }

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
  // Número de localidades(N), número de autopistas(M)
  int N, M;
  cin >> N >> M;

  if (N == 0 && M == 0)
    return false;

  // Coste de construir un aeropuerto en una localidad(a).
  int a;
  for (int n = 0; n < N; ++n) {
    cin >> a;
    // No hace falta guardarlo ya que todos los ai son iguales.
  }

  // creamos un vector de tuplas para guardar las aristas o carreteras entre
  // localidades
  vector<tuple<int, int, int>> edges;

  for (int m = 0; m < M; m++) {
    int X, Y, C;
    // Coste de construir una autopista entre X e Y es C.
    cin >> X >> Y >> C;
    edges.push_back({C, X, Y});
  }

  // Algoritmo de Kruskal ordenando las autopistas por coste.
  sort(edges.begin(), edges.end());

  // Creamos una instancia de ufds y añadimos al coste el aeropuerto construido
  // en la primera componente conexa
  ufds UF(N);
  int airport = 1;
  int cost = a;

  for (auto edge : edges) {
    // Destructuramos.
    int c = get<0>(edge), x = get<1>(edge), y = get<2>(edge);

    // Si no están relacionadas, es que una de ellas no dispone de aeropuerto
    // por lo que las unimos al árbol y añadimos el coste de esa carretera.
    if (!UF.related(x, y) && c < a) {
      UF.join(x, y);
      cost += c;
    }

    // Si todas las localidades están relacionadas entre sí es que hemos
    // encontrado el primer árbol de expansión mínima.
    if (UF.numSets == 1)
      break;
  }

  // Todo nodo raiz de una componente conexa es un aeropuerto.
  if (!UF.related(1, N)) {
    airport++;
    cost += a;
  }

  // Coste mínimo de construir autopistas, aeropuertos necesarios para que
  // todas tengan acceso a un aeropuerto.
  cout << cost << " " << airport << "\n";

  return true;
}

int main() {
  while (solve())
    ;
  return 0;
}