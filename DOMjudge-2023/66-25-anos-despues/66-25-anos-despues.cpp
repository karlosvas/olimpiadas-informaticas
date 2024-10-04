#include <cstdint>
#include <iostream>
#include <string>
using namespace std;

// Calcula la cantidad de ceros que tiene !k.
int64_t factorial_num_zero(int64_t k) {
  int64_t zeros = 0, i = 5;
  while ((k / i) >= 1) {
    zeros += k / i;
    i *= 5;
  }
  return zeros;
}

bool solve() {
  // Número por el que deve de ser divisible(d)
  // Cantidad de ceros buscada(n) [0...10^12]
  int64_t d, n;
  cin >> d >> n;

  if (d == 0 && n == 0)
    return false;

  // Binary Search de !k desde (d..10^12]
  // Selecionamos la cuota en la que se encuentra
  int64_t l = 0, r = 1;
  while (factorial_num_zero(d * r) < n) {
    // Si es menor que el número de ceros a conseguir, quiere decir que si hay
    // solución, se encuentra entre [l...r]
    l = r;
    // Probamos la siguiente ^2
    r <<= 1;
  }

  while (l + 1 < r) {
    // Calculamos el punto medio(k)
    int64_t k = (l + r) / 2;
    // Si el número de ceros es menor a el número buscado n, movemos el
    // limite izquierdo hacia la derecha, hasta encontrar el primero que cumpla
    // la condición
    if (factorial_num_zero(k * d) < n)
      l = k;
    else
      r = k;
  }

  // Si se encontro solución se encuentra entre [r..r+4]
  for (int64_t i = 0; i < 5; i++) {
    if (factorial_num_zero((r + i) * d) == n) {
      cout << (r + i) * d << "\n";
      return true;
    }
  }

  cout << "NINGUNO\n";

  return true;
}

int main() {
  while (solve())
    ;
  return 0;
}