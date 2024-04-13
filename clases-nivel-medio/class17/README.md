# Programación dinámica 2

## Problema cambio de monedas

Conjunto finito M = { m^1, m^2, ..., m^k } de monedas donde cada m^i es un número natural.
Existe una cantidad limitada de comedas de cada valor.
Se quiere pagar una cantidad C > 0 utilizando el menor número posible de monedas.

Tenemos que considerar diferentes alternativas hasta encontrar la mejor.
Las soluciones son multiconjuntos de monedas.
Podemos fijar el orden en el que vamos considerarndo los tipos de monedas sin que eso afecte al resultado final.

- ¿Que hacemos con las monedas de tipo n?
  C = {m^n + C-m^n}

monedas(i,j) = número mínimo de monedas necesarias para pagar j con las monedas de tipo 1, 2, ..., i.

> [!NOTE] Principio de optimalidad de Bellamn: para conseguir una solución óptima basta con considerar subsoluciones óptimas.

- Casos recursivos
  monedas(i,j) = {
  monedas(i-1,j) si m^i > j
  min(monedas(i-1,j), monedas(i,j-m^i)+1) si m^i <= j
  }
  donde 1 <= i <= n y 1 <= j <= C

- Casos básios
  monedas(i,0) = 0 si 0<=i<=n
  monedas(0,j) = ∞ si 1<=j<=C

- Llamada inicial: monedas(n,C)

## Implementacion

```cpp
const int INF = 1e9;

bool solve(){
   int N, C;
   cin >> N >> C;

   if(N == 0 && C == 0)
      return false;

   vector<int> M(N);
   for(int & x : M)
      cin >> x;

   vector<vector<int>> monedas(N+1, vector<int>(C+1, INF));
   monedas[0][0] = 0;

   for(int i = 1; i <= N; i++){
      for(int j = 0; j <= C; j++){
         monedas[i][0] = 0;
         if(M[i-1] > j)
            monedas[i][j] = monedas[i-1][j];
         else
            monedas[i][j] = min(monedas[i-1][j], monedas[i][j-M[i-1]]+1);
      }
   }

   cout << (monedas[N][C] == INF ? -1 : monedas[N][C]) << endl;

   vector<int> sol;
   if(monedas[N][C] != INF){
      int i = N, j = C;
      while(j > 0){
         if(M[i-1] <= j && monedas[i][j] != monedas[i-1][j]) {
            sol.push_back(M[i-1]);
            cout << M[i-1] << " ";
            j -= M[i-1];
         } else{
            i--;
         }
      }
      cout << "\n";
   }
}
```

## Problema de la mochila (entera)

Cuando Alí Babá entra en la cueva de los 40 ladrones, encuentra una gran cantidad de objetos muy valiosos, de los que conocía muy bien el peso y valor.

Solo podía llevar consigo una mochila con capacidad limitada, por lo que tenía que decidir qué objetos llevarse y cuáles dejar, para soportar un peso máximo y conocido.

Suponiendo que los objetos no se pueden partir, ¿Que objetos debería elegir Alí-Babá para maximixar el valor de su mochila?

- ¿Que hacemos con el objeto n?
  Si el objeto n no cabe en la mochila, no lo metemos.
  Si cabe, lo metemos si el valor total es mayor que el valor sin meterlo.

Hay n objetos cada un peso p^i > 0 y un valor v^i > 0.
La mochila soporta un peso total máximo M > 0.

Y el problema consiste en maximizar:
sumatorio de i=1 a n de v^i _ x^i
con la restrición
sumatorio de i=1 a n de p^i _ x^i <= M

donde x^i € {0,1} indica si hemos cogido 1 o no 0, el objeto i.

En las soluciones no importa el orden en elq ue los objetos son introducidos en la mochila.
Las soluciones dependen de los objetos que tengamos disponibles para introducior en la mochila y del peso que soporte esta.
Definimos la siguiente función:
mochila(i,j) = valor máximo que se puede obtener con los objetos 1, 2, ..., i y una mochila de capacidad j.

- Casos recursivos
  mochila(i,j) = {
  mochila(i-1,j) si p^i > j
  max(mochila(i-1,j), mochila(i-1,j-p^i) + v^1) si p^i > j
  }
  con 1 <= i <= n y 1 <= j <= M

- Casos básicos
  mochila(0,j) = 0 si 0 <= j <= M
  mochila(i,0) = 0 si 1 <= i <= n

- Llamada inicial
  mochila(n,M)

```cpp
int N;
vector<int> P, V;
vector<vector<int>> memo;

int mochila(int i, int j){
   if(memo[i][j] != -1)
      return memo[i][j];
   if(i == 0 || j == 0)
      memo[i][j] = 0;
   else if(P[i-1] > j)
      memo[i][j] = mochila(i-1,j);
   else
      memo[i][j] = max(mochila(i-1,j), mochila(i-1,j-P[i-1]) + V[i-1]);

   return memo[i][j];
}

bool calObject(){
   // Calculo de los objetos
   int i = N, j = M;
   vector<int> sol(S, false);
   while (i > 0 && j > 0){
      if(memo[i][j] != memo[i-1][j]){
         sol[i-1] = true;
         cout<<"("<<P[i-1]<<", "<<V[i-1]<<") ";
         j -= P[i-1];
      }
      i--;
   }
   cout << "\n";
   return true;
}

bool solve(){
   int M;
   cin >> N >> M;

   if(N == 0 && M == 0)
      return false;

   P.assign(N, 0);
   V.assign(N, 0),;

   for(int &x: P)
      cin >> x;
   for(int &x: V)
      cin >> x;

   memo.assign(N+1, vector<int>(M+1, -1));
   cout << mochila(N,M) << "\n";

   return true;
}
```
