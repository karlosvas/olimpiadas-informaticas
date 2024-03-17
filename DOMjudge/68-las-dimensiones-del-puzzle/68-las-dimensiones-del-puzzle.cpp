#include <bits/stdc++.h>
#include <cmath>
using namespace std;

bool solve() {
  // Númerto total de piezas del puzzle(N)
  int N;
  cin >> N;

  if (N == 0)
    return false;

  // El máximo de uno de sus lados es la raíz cuadrada de N, ya que x * y =
  // N, por lo que buscamos el mínimo divisor de N que sea mas cercano a la raíz
  // cuadrada
  int divisor = 1;
  int count = 1;
  for (int i = 1; i * i <= N; i++, count++) {
    if (N % i == 0)
      divisor = i;
  }

  // x = divisor, y = N / divisor
  // El lado mas largo del puzzle será N / divisor mas cercano a la raíz
  // cuadrada
  cout << N / divisor << "\n";

  return true;
}

int main() {
  while (solve())
    ;
  return 0;
}