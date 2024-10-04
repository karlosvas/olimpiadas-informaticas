#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

#define DOMJUDGE

vector<int> P;
vector<int> test = {25, 60, 24, 145};

int quest(int &a, int &b) {
  cout << "? " << a << " " << b << endl;
  int x;
#ifdef DOMJUDGE
  // Respuesta del juez
  cin >> x;
#else
  x = test[a - 1] + test[b - 1];
#endif
  return x;
}

// Muestra el vector de energias
void showEnergy() {
  for (int i = 0; i < P.size(); i++) {
    if (i == P.size() - 1)
      cout << P[i] << endl;
    else
      cout << P[i] << " ";
  }
}

bool solve() {
  int N;
  P.clear();

#ifdef DOMJUDGE
  cin >> N;
#else
  N = 4;
  test.clear();
#endif

  if (N == 0)
    return false;

  int a = 1, b = 2, c = 3;

  int ab = quest(a, b);
  int ac = quest(a, c);
  int bc = quest(b, c);
  // Valor de a, [ab+ac-bc] = 2a; 2a/2 = a
  int x = (ab + ac - bc) / 2;
  P.push_back(x);
  // P[0] == a, P[1] == b, P[2] == c;
  x = ab - P[a - 1];
  P.push_back(x);
  // b = ab - a
  x = bc - P[b - 1];
  // c = bc - b
  P.push_back(x);

  int d = c + 1;

  while (P.size() != N) {
    // Y asi sucesivamente hasta llenar el vector de energias.
    int cd = quest(c, d);
    x = cd - P[c - 1];
    P.push_back(x);
    c++;
    d++;
  }

  cout << "Respuesta: ";
  showEnergy();

  return true;
}

int main() {
  while (solve())
    ;
  return 0;
}