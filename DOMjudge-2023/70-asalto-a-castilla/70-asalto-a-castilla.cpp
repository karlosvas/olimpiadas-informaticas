#include <bits/stdc++.h>
using namespace std;

bool solve() {
  // Hoimbres que dispone Jaime(N)
  int N;
  cin >> N;

  if (N == 0)
    return false;

  // Cuantas veces se puede dividir el número
  int divisible = 0;
  for (int n = 1; n * n <= N; n++) {
    // Si el la division de escuadrones es divisible por n, también lo será por
    // n^2
    if (N % n == 0) {
      if (n * n == N)
        divisible++;
      else
        divisible += 2;
    }
  }

  cout << divisible << "\n";

  return true;
}

int main() {
  while (solve())
    ;
  return 0;
}