#include <iostream>

using namespace std;

int main() {
  int q;
  cin >> q;

  for (int i = 0; i < q; i++) {
    string s;
    cin >> s;

    int dots = 0;
    int dash = 0;

    for (size_t i = 0; i < s.size(); i++) {
      int x = s[i] - '0';

      if (x >= 5) {
        dots += 10 - x;
        dash += x % 5;
      } else {
        dots += x;
        dash += 5 - x;
      }
    }

    cout << dots << " " << dash << endl;
  }

  return 0;
}
