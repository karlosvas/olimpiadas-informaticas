#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, V;
vector<int> weigth;

bool possible(int m) {
  int viajes = 0, weight = 2e9;

  for (int i = 0; i < N; i++) {
    if (weight + weigth[i] <= m) {
      weight += weigth[i];
    } else {
      viajes++;
      weight = weigth[i];
      if (weight > m)
        return false; // No se puede.
    }
  }

  return viajes <= V;
}

bool solve() {
  cin >> N >> V;

  if (N == 0)
    return false;

  weigth.assign(N, 0);
  int sumOfWeigths = 0;
  int maxWeigth = 0;
  for (int &x : weigth) {
    cin >> x;
    sumOfWeigths += x;
    maxWeigth = max(maxWeigth, x);
  }

  int l = maxWeigth - 1, r = sumOfWeigths;
  // Con un camion que soporte t No podemos hacer la mudanza en V viajes, cion
  // umo que spoporte r SI.
  while (l + 1 < r) {
    int m = (l + r) / 2;
    if (possible(m)) {
      r = m;
    } else { // No se puede.
      l = m;
    }
  }

  cout << r << "\n";
  return true;
}

int main() {
  while (solve())
    ;
  return 0;
}

// Complejiad O(N * log(sumOfWeigths))