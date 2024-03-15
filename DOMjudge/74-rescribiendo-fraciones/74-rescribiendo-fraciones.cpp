#include <bits/stdc++.h>
#include <bitset>
using namespace std;

const int64_t MAXN = 46400;
bitset<MAXN> bs;

void factorizarPrimos() {
  bs.set();
  bs[0] = bs[1] = 0;
  for (int64_t i = 2; i * i < MAXN; i++) {
    if (bs[i]) {
      for (int64_t j = i * i; j < MAXN; j += i)
        bs[j] = 0;
    }
  }
}

int main() {
  // Precalculo de Criba de Eratóstenes
  factorizarPrimos();
  // 1/k = 1/a + 1/b
  int64_t k;
  while (cin >> k) {
    // Calculamos el número de divisores, un número k puede ser
    // representado como el producto de sus factores primos elevados a sus
    // exponentes (veces que se repiten) + 1
    // k = (e1+1)*(e2+1)*...*(ek+1)
    int64_t divisores = 1;

    int64_t exp = 0;
    while (k % 2 == 0) {
      k /= 2;
      exp++;
    }
    if (exp > 0)
      divisores *= (2 * exp) + 1;

    int64_t i = 3;
    while (i * i <= k) {
      if (k % i == 0 && bs[i]) {
        int64_t exp = 0;
        while (k % i == 0) {
          k /= i;
          exp++;
        }
        // *2 porque para cada divisor dado hay dos posibilidades x, y, el
        // +1 se utiliza para incluir e^0
        divisores *= (2 * exp) + 1;
      }
      i += 2;
    }

    // Si k es > 1 es un factor primo de si mismo, 2*1+1 = 3
    if (k > 1)
      divisores *= 3;

    // Devido a la propiedad conmulativa las parejas que se consideran iguales
    // deverán contarse una unica vez, ya que a+b = b+a
    cout << divisores / 2 + 1 << endl;
  }
  return 0;
}