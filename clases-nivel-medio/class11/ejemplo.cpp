#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

struct ufds {
  int numSets;
  vector<int> p;

  ufds(int N) : numSets(N), p(N, -1) {}

  int find(int i) { return p[i] < 0 ? i : p[i] = find(p[i]); }

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

using arista = tuple<int, int, int>; // <Coste extremos>
int main() {
  int V, A;
  cin >> V >> A;
  vector<arista> aristas;

  for (int i = 0; i < A; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    aristas.push_back({c, u, v});
  }

  // Algoritmo de Kruskal
  sort(aristas.begin(), aristas.end());

  ufds UF(V);
  int coste = 0;
  for (auto [c, u, v] : aristas) {
    if (!UF.related(u, v)) {
      UF.join(u, v);
      coste += c;
    }
    if (UF.numSets <= 5)
      break;
  }

  cout << coste << "\n";

  return 0;
}
