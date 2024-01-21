#include <iostream>
#include <vector>
using namespace std;

struct ufds {
  int numSets;
  vector<int> p;

  ufds(int N) : numSets(N), p(N, -1) {}

  // Devuelbe el padre de ir ecursivamente hasta encontrar la raiz.
  int find(int i) { return p[i] < 0 ? i : p[i] = find(p[i]); }

  bool related(int i, int j) { return find(i) == find(j); }

  void join(int i, int j) {
    int x = find(i), y = find(j);
    // SI son iguales ya estaban en el mismo árbol.
    if (x == y)
      return;
    // Pone como hijo al arbol mas pequeño.
    if (p[x] < p[y])
      swap(x, y);
    // Sumamos el tamaño del arbol mas pequeño al mas grande. y ponemos como
    // padre al mas grande.
    p[y] += p[x];
    p[x] = y;
    --numSets;
  }

  int size(int i) { return -p[find(i)]; }
};

bool solve() {
  int N, M;
  cin >> N >> M;
  if (!cin)
    return false;

  ufds UF(N);

  for (int i = 0; i < M; ++i) {
    int T;
    cin >> T;
    if (T > 0) {
      int prim; // Primero
      cin >> prim;
      --prim;
      for (int j = 1; j < T; ++j) {
        int otro;
        cin >> otro; // Otros
        --otro;
        UF.join(prim, otro); // Ponemos a otros como hijos del primero.
      }
    }
  }

  cout << UF.size(0);
  // Mostramos el tamaño del arbol de cada nodo.
  for (int i = 1; i < N; i++) {
    cout << " " << UF.size(i) << "\n";
  }

  cout << "\n";

  return true;
}

int main() {
  while (solve()) {
  };

  return 0;
}
