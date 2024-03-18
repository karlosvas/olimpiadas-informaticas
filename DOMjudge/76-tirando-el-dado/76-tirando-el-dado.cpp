#include <bits/stdc++.h>
using namespace std;

long memo[21][101];

long comb(int64_t i, int64_t J) {
  // Si la suma deseada es 0, solo hay una forma de obtenerla
  if (J == 0)
    return 1;
  // Si no hay más números para sumar o la suma deseada es negativa, no hay
  if (i == 0 || J < 0)
    return 0;
  // Si ya se ha calculado el valor, se retorna
  if (memo[i][J] != -1)
    return memo[i][J];
  // Devido a que se puede utilizar el mismo número más de una vez, no se resta
  // 1 a i
  int64_t includes = comb(i, J - i);
  int64_t excludes = comb(i - 1, J);
  return memo[i][J] = includes + excludes;
}

int main() {
  int64_t C;
  cin >> C;
  while (C--) {
    // Número de caras del dado(N), suma deseada(S)
    int64_t N, S;
    cin >> N >> S;

    memset(memo, -1, sizeof(memo));
    cout << comb(N, S) << "\n";
  };
  return 0;
}