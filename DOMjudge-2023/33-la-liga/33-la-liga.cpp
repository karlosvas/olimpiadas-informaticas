#include <iostream>
#include <set>
using namespace std;

bool solve() {
  int N;
  cin >> N;
  set<int> cromos;

  if (N == 0)
    return false;

  for (int n = 0; n < N; n++) {
    int cromo;
    cin >> cromo;
    cromos.insert(cromo);
  }

  cout << cromos.size() << "\n";

  return true;
}

int main() {
  while (solve()) {
  }
  return 0;
}