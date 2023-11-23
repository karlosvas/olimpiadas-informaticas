#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
vector<vector<char>> garden;
int X,Y; 
int incX[] ={-1,0,1,0};
int incY[] ={0,1,0,-1};

int bfs(pair<int, int> O, pair<int, int> D){

    for(int y= 0; y < Y; ++y){
        for(int x = 0; x < X; ++x){
            // preproceso del Jardin para indicar las alarmas, si es un numero K, se le da X a las K filas(x) y columnas(y) adyacentes.
            if(isdigit(garden[y][x])){
                int K = garden[y][x] - '0';
                for (int pos = 0; pos < 4; ++pos) {
                    // Cada pos es cada dirección en los dos ejes.
                    for(int k = 1; k < K + 1; ++k){
                        // La nueva x (nx) es lo que valga x por la dirección pos a la que apunta. 
                        int nx = x + incX[pos] * k;
                        int ny = y + incY[pos] * k;
                        if (0 <= nx && nx < X && 0 <= ny && ny < Y) {
                            // Si hay muro termina K para pasar a la siguiente posición.
                            // Si en el jardin hay . la camara puede vigilarlo.
                            if(garden[ny][nx] == '#') break;
                            else if(garden[ny][nx] == '.') garden[ny][nx] = 'X';
                        }
                    }
                }
            }
        }
    }
    
    // Creamos un vector de longitud Y*X, iniciado a -1.
    // Y creamos una cola de pares, en el que first = (y) e second = (x).
    vector<int> dist(Y*X, -1);
    queue<pair<int, int>> q; q.push(O);
    // La distancia es igual a el valor de la fila = y * logitud de la matriz en x = X + el valor de (dist=y*X+x).
    dist[O.first * X + O.second] = 0;

    while(!q.empty()){
        // Añadimos a la cola a el par v, que es un par de (y,x) siempre que no este vacía.
        auto v = q.front(); q.pop();
        int y= v.first;
        int x= v.second;
        for (int pos = 0; pos < 4; ++pos) {
            // Nos movemos en los dos ejes, verificando si esta dentro de los límites.
            int newCol = y + incY[pos];
            int newRow = x + incX[pos];
            if (newRow >= 0 && newRow < X && newCol >= 0 && newCol < Y) {
                // La distancia actuual es w = y * X + v.
                int w = newCol * X + newRow;
                if (dist[w] == -1) {
                    // Si no ha sido visitada se suma 1, pregunta si es el detino o si es un camino valido, ni muro ni que este vigilado, y añade el nuevo par de (y,x) a la cola.
                    dist[w] = dist[y * X + x] + 1;
                    if (garden[newCol][newRow] == garden[D.first][D.second]) return dist[w];
                    else if(garden[newCol][newRow] != '.') continue;
                    q.push({newCol, newRow});
                }
            }
        }
        
    }
    // No se a encontrado un camino.
    return -1;
}

int main(){
    int J; cin>>J;
    while(J > 0){
        cin>>X>>Y;
        // Vector de vectores de Y*X vacio.
        garden.assign(Y,vector<char>(X, {}));
        
        // Origen(O), Destino(D).
        pair<int, int> O, D;
        string line;
        cin.ignore();
        
        for(int y= 0; y < Y; ++y){
            getline(cin, line);
            for(int x = 0; x < X; ++x){
                // Si encuentra E la guardamos en el origen, y si encuentra P la guardamos en el destino. Y actualizamos el valor en la matriz del jardín.
                if (line[x] == 'E'){
                    O.first = y; O.second = x;
                }else if (line[x] == 'P'){
                    D.first = y; D.second = x;
                }
                garden[y][x] = line[x];
            }
        }
        
        // Llamamos a bfs y retornará un valor si es -1 quiere decir que es imposible cruzar el jardín.
        int sol = bfs(O, D);
        if(sol == -1) cout<<"NO\n";
        else cout<<sol<<"\n";

        // Restamos J para pasar a el siguiente bucle while.
        J--;
    };

    return 0;
}