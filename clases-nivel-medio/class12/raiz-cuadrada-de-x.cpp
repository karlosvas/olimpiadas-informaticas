#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  // int64_t == long long, evita el desbordamiento.
  int64_t N = 100000, l = 1, r = N, i = 0;

  // l*l <= N && r*r > N
  while (l + 1 < r) {
    int64_t m = (l + r) / 2;
    ++i;
    if (m * m <= N)
      l = m;
    else // m*m > N
      r = m;
  }

  cout << " La raiz cuadrada de " << N << " es " << l << "en " << i << " pasos"
       << "\n";

  return 0;
}