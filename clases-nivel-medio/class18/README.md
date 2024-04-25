# Programación dinámica

## Caminos mínimos entre todo par de vértices algoritmo de Floyd-Warshall

Dado un grafo dirijido y valorado, calcular el camino de coste mínimo entre todo par de vértices.
Podríamos utiliza el algoritmo de Dikstra V veces para calcular los caminos mínimos desde cada vértice a todos los demas.
El algoritmo de Floyd-Warshall nos permite hacer esto en O(V^3) donde V es el número de vértices, con pesos posiblemente negativos.

G[i][j] {
0 si i=j
coste si hay arista de i a j
+infinito si no hay arista de i a j
}

C^k(i,j) = coste mínimo de ir de i a j pasando por los vértices [1,2,...,k]
C^k(i,j) = min(C^k-1(i,j), C^k-1(i,k)+C^k-1(k,j))
C^0 = G

Conjunto de vértices intermedios
k= {1,2,...,V}

C^k(k,j) = min(C^k-1(k,j), C^k-1(k,k)+C^k-1(k,j)) = C^k-1(k,j)

## Reconstrucción de caminos mínimos

A^k(i,j) = vértice anterior a j en el camino mínimo de la i a la j pudiendo utilizar como vértices intermedios aquellos entre 1 y k

A^0 {
-1 si i=j || G[i][j] =+ infinito
i si i!=j && G[i][j] < +infinito
}

A^k(i,j) = {
A^k-1(i,j) si C^k-1(i,j) <= C^k-1(i,k)+C^k-1(k,j)
A^k-1(k,j) si C^k-1(i,j) > C^k-1(i,k)+C^k-1(k,j)
}

```cpp
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;
int V;
vector<vector<int>> G;
vector<vector<int>> C, A;

void FloydWarshall() {
  C = G;
  A.assign(V, vector<int>(V, -1));

   for (int i = 0; i < V; i++)
      for (int j = 0; j < V; j++)
         if (i != j && G[i][j] < INF)
         A[i][j] = i;

   for (int k = 0; k < V; k++) {
      for (int i = 0; i < V; i++) {
         for (int j = 0; j < V; j++) {
         int temp = C[i][k] + C[k][j];
            if (temp < C[i][j]) {
               C[i][j] = temp;
               A[i][j] = A[k][j];
           }
         }
         if(C[i][i] < 0) {
            cout << "Hay un ciclo negativo" << endl;
            return;
         }
      }
   }


}

void caminos(int i, int j) {
  if (A[i][j] == INF)
    return;
  if (i == j)
    cout << i;
  else {
    caminos(i, A[i][j]);
    cout << " -> " << j;
  }
}

int main() {
  V = 6;
  G = vector<vector<int>>(V, vector<int>(V, INF));

  G[1][2] = 3;
  G[1][3] = 8;
  G[1][5] = -4;
  G[2][4] = 1;
  G[2][5] = 7;
  G[3][2] = 4;
  G[4][3] = -5;
  G[4][1] = 2;
  G[5][4] = 6;

  FloydWarshall();

  if (C[3][5] != INF) {
    cout << C[3][5] << '\n';
    caminos(3, 5);
    cout << '\n';
  }

  return 0;
}
```

## Detectar ciclos negativos

C^k(i,i) = min(C^k-1(i,i), C^k-1(i,k)+C^k-1(k,i))
C^k(i,i) < 0

## Multiplicación de matrices

EL producto de una matriz Apxq y una matriz Bqxr es una matriz Cpxr cuyos elementos son:

C[i][j] = sumatorio desde k=1 hasta q de a[i][k]\*b[k][j]
Se necesitan qp\*r multiplicaciones entre números para calcular C.

Queremos multiplicar una secuencia de matrices M1,M2,...,Mn donde Mi tiene dimensione di-1\*di.

El producto de matrices no es conmutativo, pero sí es asociativo.

¿Cuál es la mejor forma de colocar paréntesis en al secuencia de multiplicaciones de forma que el número de multiplicaciones entre números sea mínimo?

### Ejemplo de multiplicación encadenada de matrices

A13 \* B5x89 \* C89x3\* D3x4

((A\*B)\*C)\*D = 10582
(A\*(B\*C))\*D = 2856

(M^1...M^k) \* (M^k+1...M^n)
El principio de optimalidad de Bellman nos dice que si una solución óptima a un problema contiene soluciones óptimas a subproblemas, entonces la solución global es óptima.

matrices(i,j) = número mínimo de multiplicaciones básicas para realizar el producto matricial Mi...Mj

Todas las posibilidades de decidir cuál es el último producto a realizar:

Mi \* (Mi+1...Mj)
(Mi...Mi+1) \* (Mk+2...Mj)
(Mi...Mj-1) \* Mj

## Definción recursiva

Casos recursivos i < j:
matrices(i,j) = min_i<=k<=j-1{matrices(i,k)+matrices(k+1,j)+di-1\*dk\*dj} para todo k entre i y j-1

Caso base i=j:
matrices(i,i) = 0
Si solo tenemos una matriz no necesitamos hacer el producto entre escalares para convertirlo en una matriz, ya lo es.

Llamada inicial:
matrices(1,n)

## Reconstrucción de la solución

```cpp
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int multiplica_matrices(vector<int> const& D, vector<vector<int>> & P){
   int n = D.size()-1;
   vector<vector<int>> matrices(n+1, vector<int>(n+1, 0));
   P = vector<vector<int>>(n+1, vector<int>(n+1, 0));
   for (int d = 1; d <= n-1; ++d){ // Recorre diagonales
      for (int i = 1; i <= n-d; ++i){ // Recorre elementos de diagonal
         int j = i+d;
         matrices[i][j] = INF;
         for (int k = i; k <= j-1; ++k){
            int temp = matrices[i][k] + matrices[k+1][j] + D[i-1]*D[k]*D[j];
            if (temp < matrices[i][j]){
               matrices[i][j] = temp;
               P[i][j] = k;
            }
         }
      }
   }
}

void escribir_parentesis(int i, int j, vector<vector<int>> const& P){
   if (i == j)
      cout << "M" << i;
   else{
      int k = P[i][j];
      if(k > i){
         cout << "(";
         escribir_parentesis(i, k, P);
         cout << ")";
      } else {
         cout << "M" << i << "*";
         if (k+1 < j){
            cout << "(";
            escribir_parentesis(k+1, j, P);
            cout << ")";
         } else{
            cout << "M" << j;
         }
      }
   }
}
```
