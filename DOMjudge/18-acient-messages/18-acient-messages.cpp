#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

bool blanco = false;
bool negro = true;
int incF[4] = {-1, 0, 1, 0};
int incC[4] = {0, 1, 0, -1};

// Convertimos sus caracteres hexadecimales a su valor binario.
void hexa_to_bin(string &linea, vector<bool> &v) {
  for (string::size_type i = 0; i < linea.length(); i++) {
    int interval = 0;
    // Si es mayor que 'a' es una letra, por lo que deveremos restarle a, y
    // sumarle 10, ya que A empieza en 10, si no lo convertimos a int.
    if (linea[i] >= 'a')
      interval = linea[i] - 'a' + 10;
    else
      interval = linea[i] - '0';

    // Resultado con los 4 bits binarios.
    for (int j = 3; j >= 0; --j) {
      // Si el resto de el intervalo entre 2, da 1 = true, es negro, si es 0 =
      // false es blanca.
      if (interval % 2)
        v[4 * i + j] = negro;
      else
        v[4 * i + j] = blanco;
      // Para convertir a binario, debemos ir desglosando cada potencia de dos.
      interval /= 2;
    }
  }
}

// Bfs para marcar las casillas blancas.
void marcaBlanco(int i, int j, int H, int W, vector<vector<bool>> &marked,
                 vector<vector<bool>> &m) {
  marked[i][j] = true;
  // Nuevo i(k), nuevo j(l) en las 4 direciones.
  for (int d = 0; d < 4; ++d) {
    // Si esta dentro de los límites, se llama de forma recursiva.
    int k = i + incF[d], l = j + incC[d];
    if (k >= 0 && k < H && l >= 0 && l < W && m[k][l] == blanco &&
        !marked[k][l])
      marcaBlanco(k, l, H, W, marked, m);
  }
}

// Bfs que cuenta los huecos blancos y marca por donde pasa.
void marcaNegro(int i, int j, int &huecos, int H, int W,
                vector<vector<bool>> &marked, vector<vector<bool>> &m) {
  marked[i][j] = true;
  // Nuevo i(k), nuevo j(l) en las 4 direciones.
  for (int d = 0; d < 4; ++d) {
    // Si esta dentro de los limites se llama de forma recursiva.
    int k = i + incF[d], l = j + incC[d];
    if (k >= 0 && k < H && l >= 0 && l < W && !marked[k][l]) {
      if (m[k][l] == blanco) {
        ++huecos;
        marcaBlanco(k, l, H, W, marked, m);
      } else {
        marcaNegro(k, l, huecos, H, W, marked, m);
      }
    }
  }
}

bool solve(int caso) {
  int H, W;
  // Altura(H), Anchura(W).
  cin >> H >> W;

  if (H == 0)
    return false;

  // En cada fila multiplicamos cada caracter porque está en hexadecimal por lo
  // que un dígito son 4 bits.
  W *= 4;

  // Matriz donde se encuentra la imagen(m).
  vector<vector<bool>> m(H, vector<bool>(W, false));

  for (int h = 0; h < H; ++h) {
    string linea;
    cin >> linea;
    // Leemos la entrada y la pasamos a binario.
    hexa_to_bin(linea, m[h]);
  }

  // Vector de boleanos para saber por donde hemos pasado.
  vector<vector<bool>> marked(H, vector<bool>(W, false));

  // Marcamos el fondo de blanco, como visitado.
  // Horizontal.
  for (int j = 0; j < W; ++j) {
    if (m[0][j] == blanco && !marked[0][j])
      marcaBlanco(0, j, H, W, marked, m);
    if (m[H - 1][j] == blanco && !marked[H - 1][j])
      marcaBlanco(H - 1, j, H, W, marked, m);
  }
  // Vertical.
  for (int i = 1; i < H - 1; ++i) {
    if (m[i][0] == blanco && !marked[i][0])
      marcaBlanco(i, 0, H, W, marked, m);
    if (m[i][W - 1] == blanco && !marked[i][W - 1])
      marcaBlanco(i, W - 1, H, W, marked, m);
  }

  // Para cada pixel nuevo encontrado, marcamos el dibujo al que pertenece,
  // averiguando cuantos huecos blancos contiene.
  string res;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      // Cada vez que encuentre un pixel negro que no este marcado, quiere decir
      // que es un geglífiico diferente.
      if (m[i][j] == negro && !marked[i][j]) {
        int huecos = 0;
        // Llamamos a un bfs, que cuenta huecos blancos.
        marcaNegro(i, j, huecos, H, W, marked, m);
        // Dependiendo de los huecos encontrados damos una solución.
        switch (huecos) {
        case 0:
          res.push_back('W'); // Was
          break;
        case 1:
          res.push_back('A'); // Ankh
          break;
        case 2:
          res.push_back('K'); // Akhet
          break;
        case 3:
          res.push_back('J'); // Wedjat
          break;
        case 4:
          res.push_back('S'); // Scarab
          break;
        case 5:
          res.push_back('D'); // Djed
          break;
        }
      }
    }
  }

  sort(res.begin(), res.end());
  // Ordenamos la respuesta y mostramos el resultado, con el caso actual y la
  // figura encontrada.
  cout << "Case " << caso << ": " << res << endl;
  return true;
}

int main() {
  // ios_base desincroniza las operaciones de entrada/salida con operaciones
  // estandar.
  ios_base::sync_with_stdio(false);
  // .tie evita el flushing automático, desvincula la entrada estándar (cin)
  // de la salida estándar (cout).
  cin.tie(nullptr);
  int caso = 0;
  while (solve(++caso))
    ;
  return 0;
}