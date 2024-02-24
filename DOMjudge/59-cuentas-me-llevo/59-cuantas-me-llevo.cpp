#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

bool solve() {
  string A, B;
  cin >> A >> B;

  if (A == "0" && B == "0")
    return false;

  reverse(A.begin(), A.end());
  reverse(B.begin(), B.end());

  int acarreo_total = 0;
  int acarreo = 0;

  for (size_t i = 0; i < max(A.size(), B.size()); i++) {
    // Lo convertimos a int restandole el char '0'.
    int num_A = 0, num_B = 0;

    if (i < A.size())
      num_A = A[i] - '0';
    if (i < B.size())
      num_B = B[i] - '0';

    // El número actual es la pocición i de A y la i de B + el acarreo.
    int num = num_A + num_B + acarreo;
    acarreo = 0;

    if (num > 9) {
      // Nuevo acarreo encontrado.
      // la cantidad de veces que un número sea divisible entre 10 es su
      // acarreo.
      while (num >= 10) {
        num /= 10;
        acarreo++;
      }
      // Sumamos el acarreo de este i.
      acarreo_total += acarreo;
    }
  }

  cout << acarreo_total << "\n";
  return true;
}

int main() {
  while (solve())
    ;
  return 0;
}