#include <bits/stdc++.h>
using namespace std;

int MOD = 46337;
int MAX = 1001;

// Dinamic programing dp, almacena las respuestas anteriores si ya se calcularon
vector<int> dp(MAX, -1);
vector<vector<int>> memo(MAX, vector<int>(MAX, -1));

// Todas las formas posibles de llegar a j con i caracoles
int comb(int i, int j) {
  if (j > i || j < 0)
    return 0;
  if (memo[i][j] != -1)
    return memo[i][j];
  else
    return memo[i][j] = (comb(i - 1, j) + comb(i - 1, j - 1)) % MOD;
}

// Formas de rellenar un marcador con n caracoles
int caracoles(int n) {
  // Si ya se ha calculado se devuelbe
  if (dp[n] != -1)
    return dp[n];
  // [k...N] donde cada ki es el número de caracoles que llegarían juntos a la
  // meta * formas de rellenar un marcador de n-k caracoles
  int res = 0;
  for (int k = 1; k <= n; ++k)
    res = (res + (comb(n, k) * caracoles(n - k)) % MOD) % MOD;
  return dp[n] = res;
}

int main() {
  // Cantidad de formas de escoger 0 elementos de un conjunto de 0 elementos 1
  // forma.
  memo[0][0] = 1;
  // Una forma es el marcado vacío, dp[0] = 1. O un único caracol cruza la
  // línea de meta y ocupa el primer lugar por lo que dp[1] = 1.
  dp[0] = dp[1] = 1;
  int n;
  while (cin >> n) {
    cout << caracoles(n) << '\n';
  }
  return 0;
}