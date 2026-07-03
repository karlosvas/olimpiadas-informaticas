#include <iostream>
#include <map>
#include <vector>
using namespace std;

static bool query(map<int, vector<int>> &m, int long_sec, int n) {
  for (int key = 1; key <= n; ++key) {
    if (m.find(key) != m.end())
      continue;

    for (int j = 1; j <= long_sec; ++j) {
      if (key == j)
        continue;
      cout << "? 2 " << key << " " << j << endl;
      int ans;
      cin >> ans;
      if (ans == -1)
        return false;
      if (ans == 0)
        m[key].push_back(j);
    }

    int sz = m[key].size();
    if (sz == 3) {
      cout << "! " << m[key][0] << " " << m[key][1] << " " << m[key][2] << endl;
      return false;
    } else if (sz == 2) {
      int j1 = m[key][0], j2 = m[key][1];
      cout << "? 3 " << key << " " << j1 << " " << j2 << endl;
      int ans;
      cin >> ans;
      if (ans == -1)
        return false;
      if (ans == 0) {
        cout << "! " << key << " " << j1 << " " << j2 << endl;
        return false;
      }
    }
  }
  return true;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int long_sec = 2 * n + 1;
    map<int, vector<int>> m;
    query(m, long_sec, n);
  }
  return 0;
}
