#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> memo;
int N;

struct movie {
  int date;
  int duration;
};

vector<movie> movies;

// Momento en el que se termína la (i) película y se toma unas palomitas
// StartNext(j) = Inicio de la siguiente película para ver en horas.
bool can_watch(int date, int duration, int startNext) {
  // Si el tiempo es > 1440 = 24:00, han cerrado, si no miramos si hay al menos
  // una diferencia de 10 entre el comienzo de la siguiente y el final de la
  // anterior
  int endTime = date + duration;
  if (endTime > 1440)
    return false;
  return startNext - endTime >= 10;
}

// Cambiamos la fecha a minutos, substr no incluye el último elemento
int toMin(string date) {
  return (stoi(date.substr(0, 2)) * 60) + stoi(date.substr(3));
}

// Secuencia creciente mas larga
// Cuanto es el mayor tiempo que puedo estar viendo las películas si tengo las
// películas de la 1 hasta la última y no puedo ver peliculas que comienzen
// antes de j +10
int LIS(int i) {
  // Si es N ya recorrioó todas las películas
  if (i == N)
    return 0;
  if (memo[i] != -1)
    return memo[i];

  int maxJ = 0;
  // Buscamos desde la siguientes opciones de películas hasta probar con todas
  for (int j = i + 1; j <= N; ++j) {
    //  Si j es la última película o si se puede ver la siguiente porque no
    //  sobrepone la anterior en tiempo, lo probamos como máxima secuencia
    if (j == N || can_watch(movies[i].date, movies[i].duration, movies[j].date))
      maxJ = max(maxJ, movies[i].duration + LIS(j));
  }

  return memo[i] = maxJ;
}

bool solve() {
  // películas que se proyectaran(N)
  cin >> N;

  if (N == 0)
    return false;

  movies.assign(N, {});
  for (int n = 0; n < N; n++) {
    string date;
    cin >> date >> movies[n].duration;
    movies[n].date = toMin(date);
  }

  // Da igual el orden en el que ordenemos las películas
  sort(movies.begin(), movies.end(),
       [](const movie &a, const movie &b) { return a.date < b.date; });

  // Inicializamos la tabla de memorización
  memo.assign(N, -1);

  // Selecionamos por cual ipelícula es mejor empezar, y selecionamos la
  // secuncia creciente mas larga
  int bestTime = 0;
  for (int i = N - 1; i >= 0; i--)
    bestTime = max(bestTime, LIS(i));
  cout << bestTime << "\n";

  return true;
}

int main() {
  while (solve())
    ;
  return 0;
}