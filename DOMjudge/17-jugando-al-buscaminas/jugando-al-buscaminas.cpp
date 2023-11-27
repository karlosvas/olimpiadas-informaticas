#include <vector>
#include <iostream>
#include <string>
using namespace std;

using Map = vector<vector<char>>;
Map table, solution;
vector<vector<bool>> visit;

int incX[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int incY[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int F, C;

void dfs(int y, int x) {
    visit[y][x] = true;
    int bomba = 0;
    
    // Cuenta las bombas adyacentes en x y.
    for (int pos = 0; pos < 8; ++pos) {
        int nx = x + incX[pos], ny = y + incY[pos];

        if (0 <= nx && nx < C && 0 <= ny && ny < F && table[ny][nx] == '*') {
            bomba++;
        }
    }
    
    // Actualiza el valor en el tablero, si es un x y es un numero no se llamara posteriormente a dfs.
    if (bomba > 0) table[y][x] = bomba + '0';

    for (int pos = 0; pos < 8; ++pos) {
        int nx = x + incX[pos], ny = y + incY[pos];
        if (0 <= nx && nx < C && 0 <= ny && ny < F && !visit[ny][nx] && table[ny][nx] == '-' && table[y][x] == '-') {
            dfs(ny, nx);
        }
    }

    // La solucion es igual a los piezas de table que se cambian en dfs.
    solution[y][x] = table[y][x];
}

bool solve(){
    // Filas (F), Columnas (C)
    cin>>F>>C;
    if(!cin) return false;

    // Creamos matrizes de F filas en cada una con C columnas.
    table.assign(F, vector<char>(C, {}));
    solution.assign(F, vector<char>(C, 'X'));
    visit.assign(F, vector<bool>(C, false));

    cin.ignore();
    for(int y = 0; y < F; y++) {
        string line;
        getline(cin, line);
        for(int x = 0; x < C; x++) {
            table[y][x] = line[x];
        }
    }

    int K; cin>>K;
    bool game_over = false;
    // Empezamos el turno desde x y en cada k casos.
    for(int i= 0; i < K; i++){
        int y, x; cin>>y>>x;
        x--; y--;
        if (table[y][x] == '*'){
            cout<<"GAME OVER\n";
            game_over = true;
        }else dfs(y,x);
    }
    
    if(game_over) return true;
    // Si hay gameover se pasa a la siguiente entrada.

    for (int y = 0; y < F; ++y) {
        // Se recorre el tablero de soluciones.
        for (int x = 0; x < C; ++x) {
            cout<<solution[y][x];
        }
        cout<<"\n";
    }

    return true;
}

int main(){
    while(solve());
    return 0;
}