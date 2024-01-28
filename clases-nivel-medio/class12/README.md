# Tres retos

Adivina un número entre 1 y 100.
Adivina un numero positivo.
El problema del duende Gumersido.

## Búsqueda en un vector ordeando

- Búsqueda binaria:
  Dado un vcecotr ordenado V[0..N-1] y un valor B, saber si está o no y donde.

```cpp
vector<int> v = {3, 7, 9, 10, 14, 15, 22, 29, 48, 50, 63, 68, 75, 80};
int B = 10, l = 0, r = v.size() - 1;

while (l + 1 < r) {
int m = (l + r) / 2;
    if (v[m] == B) {
        cout << "Encontrado en la posicion " << m << "\n";
        break;
    } else if (v[m] > B) r = m - 1;
    else l = m + 1;
}

if (r < l) cout << "No encontrado\n";
else cout <<" Entre"<< l << ' y ' << r << '\n';
```

- Búsqueda de un número culesquiera repetido positivo:
  V[0..l] < B, Para todos los elementos desde 0 a l incluido, son menores que B.
  V[r..n) >= B, para todos los elementos desde r hasta n, son mayores o iguales que B.

Primera posición del elemento buscado.

```cpp
vector<int> v = {3, 7, 9, 10, 14, 15, 22, 29, 48, 50, 63, 68, 75, 80};
int N = 14, B = 10, l = -1, r = N;

while (l + 1 < r) {
    int m = (l + r) / 2;
    if (v[m] < B) l = m;
    else r = m;
}

if (r < N && v[r] == B) cout<<"Primera posición está en la posicion "<<r<<"\n";
else cout<<"No encontrado\n";
```

Última posición del elemento buscado.

```cpp
if (r < N && v[r] == B) {
    cout << "Esta en la posicion " << r << "\n"; // Posición 3

    l = -1, r = N; // v[0..l] <= B && v[r..N-1] > B
    while (l + 1 < r) {
      int m = (l + r) / 2;
      if (v[m] <= B) {
        l = m;
      } else // v[m] > B
        r = m;
    }
    cout << "Está por ultima vez en la posicion" << l << "\n"; // Posición 5
  } else
    cout << "No encontrado\n";
```

### lower_bound

```cpp
template <class ForwardIterator, class T>
ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, const T& val);
```

Retorna un iterador al primer elemento en el rango [first,last) que no es menor que el val.
Se utiliza principalmente en contenedores ordenados como vectores o listas.

_ForwardIterator_: Especifica el tipo del iterador que se utiliza para recorrer el rango.
_first_: Es el iterador que apunta al inicio del rango.
_last_: Es el iterador que apunta al final del rango.
_val_: Es el valor que se está buscando.

La función busca el primer elemento en el rango que no es menor que val utilizando la comparación <. Retorna un iterador apuntando a esa posición.

## Hallar la raiz cuadrada de x > 0

Nos conformamos con la parte entera por defecto.
Solo sabemos operaciones básicas (sumar, multiplicar, dividir o comparar) números enteros.

> **Nota** int64_t es un tipo de dato entero de 64 bits, es lo mismo que long long.

```cpp
  int64_t N = 100000, l = 1, r = N, i = 0;
  while (l + 1 < r) {
    int64_t m = (l + r) / 2;
    ++i;
    if (m * m <= N)
      l = m;
    else
      r = m;
  }
  cout << " La raiz cuadrada de " << N << " es " << l << "en " << i << " pasos" << "\n";
```
