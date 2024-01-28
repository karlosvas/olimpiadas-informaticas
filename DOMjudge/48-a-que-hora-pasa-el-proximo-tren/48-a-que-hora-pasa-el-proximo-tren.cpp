#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

// Convierte el tiempo en segundos.
int convertSecond(int H, int M, int S) { return H * 3600 + M * 60 + S; }

bool solve() {
  int T, H; // Trenes(T), Horas(H).
  cin >> T >> H;
  vector<int> trains(T);

  if (!cin)
    return false;

  for (int t = 0; t < T; t++) {
    int HH, MM, SS;
    char d;
    cin >> HH >> d >> MM >> d >> SS;

    // Lo convertimos a segundos y lo almacenaos en el vector.
    int time = convertSecond(HH, MM, SS);
    trains[t] = time;
  }

  for (int h = 0; h < H; h++) {
    int HH, MM, SS;
    char d;
    cin >> HH >> d >> MM >> d >> SS;

    // Buscamos el primer tren que salga despues de la hora dada.
    // Tiempo en segundos de la hora dada, apuntamos a la posición anterior
    // primer tren - 1(l), y a la posición del ultimo tren + 1(r).
    int B = convertSecond(HH, MM, SS), l = -1, r = trains.size();

    // Se cumple que // trenes[0..l] < B && v[r..trains.size-1] >= B
    while (l + 1 < r) {
      // Mitad de trenes[l...r)(m).
      int m = (l + r) / 2;

      // Si el tren sale después de la hora dada, apuntamos a la posición
      // posible a r, si no a la posicion no posible a l.
      // Si es igual a B, el primer True sera r.
      if (trains[m] >= B)
        r = m;
      else
        l = m;
    }

    // Si sigue apuntado a la última posición, es que ninguno a sido True por lo
    // que no hay trenes posibles.
    if (r == trains.size())
      cout << "NO\n";
    else
      cout << setw(2) << setfill('0') << trains[r] / 3600 << ":" << setw(2)
           << setfill('0') << (trains[r] % 3600) / 60 << ":" << setw(2)
           << setfill('0') << trains[r] % 60 << "\n";
  }

  cout << "---\n";
  return true;
}

int main() {
  while (solve())
    ;
  return 0;
}