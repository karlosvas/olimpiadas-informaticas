# Probelmas matemáticos 2

## Numeros primos

Un número primo es un número natural mayor que 1 que tiene únicamente dos divisores distintos: él mismo y el 1.
El número 2 es el único primo que es par, los números primos son fundamentales en la teoría de números, y la principal razón es que los números naturales mayores que 1 pueden ser factorizados de manera única como producto de números primos. Este es el llamado teorema fundamental de la aritmética.

Un número compuesto es un número natural que tiene, además de al 1 y a él mismo, algún otro divisor.

Por convenio, el número 1 no se considera ni primo ni compuesto.

La primalidad de ser un número primo se denomina primalidad ("test de primalidad" es el nombre de los algoritmos que determinan si un número es primo).

La lista de números primos es infinita, como demostró Euclides en el siglo III a.C, por reducción al absurdo.
q = (p1 \* p2 \*... \* pn) + 1

## Aproximación de Gauss

pi(n) = ~n/ln(n)

## Teoremoa fundamental de la aritmética

Todo número natural tiene una representación única como producto de factores primos salvo el orden
2 = 2
4 = 2\*2
15 = 3\*5
Si 1 fuera cosiderado primo, la definición tendría que revisarse.
¿Cuál es la descomposición en factores primos de 1?
1 =
0! = 1

## Descomposición de números en factores primos

```cpp
void factorizar(long long n) {
  assert(n >= 2);

  cout << n << " =";

  while ((n % 2) == 0) {
    cout << " 2";
    n /= 2;
  }

  long long p = 3;

  while (p * p <= n) {
    while ((n % p) == 0) {
      cout << " " << p;
      n /= p;
    }
    p += 2;
  }

  if (n != 1) {
    cout << " " << n;
  }
  cout << endl;
}
```

Versión recursiva

```cpp
void factorizarRec(int n) {
  long long p = 2;

  while (p * p <= n && (n % p) != 0) {
    ++p;
  }

  if (n % p == 0) {
    cout << " " << p;
    factorizarRec(n / p);
  } else {
    if (n != 1)
      cout << " " << n;
  }
}
```

En pogramación competitiva a veces se usan otras funciones relaciondas en factores primos.

- numFactoresPrimos(n) ¿Cuantos primos tiene n?
- numFactoresPrimosDistintos(n) ¿Cuantos primos distintos tiene n?
- sumaFactoresPrimos(n) ¿Cual es la suma de los factores primos de n?
- numeroDeDivisores(n) ¿Cuantos divisores tiene n?

n = A^a \* B^b \* C^c ... \* F^f
numeroDeDivisores(n) = (a+1) \* (b+1) \* (c+1) ... \* (f+1)

## Precálculo de primos

Es raro que nos pidan escribir la fatorizacion de números. Normalmente es necesario saber si un número es o no primo y uisar esa informacuión para otras cosas.
Dado un rango \[i,j\] ¿Cuantos números primos hay?

```cpp
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

#define MAX_N 10000;
vector<int> primos;

void precalcularPrimos() {
   primos.push_back(2);
   primos.push_back(3);

  for (int n = 5; n < MAX_N; n += 2) {
   // Si n es primo primos.push_back(n);
   // ¿n es primo?
   auto pIt = primos.begin();

   while(*Pit * *pIt <= n && (n % *pIt) != 0)
      ++pIt;

   if(n % *pIt == 0)
      primos.push_back(n);
  }
}

bool esPrimo (long long n){
   if(n <= MAX_N)
      return binary_search(primos.begin(), primos.end(), n);
   else{
      pIt = primos.begin();
      long long p = *pIt;
      while(p * p <= n && (n % p) != 0){
         ++pIt;
         p = *pIt;
      }
      return (n % p) != 0;
   }
}

int main(){
   precalcularPrimos();
   cout << "Entre 2 y "<<MAX_N<<" hay "<<primos.size()<<" primos\n";
   return 0;
}
```

## Precálculo de primos: criba de Eratóstenes

La criba de Eratósteles es un algoritmo para hallar todos los primos menores que un numero natural dado.
Comenzar con un array de boleanos con una entrada por cada número que indica si es primo o no.
Al principio todos están en true.
Se recorren del menor al mayor y se tiran los múltiplos de los números marcados como primos que nos encontremos.

```cpp
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

#define MAX_PRIME 10000010

bitset<MAX_PRIME + 1> bs;
vector<long long> primes;

void sieve() {
  bs.set(); // Todos son primos mientras no se demuestre lo contrario.
  bs[0] = bs[1] = 0; // El 0 y el 1 no son primos

  for (long long i = 2; i <= MAX_PRIME; i++) {
    if (bs[i]) {
      for (long long j = i * i; j <= MAX_PRIME; j += i) {
        bs[j] = 0;
      }
      primes.push_back(i);
    }
  }
}
```
