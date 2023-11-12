#include <iostream>
#include <vector>
#include <string>

using namespace std;
using Map = vector<vector<char>>;
Map picture;
vector<vector<bool>> visit;

int incX[] ={-1,0,1,0};
int incY[] ={0,1,0,-1};
int W,H; 

void dfs(int x, int y){
    visit[x][y] = true;
    // Recorremos todos  los '.' desde la llamada inicial de x y para marcarlos como visitado.
    for(int d = 0; d < 4; ++d){
        // Verificamos quese encuentrae en el rango de la matriz y le damos movimiento vertical y horizontal.
        int nx = x + incX[d], ny= y + incY[d];
        if (0 <= nx && nx < W && 0 <= ny && ny < H && picture[nx][ny] == '.' && !visit[nx][ny]) {
            dfs(nx, ny);
        }
    }
}

bool solve(){
    // Width o anchura (W)
    // Heigth o altura (H)
    cin>>W>>H;
    if(!cin) return false;

    // Matriz y visit de W*H
    picture.assign(W, vector<char>(H, '.'));
    visit.assign(W, vector<bool>(H, false)); 

    string line;
    cin.ignore();

    for(int y= 0; y< H; y++){
        // Guardando la imagen
        getline(cin, line);
        for(int x= 0; x < line.size(); x++){
            picture[x][y] = line[x];
        }
    }

    int blancas = 0;
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            // Buscando conexiones anexas de blancas.
           if(!visit[x][y] && picture[x][y] == '.'){
                dfs(x, y);
                blancas++;
           }
        }
    }

    // Restamos la conexión anexa que forma el fondo.
    cout<<blancas-1<<"\n";

    return true;
}

int main(){
    while(solve());
    return 0;
}