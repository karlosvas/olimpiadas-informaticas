#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define DOMJUDGE
int NX, NY;

// Genera un numero aleatorio entre a y b.
int random(int a, int b) { return a + rand() % (b - a + 1); }

// Si el dron esta en un X Y y los parasoles mordisuquearon los girasoles,
// devuelve 1, sino esta los girasoles miran al sol 0.
#ifdef DOMJUDGE
int query(int &mx, int &my) {
  cout << "? " << mx << " " << my << endl;
  // Respuesta del juez
  int ans;
  cin >> ans;
  return ans;
}
#else
bool query(int &mx, int &my) { return mx >= NX && my >= NY; }
#endif

pair<int, int> binarySearch(int &TamX, int &TamY) {
#ifndef DOMJUDGE
  // Genera un número aleatorio entre 1...TamX y 1...TamY para generar
  // soluciones.
  NX = random(1, TamX);
  NY = random(1, TamY);
#endif

  // Binary search del primer parasol que mordisquiea los girasoles en el ultimo
  // Y, desde [1..TamX].
  int lx = 0, rx = TamX;

  while (lx + 1 < rx) {
    // Mitad en X (horizontalmente)
    int mx = (lx + rx) / 2;
    // Mientras no se encuentre el parasol que mordisquiea los girasoles, se
    // mueve la izquierda si se enuentra la derecha.
    if (query(mx, TamY)) {
      rx = mx;
    } else {
      lx = mx;
    }
  }

  // Binary search con la X del primer parasol que mordisquieo los girasoles
  // desde [1..TamY], para encontrar el primero.
  int ly = 0, ry = TamY;

  while (ly + 1 < ry) {
    // Mitad en Y (vericalmente)
    int ml = (ly + ry) / 2;
    if (query(rx, ml)) {
      ry = ml;
    } else {
      ly = ml;
    }
  }

  return {rx, ry};
}

bool solve() {
#ifdef DOMJUDGE
  int TamX, TamY;
  cin >> TamX >> TamY;
#else
  int TamX = rand(), TamY = rand();
#endif

  if (TamX == 0 && TamY == 0)
    return false;

  pair<int, int> result = binarySearch(TamX, TamY);

  // Imprime la respuesta
  cout << "=> " << result.first << " " << result.second << endl;
#ifndef DOMJUDGE
  cout << "Respuesta: " << NX << " " << NY << endl;
#endif
  return true;
}

int main() {
#ifdef DOMJUDGE
  while (solve())
    ;
#else
  for (int i = 0; i < 100; i++) {
    solve();
    if (i == 99)
      cout << "Stop for debuggin" << endl;
  }
#endif
  return 0;
}