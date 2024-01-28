#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool solve() {

  int N;
  cin >> N;
  vector<int> problems(N);

  if (!cin)
    return false;

  for (int n = 0; n < N; n++) {
    int p;
    cin >> p;
    problems[n] = p;
  }

  int P;
  cin >> P;
  for (int p = 0; p < P; p++) {
    // Número buscado de problemas resueltos(C).
    int C;
    cin >> C;

    // Binary search
    // Número de elementos(N) entre (l..r]
    int N = problems.size(), l = -1, r = N;

    while (l + 1 < r) {
      // Mitad del intervalo
      int m = (l + r) / 2;
      // Si es menor que C, movemos la derecha hacia m, si es mayor,
      // movemos la izquierda hacia m.
      if (problems[m] < C)
        r = m;
      else
        l = m;
    }

    if (l < N && problems[l] == C) {
      // Si l es menor que N y el elemento en la posición l es igual a C,
      // obteremos la pocicion del último elemento igual a C y le sumamos 1
      // porque empieza desde 1 a N.
      int last = l + 1;

      // El intervalo se reduce a (-1..last]
      r = l, l = -1;
      while (l + 1 < r) {
        int m = (l + r) / 2;
        // Si es menor o igual que C, movemos la derecha hacia m, si es mayor,
        if (problems[m] <= C)
          r = m;
        else
          l = m;
      }

      // El primer elemento igual a C es la posición r + 1 porque va de 1 a N.
      int first = r + 1;

      cout << first << " " << last << "\n";
    } else
      cout << "NO HAY\n";
  }

  cout << "---\n";
  return true;
}

int main() {
  while (solve())
    ;
  return 0;
}