#include <bits/stdc++.h>

using namespace std;
// Profundidad (prof), oro (gold)
int prof[100];
int gold[100];
vector<vector<int>> memo;

// Knapsack iterativo, encuentra el valor maximo que se puede obtener
int Knapsack(int n, int m) {
  // Inicializa la matriz de memo
  memo.assign(n + 1, vector<int>(m + 1, 0));

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      // Si la profundidad del cofre es menor o igual al peso maximo que puede
      // soportar la botella se toma el maximo entre el valor del cofre mas el
      // valor de la celda anterior
      if (prof[i - 1] <= j)
        memo[i][j] =
            max(gold[i - 1] + memo[i - 1][j - prof[i - 1]], memo[i - 1][j]);
      else
        memo[i][j] = memo[i - 1][j];
    }
  }
  return memo[n][m];
}

vector<pair<int, int>> camino(int n, int j) {
  vector<pair<int, int>> sol;
  // Recorre la matriz de memo para obtener el camino, si el valor de la celda
  // es igual al de la celda anterior, no se toma en cuenta en el camino a
  // seguir
  for (int i = n; i > 0; i--) {
    if (memo[i][j] != memo[i - 1][j]) {
      sol.push_back(pair<int, int>(prof[i - 1], gold[i - 1]));
      //  j es igual a j - prof[i - 1] ya que se toma en cuenta el peso del
      //  cofre que se tomo anteriormente
      j -= prof[i - 1];
    }
  }
  return sol;
}

int main() {
  // Segundos que permite la botella estar debajo del agua (T)
  // Numero de cofres (N)
  // Prefundidad a la que se ecnuentra cada cofre (p)
  int T, N, p;

  while (cin >> T) {
    cin >> N;
    for (int n = 0; n < N; n++) {
      cin >> p;
      prof[n] = p + (p * 2);
      cin >> gold[n];
    }

    // Peso maximo que puede soportar la botella
    cout << Knapsack(N, T) << "\n";

    // Obtiene el camino que se debe seguir para obtener el mayor valor
    vector<pair<int, int>> path = camino(N, T);
    cout << path.size() << "\n";

    // Imprime el camino para obtener el mayor valor
    for (int i = path.size() - 1; i >= 0; i--)
      cout << path[i].first / 3 << " " << path[i].second << "\n";

    cout << "---\n";
  }
  return 0;
}