#include <bits/stdc++.h>
#include <string>
using namespace std;

bool solve() {
  long long N;
  cin >> N;

  if (N == 0)
    return false;

  string binary;
  bool foundOne = false;
  for (int i = 63; i >= 0; i--) {
    if ((N >> i) & 1) {
      binary += "1";
      foundOne = true;
    } else if (foundOne) {
      binary += "0";
    }
  }

  int end = binary.find_last_of('1');
  binary = binary.substr(0, end + 1);
  string Rbinary = string(binary.rbegin(), binary.rend());

  if (binary == Rbinary)
    cout << "SI\n";
  else
    cout << "NO\n";

  return true;
}

int main() {
  while (solve())
    ;
  return 0;
}