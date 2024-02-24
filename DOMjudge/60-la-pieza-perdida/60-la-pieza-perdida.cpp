#include <iostream>
#include <string>
using namespace std;

bool solve() {
  int N;
  cin >> N;

  if (N == 0)
    return false;

  // Suma total de la sucesión desde 1...N (sum_T)
  // Suma de la sucesión de los k números (sum_K)
  int sum_T = 0, sum_K = 0;

  for (int i = 1; i <= N; i++) {
    if (i != N) {
      // Caso de prueba con N-1 números (K)
      int k;
      cin >> k;
      sum_K += k;
    }
    // Suma total de la sucesión
    sum_T += i;
  }

  // La pieza perdida es la diferencia entre la suma total de la sucesión y la
  // suma de los k números
  cout << (sum_T - sum_K) << "\n";
  return true;
}

int main() {
  while (solve())
    ;
  return 0;
}