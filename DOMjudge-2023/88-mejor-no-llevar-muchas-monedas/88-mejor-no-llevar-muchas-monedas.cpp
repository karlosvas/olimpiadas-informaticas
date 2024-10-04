#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 7;
vector<int> values;
vector<vector<int>> memo;

struct tMoneda {
  int tipos, cantidad;
};

#define DOMJUDGE

int comb(vector<tMoneda> &moneda, int i, int j) {
  // Casos base, j=0 no necesitamos monedas, si el ídice o cantidad es < 0 no
  // podemos formarla, y si ya se calculó la devolbemos
  if (j == 0)
    return 0;
  if (i < 0 || j < 0)
    return inf;
  if (memo[i][j] != -1)
    return memo[i][j];
  // Mínimo de monedas de cada [i][j](k)
  int res = inf;
  // Desde  [0... disponibles && monedas para formar j sin pasarnos]

  // El min k, es aquel entre los anteriores i-1, que es la cantidad restante
  // después de haber calculado k monedas de tipo i. k * mi.tipos es la cantidad
  // total que podemos formar usando k monedas tipo i, - j para restarselo a la
  // cantidad restante que necesitamos para formar j y + k porque hemos usado k
  // monedas de tipo i
  int maxK = min(moneda[i].cantidad, j / moneda[i].tipos);
  for (int k = 0; k <= maxK; ++k)
    res = min(res, comb(moneda, i - 1, j - k * moneda[i].tipos) + k);
  return memo[i][j] = res;
}

bool solve() {
  // Tipos de monedas (N)
  int N;
#ifdef DOMJUDGE
  cin >> N;
#else
  N = 4;
#endif

  if (!cin)
    return false;

  // Valores de las monedas de cada tipo (valores)
  // Cantidad de monedas que tiene de cada uno de esos tipos (cantidad)
  vector<tMoneda> moneda(N);

#ifdef DOMJUDGE
  for (int i = 0; i < N; ++i)
    cin >> moneda[i].tipos;
  for (int i = 0; i < N; ++i)
    cin >> moneda[i].cantidad;
#else
  moneda = {{1, 10}, {5, 2}, {10, 5}, {50, 4}};
#endif

  // Precio del coche(C)
  int C;
#ifdef DOMJUDGE
  cin >> C;
#else
  C = 260;
#endif

  // Inicializamos la tabla de memorización
  memo.assign(N, vector<int>(C + 1, -1));
  // Mínimo número de monedas necesarias para pagar C
  int coins = comb(moneda, N - 1, C);

  if (coins == inf)
    cout << "NO\n";
  else
    cout << "SI " << coins << "\n";

  return true;
}

int main() {
  while (solve())
    ;
  return 0;
}
