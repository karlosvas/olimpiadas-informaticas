#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> v = {3, 7, 9, 10, 10, 10, 22, 29, 48, 50, 63, 68, 75, 80};
  int N = 14, B = 10, l = -1, r = N;

  while (l + 1 < r) {
    int m = (l + r) / 2;
    if (v[m] < B)
      l = m;
    else
      r = m;
  }

  if (r < N && v[r] == B) {
    cout << "Esta en la posicion " << r << "\n"; // Posicion 3

    l = -1, r = N; // v[0..l] <= B && v[r..N-1] > B
    while (l + 1 < r) {
      int m = (l + r) / 2;
      if (v[m] <= B) {
        l = m;
      } else // v[m] > B
        r = m;
    }
    cout << "Está por ultima vez en la posicion" << l << "\n"; // Posicion 5
  } else
    cout << "No encontrado\n";

  return 0;
}