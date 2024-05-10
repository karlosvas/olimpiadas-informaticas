#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo, tablero;
vector<string> combinaciones;

#define DOMJUDGE

// Revisamos si es posible la combinación
bool posible(string a, string b) {
  for (int i = 0; i < 4; i++)
    if (a[i] == b[i] && a[i] == 'X')
      return false;
  return true;
}

// Máximo que puedo conseguir poniendo piedras hasta la columa i si la columna
// i tiene la combinación j
int comb(int i, int j) {
  if (i < 0 || j < 0)
    return 0;
  if (memo[i][j] != -1)
    return memo[i][j];
  int maxK = 0;
  // Para la Y[i] tenemos 8 opciones
  // para cada k F(i,k = max {F(i-1, k prima) | k prima y k son compatibles}
  for (int k = 0; k < 8; k++) {
    // Si k prima == j son compatibles y es un posible máximo, para cada j
    // prueba cada forma ki, para buscar su mayor compatible con la anterior
    // combinación
    if (posible(combinaciones[j], combinaciones[k])) {
      int sum = 0;
      // Recorremos combinación j para sumar en el tablero la columna y,
      // fila i
      for (int y = 0; y < 4; y++)
        if (combinaciones[j][y] == 'X')
          sum += tablero[y][i];
      maxK = max(maxK, comb(i - 1, k) + sum);
    }
  }
  return memo[i][j] = maxK;
}

// Las X representan guijarros, generamos todas las combinaciones
void combinationSring(int fila, string combinacion) {
  if (fila == 4) {
    combinaciones.push_back(combinacion);
    return;
  }
  combinationSring(fila + 1, combinacion + '_');
  if (fila == 0 || combinacion[fila - 1] == '_')
    combinationSring(fila + 1, combinacion + 'X');
}

bool solve() {
  // Filas del tablero (N)
  int X;
#ifdef DOMJUDGE
  cin >> X;

  if (!cin)
    return false;
#else
  X = 6;
#endif
  // Columnas del tablero(Y)
  int Y = 4;

#ifdef DOMJUDGE
  tablero.assign(Y, vector<int>(X, 0));
  for (int i = 0; i < Y; i++) {
    for (int j = 0; j < X; j++)
      cin >> tablero[i][j];
  }
#else
  tablero = {{100, 20, 70, 40, 10, 60},
             {90, 50, 30, 10, 15, 30},
             {30, 15, 10, 30, 50, 90},
             {60, 10, 40, 70, 20, 100}};
#endif

  int best = 0;
  // Inicializamos el tablero y la tabla de memorización, con 4 filas y X
  // columnas, y probamos con que combinación se obtiene resultado mayor
  memo.assign(X + 1, vector<int>(8, -1));
  for (int i = 0; i < 8; i++)
    best = max(best, comb(X - 1, i));

  cout << best << "\n";
  return true;
}

int main() {
  combinationSring(0, "");
  while (solve())
    ;
  return 0;
}