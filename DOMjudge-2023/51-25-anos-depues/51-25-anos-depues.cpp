#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Devuelbe la cantidad de 0 al final de el factorial de un número N
int64_t FactorialCeros(int64_t N) {
  // Siempre que sea divisor de 5 tiene ceros la cantidad de veces que sea
  // divisible por 5.
  // Cada vez que sea una potencia de 5 tiene + 1 cero adicional
  int64_t i = 5, zero = 0;
  while ((N / i) >= 1) {
    zero += N / i;
    i *= 5;
  }
  return zero;
}

bool solve() {
  // Número por el que tiene que ser divisible(d)
  // Cantidad de ceros(n)
  int64_t d, n;
  cin >> d >> n;

  if (d == 0 && n == 0)
    return false;

  // Selecionamos la cuota de factores de (k * d) < n
  int64_t l = 0, r = 1;
  while (FactorialCeros(d * r) < n) {
    // Si es menor que el número de ceros a conseguir, quiere decir que si hay
    // solución, se encuentra entre [l...r]
    l = r;
    // Probamos la siguiente ^2
    r <<= 1;
  }

  // Buscamos el número factorial que multiplicado por d tenga n ceros
  while (l + 1 < r) {
    // K prima(k_i)
    int64_t k = (l + r) / 2;

    // Si el factorial del número divisible por d es al menos r, pasa a ser r
    if (FactorialCeros(d * k) < n)
      l = k;
    else
      r = k;
  }

  // AL terminar la solución está almacenada en r
  // Si d * k tiene exactamante n ceros se encontró un número tal
  if (FactorialCeros(d * r) == n)
    cout << d * r << "\n";
  else
    cout << "NINGUNO\n";

  return true;
}

int main() {
  while (solve())
    ;
  return 0;
}