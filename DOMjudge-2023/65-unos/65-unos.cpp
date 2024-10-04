#include <bits/stdc++.h>
#include <string>
using namespace std;

bool solve() {
  // Número impar no terminado en cinco, (0, 1.000.000]
  long long N;
  cin >> N;

  if (!cin)
    return false;

  long long longitud = 1;
  long long potencia = 1;

  while (potencia % N != 0) {
    // [11, 111, 1111, ...]
    potencia = (potencia * 10 + 1) % N;
    longitud++;
  }

  cout << longitud << "\n";

  return true;
}

int main() {
  while (solve())
    ;
  return 0;
}