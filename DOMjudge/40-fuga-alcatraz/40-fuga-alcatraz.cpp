#include <iostream>
#include <vector>
using namespace std;

struct cords {
  int x;
  int y;

  // Con emplace_back podemos llamar al constructor, en evz de crear el objeto
  cords(int _x, int _y) : x(_x), y(_y) {}
};

struct ufds {
  int numSets;
  vector<int> p;

  ufds(int N) : numSets(N), p(N, -1){};

  // Devuelve el padre de ir recursivamente hasta encontrar la raiz.
  int find(int i) { return p[i] < 0 ? i : p[i] = find(p[i]); }

  // Comprueba si dos V estan entre sí en el mismo arbol.
  bool related(int i, int j) { return find(i) == find(j); }

  void join(int i, int j) {
    int x = find(i), y = find(j);
    // Si son iguales ya estaban en el mismo árbol.
    if (x == y)
      return;
    // Pone como hijo al arbol mas pequeño.
    if (p[x] < p[y])
      swap(x, y);
    // Sumamos el tamaño del arbol más pequeño al mas grande. y ponemos como
    // padre al mas grande.
    p[y] += p[x];
    p[x] = y;
    --numSets;
  }

  int size(int i) { return -p[find(i)]; }
};

bool solve() {
  // Ancho del patio(X)
  // ALto del patio(Y)
  // Vigilates(N)
  int X, Y, N;
  cin >> X;

  if (X == 0)
    return false;

  cin >> Y >> N;

  // Creamos un árbol de tamaño N+2, los nodos + muros de este y oeste
  // (instancia de ufds)
  ufds UF(N + 2);
  vector<cords> V;

  for (int n = 0; n < N; ++n) {
    // Posición de el vigilante (x,y) en un radio de 10m
    int x, y;
    cin >> x >> y;

    // Si interseca con alguno de los lados de la cárcel de X*Y no se puede
    // pasar entre vigilante y pared
    if (x <= 10 || (x + 10) >= X)
      UF.join(n, x <= 10 ? N : N + 1);

    // Añadimos al vector de vigilantes
    V.emplace_back(x + 10, y + 10);
  }

  // Para cada vigilante vemos si conoce a los demas, si las areas de visión
  // intersecan
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      // (x1-x2)^2+(y1-y2)^2
      int dist_squared = (V[i].x - V[j].x) * (V[i].x - V[j].x) +
                         (V[i].y - V[j].y) * (V[i].y - V[j].y);
      // Se conocen porque 20^2 = 400, 10 metros de área de visión cada uno
      if (dist_squared <= 400)
        UF.join(i, j);
    }
  }

  // Si el este y el oeste están relacionados no hay camino entre el norte y el
  // sur sin ser detectado
  if (UF.related(N, N + 1))
    cout << "NO\n";
  else
    cout << "SI\n";

  return true;
}

int main() {
  while (solve())
    ;

  return 0;
}