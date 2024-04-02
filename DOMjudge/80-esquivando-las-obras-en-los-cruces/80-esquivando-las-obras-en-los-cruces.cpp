#include <bits/stdc++.h>
using namespace std;

// Matriz de memoización (1 ≤ N, M ≤ 50)
int memo[51][51];

int comb(int N, int M, vector<vector<char>> &road) {
  // Inicializar la matriz de memoización a cero
  memset(memo, 0, sizeof(memo));
  memo[0][0] = 1;

  // Calculamos el número de caminos para cada celda recorriendo memo, para
  // cacular N-1 hace falta N. Para M-1 hace falta M.
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      // Si la celda es un obstáculo, no se puede pasar por ella
      if (road[i][j] == 'X')
        continue;
      // Evitamos el acceso a indices fuera de la matriz
      if (i > 0)
        memo[i][j] += memo[i - 1][j];
      if (j > 0)
        memo[i][j] += memo[i][j - 1];
    }
  }

  // Caminos para llegar a la esquina inferior derecha
  return memo[N - 1][M - 1];
}

bool solve() {
  // Número de calles este-oeste(N) Número de calles norte-sur(M)
  int N, M;
  cin >> N >> M;

  if (!cin)
    return false;

  // Mapa de la ciudad(road)
  vector<vector<char>> road(N + 1, vector<char>(M + 1));

  // Leer el mapa de la ciudad
  for (int n = 0; n < N; n++) {
    string line;
    cin >> line;
    for (int m = 0; m < M; m++) {
      road[n][m] = line[m];
    }
  }

  // Calcular el número de caminos posibles desde [0][0] a [N-1][M-1]
  cout << comb(N, M, road) << "\n";

  return true;
}

int main() {
  while (solve())
    ;
  return 0;
}