#include <bits/stdc++.h>
#include <cassert>
using namespace std;

void factorizar(long long n) {
  assert(n >= 2);

  cout << n << " =";

  while ((n % 2) == 0) {
    cout << " 2";
    n /= 2;
  }

  long long p = 3;

  while (p * p <= n) {
    while ((n % p) == 0) {
      cout << " " << p;
      n /= p;
    }
    p += 2;
  }

  if (n != 1) {
    cout << " " << n;
  }
  cout << endl;
}

int main() {
  factorizar(2);
  factorizar(4);
  factorizar(15);
  factorizar(2146483647);
  return 0;
}