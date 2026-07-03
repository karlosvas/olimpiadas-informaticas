#include <bitset>
#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    long long n, k;

    // size(n), milisecounds(k)
    cin >> n >> k;

    // bits(s)
    string s;
    cin >> s;

    bitset<100000> b(s);

    while (k > 0) {
      auto last = b >> 1;
      auto next = b << 1;

      last[n - 1] = b[0];
      next[0] = b[n - 1];

      b = last ^ next;

      k--;
    }

    for (int i = n - 1; i >= 0; i--)
      cout << b[i];
    cout << endl;
  }

  return 0;
}
