#include <iostream>
#include <string>
#include <vector>
using namespace std;

int findCM1(const vector<vector<int>>& tabla, int n) {
    int CM1 = 0;
    int fila = 0;
    int columna = 0;
    int diagonal = 0;

    for (int i = 0; i< n ; i++){
        fila += tabla[0][i];
        columna += tabla[i][0];
        diagonal += tabla[i][i];
    }

    if(fila == columna && columna == diagonal){
        CM1 = fila;
    }

    return CM1;
}

// int findCM2(const std::vector<std::vector<int>>& tabla, int n) {
// }

int main(){
   
    int n;
    cin>>n;
    int numeros;
    cin>>numeros;
    vector<vector<int>> tabla(n, vector<int>(n));
    vector<vector<int>> numeros;

    for (int y= 0; y < n; y++){
        for (int x= 0; x < n; x++){
        tabla[y][x] = numeros;
        }
    }

    int CM1 = findCM1(tabla, n);
    std::cout<<"\n CM1 es= "<<CM1<<"\n";


    // int CM2 = findCM2(tabla, n);
    // std::cout<<"\n M2 es= "<<CM2<<"\n";

    return 0;
}

