#include <bits/stdc++.h>
using namespace std;

int main() {
  // Casos de prueba
  int C;
  cin >> C;

  while (C--) {
    // Numero factorial !N, cantidad de ceros(zeros).
    long long N, zeros = 0;
    cin >> N;

    // Si N es menor a 5, no hay ceros.
    if (N < 5) {
      cout << 0 << "\n";
      continue;
    } else {
      // Contar la cantidad de ceros, cada multiplo de 5, 25, 125, 625, 3125,
      // etc, se suma un cero, adicional.
      long long i = 5;
      while ((N / i) >= 1) {
        zeros += N / i;
        i *= 5;
      }
    }
    cout << zeros << "\n";
  }

  return 0;
}