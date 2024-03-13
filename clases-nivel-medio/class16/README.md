# Números combinatorios

n/r es el número de subconjuntos de cardinal r qure tiene un conjunto de n elementos.
r puede variar entre 0 y n.
si r es mayor que n, n/r = 0.

## Triángulo de Pascal

Cada elemento es igual a la suma de los dos elementos que tiene encima.

         1
        1 1
       1 2 1
      1 3 3 1
     1 4 6 4 1
    1 5 10 10 5 1

Para contar subconjuntos distintos no importa el orden devido a que a+b = b+a.
Si elejimos uno de los elementos los subconjuntos se dividen en dos tipos los que contienen el elemento y los que no lo contienen.

### Implementación recursiva

La implementación recursiva es muy ineficiente debido a que se calculan los mismos valores muchas veces, poara solucionar esto se puede usar programación dinámica.

```cpp
int comb(int n, int r) {
    if (r == 0 || r == n) return 1;
    return comb(n-1, r-1) + comb(n-1, r);
}
```

## Programación dinámica

Utilización de una tabla (array multidimensional) para almacenar los resultados a subproblemas ya resueltos.
La tambla tiene dimensiones como argumentos tiene la recurrencia.
El tamaño de cada dimensión coincide con los valñores que puede tomar el argumento correspondiente.
Cada subproblema se asocia a una posición en la tabla.

### Descendente top-down

Mantiene el diseño recursivo.
La función utiliza una tabla donde se alamcenan las soluciones a los subproblemas ya resueltos.
Antes de resolver de manera recursiva un subproblema, se mira en la tabla por si se hubiera resuelto ya.
Tras resolver un subproblema recursivo, su solución se almacena en la tabla.
Necesidad de saber si un subproblema ya ha sido resuelto o no.

```cpp
#include <iostram>
#include <vector>
#include <cstring>
using namespace std;

#define MAX = 10000;

int comb(int n, int r) {
    if (r == 0 || r == n) return 1;
    if (memo[n][r] != -1) return memo[n][r];
    return memo[n][r] = comb(n-1, r-1) + comb(n-1, r);
}

int main() {
   int n, r;
   cin >> n >> r;

   long memo[MAX+1][MAX+1];
   memset(memo, -1, sizeof(memo)); // Libreria cstring
   cout << comb(n, r) << endl;

   return 0;
}
```

### Ascendente bottom-up

Cambiar el orden en el que se resuelven los subproblemas.
Comenzar por los subproblemas más pequeños que se puedan necesitar, para ir combinándolos hasta llegar a resolver el problema original.
Los subproblemas se van resolviendo recorriendolos de menos a mayor tamaño.
Todos los posibles subproblemas de tamaño menor tienen que ser resueltos antes de resolver uno de tamaño mayor.

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
   int n, r;
   cin >> n >> r;

   memset(memo, 0, sizeof(memo));
   memo[0][0] = 1;

   for (int i = 1; i <= n; i++) {
      memo[i][0] = 1;
      for (int j = 1; j <= r; j++)
         memo[i][j] = memo[i-1][j-1] + memo[i-1][j];
   }
   cout<< memo[n][r] << "\n";
   return 0;
}
```

## Palindromos

Caso recursivo(i<\j)

patindromo(i,j)=
{
patindromo(i+1,j-1) si s[i]==s[j]
max(patindromo(i+1,j),patindromo(i,j-1)) si s[i]!=s[j]
}

## Tiro al patíndromo, top down

```cpp
// Valor del palindromo mas largo
cin >> patitos;
int N = patitos.lenght();

for (int i = 0; i < N; i++)
   for (int j = 0; j < N; j++)
      P[i][j] = -1;

int patin(int i, int j){
   int & res = P[i][j];
   if (res != -1) {
      if ( i >j ) res = 0;
      else if(i == j) res = 1;
      else if(patitos[i] == patitos[j]) res = patin(i+1, j-1) + 2;
      else res = max(patin(i+1, j),patin(i, j-1));
   }
   return res;
}

// Añade al final del sol el palíndromo más largo en patitos[i...j]
void reconstruir(int i, int j, string & sol){
   if (i > j) return;
   if (i == j) sol += patitos[i];
   else if (patitos[i] == patitos[j]){
      sol += patitos[i];
      reconstruir(i+1, j-1, sol);
      sol += patitos[j];
   }
   else if (P[i+1][j] > P[i][j-1]) reconstruir(i+1, j, sol);
   else reconstruir(i, j-1, sol);
}

// Version iterativa, botton up
cin >> patitos;
int N = patitos.lenght();

P[N-1][N-1] = 1;
for (int i = N-2; i >= 0; i--){
   P[i][i] = 1; P[i+1][i] = 0;
   for (int j = i+1; j < N; j++){
      if (patitos[i] == patitos[j]) P[i][j] = P[i+1][j-1] + 2;
      else P[i][j] = max(P[i+1][j], P[i][j-1]);
   }
}
```
