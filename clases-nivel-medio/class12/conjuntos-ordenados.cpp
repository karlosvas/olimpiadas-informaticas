#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> v = {3, 7, 9, 10, 14, 15, 22, 29, 48, 50, 63, 68, 75, 80};

  int B = 10, l = 0, r = v.size() - 1;

  while (l <= r) {
    int m = (l + r) / 2;
    if (v[m] == B) {
      cout << "Encontrado en la posicion " << m << "\n";
      break;
    } else if (v[m] > B) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }

  if (r < l)
    cout << "No encontrado\n";
  else
    cout << " L en " << l << " y r en " << r << '\n';

  return 0;
}