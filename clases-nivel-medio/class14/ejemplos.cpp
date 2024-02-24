#include <iostream>
// #include <numeric> => gcd y lcm
using namespace std;
typedef long long int ll;

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int lcm(int a, int b) { return a * b / gcd(a, b); }

// Factorial Recursivo
ll factorialRec(int n) {
  if (n == 0)
    return 1;
  return n * factorialRec(n - 1);
}

// Factorial Iterativo
ll factorialIt(int n) {
  ll r = 1;
  while (n > 0) {
    r *= n;
    --n;
  }
  return r;
}

int main() {
  int i = 0;
  float f = i;

  while (i == f) {
    ++i;
    ++f;
  }

  cout << "El valor de i es: " << i << " valor de f es: " << f << endl;
  cout << lcm(3, 5) << endl;
  cout << gcd(3, 5) << endl;
  cout << factorialIt(10) << endl;
  cout << factorialRec(10) << endl;

  return 0;
}
