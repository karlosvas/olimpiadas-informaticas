#include <bits/stdc++.h>
#include <sstream>
using namespace std;

vector<vector<int>> memo;

// Subsecuencia común mas larga
int comb(int i, int j, const vector<string> &X, const vector<string> &Y) {
  // Si nos quedamos sin alguno de las secuencias no se puede
  if (i >= X.size() || j >= Y.size())
    return 0;
  if (memo[i][j] != -1)
    // SI ya esta calculada retornamos su valor
    return memo[i][j];
  // Si son iguales la pr
  if (X[i] == Y[j]) {
    return memo[i][j] = comb(i + 1, j + 1, X, Y) + 1;
  } else {
    return memo[i][j] = max(comb(i + 1, j, X, Y), comb(i, j + 1, X, Y));
  }
}

// Lector de entrada con sstring
vector<string> leer() {
  string linea;
  getline(cin, linea);
  if (!cin)
    return {};
  vector<string> V;
  stringstream ss(linea);
  // Metemos cada palabra en el vector de la secuencia
  string palabra;
  while (ss >> palabra)
    V.push_back(palabra);
  return V;
}

bool solve() {
  vector<string> X, Y;
  // Leemos la lista de los de la mañana
  X = leer();
  if (!cin)
    return false;
  // Leemos la lista de los de la tarde
  Y = leer();

  // Inizializamos la tabla de momorizaición
  memo.assign(X.size() + 1, vector<int>(Y.size() + 1, -1));

  // Buscamos la subsecuencia común mas larga, rellendo memo
  int longest = comb(0, 0, X, Y);

  // Reconstrución de solución, desde [0][0]
  int i = 0, j = 0;
  vector<string> res;
  while (i < X.size() && j < Y.size()) {
    if (X[i] == Y[j]) {
      res.push_back(X[i]);
      i++;
      j++;
    } else {
      if (memo[i + 1][j] > memo[i][j + 1]) {
        i++;
      } else {
        j++;
      }
    }
  }

  // Mostramos la solución
  if (res.size() > 0) {
    cout << res[0];
    for (int i = 1; i < res.size(); i++) {
      cout << ' ' << res[i];
    }
  }

  cout << '\n';
  return true;
}

int main() {
  while (solve())
    ;
  return 0;
}