#include <bits/stdc++.h>
#include <cassert>
using namespace std;

void factorizarRec(int n) {
  long long p = 2;

  while (p * p <= n && (n % p) != 0) {
    ++p;
  }

  if (n % p == 0) {
    cout << " " << p;
    factorizarRec(n / p);
  } else {
    if (n != 1)
      cout << " " << n;
  }
}

void factorizar(long long n) {
  assert(n >= 2);
  factorizarRec(n);
  cout << endl;
}

int main() {
  factorizar(2);
  factorizar(4);
  factorizar(15);
  return 0;
}