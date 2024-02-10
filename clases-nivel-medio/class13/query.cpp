#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int random(int a, int b) { return a + rand() % (b - a + 1); }

int ini, fin, N;
#define DOMJUDGE

#ifndef DOMJUDGE
string query(int m) {
  if (m <= N)
    return "<=";
  else
    return ">";
}
#else
string query(int m) {
  cout << "? " << m << endl;
  string ans;
  cin >> ans;
  return ans;
}
#endif

bool solve() {
#ifndef DOMJUDGE
  int ini = 1, fin = 1000000;
#else
  cin >> ini >> fin;
#endif

  if (ini == 0 && fin == 0)
    return false;

#ifndef DOMJUDGE
  N = random(ini, fin);
#endif

  int l = ini - 1, r = fin;
  while (l + 1 < r) {
    int m = (l + r) / 2;
    if (query(m) == "<=")
      r = m;
    else
      l = m;
  }

#ifndef DOMJUDGE
  cout << "Respuesta:  " << r << endl;
#else
  cout << "Respuesta:  " << r << endl;
#endif

  return true;
}

int main() {
#ifndef DOMJUDGE
  for (int i = 0; i < 100; i++)
    solve();
#else
  while (solve())
    ;
#endif
  return 0;
}