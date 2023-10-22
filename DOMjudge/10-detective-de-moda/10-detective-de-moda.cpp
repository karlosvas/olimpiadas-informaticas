#include <iostream>
#include <queue>
#include <map>
using namespace std;

bool resolve(){
    int n, e, x, y;

    cin>>n>>e;
    if(1 < n < 10) return false;
    if(1 < e < 10) return false;
    if((1 < x && 1 < y) || (x > 10 && y > 10)) return false;

    map<int> mapShirt;

    return true;
}

int main(){
    while(resolve());
    
    return 0;
}

// Todos los numeros x e y son distintos, son las mcamisetas que ya hay al principio cuando abren la tienda, i y j son las camisetas que llegan.

// Devemos realizarlo con una cola doble.