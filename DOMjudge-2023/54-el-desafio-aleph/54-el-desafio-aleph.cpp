#include <iostream>
#include <string>
#include <vector>
using namespace std;

int S;
#define DOMJUDGE

// Generador de números aleatorios entre a y b.
int random(int a, int b) { return a + rand() % (b - a + 1); }

#ifdef DOMJUDGE
string quest(int m) {
  cout << "? " << m << endl;
  // Respuesta Gran maestro de los sabios.
  string x;
  cin >> x;
  return x;
}
#else
string quest(int m) { return (m < S) ? ">" : "<="; }
#endif

bool solve() {
  int l = 0, r = 0;
#ifdef DOMJUDGE
  cin >> l >> r;
#else
  l = random(0, 500000);
  r = random(l, 1000000);
  S = random(l, r);
#endif

  if (l == 0 && r == 0)
    return false;

  // Busqueda binaria desde (l, r]
  --l;
  while (l + 1 < r) {
    int m = (l + r) / 2;
    string res = quest(m);

    // Si el número secreto es mayor que m movemos la izquierda, si es igual o
    // menor movemos la derecha.
    if (res == ">") {
      l = m;
    } else if (res == "<=") {
      r = m;
    }
  }

  // Número secreto del gran Aleph
  cout << "Respuesta: " << r << endl;
#ifndef DOMJUDGE
  cout << "Se espera: " << S << endl;
#endif

  return true;
}

int main() {
#ifdef DOMJUDGE
  while (solve())
    ;
#else
  for (int n = 0; n < 100; n++) {
    solve();
    if (n == 99)
      cout << "Breakpoint" << endl;
  }
#endif

  return 0;
}