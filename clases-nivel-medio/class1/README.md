# Las estructuras de datos
Son los elementos en los que podremos guardar ssdatos para despues recuperarlos.
Lo que diiferencia entre unas y otras consiste en que elementos podemos acceder.

# Estruturas de dartos lineales
Una detras de otra (Principales)

/*
### Pilas
Se utiliza para la recursión y callbacks.

### LIFO
Estructura de datos LIFO Last In, Fisrt Out
Estructura aen la que podemos guardar elementos, y solo podremos acceder al último introducido.

#include <stack>
std::stack<int> pila;

push() => Añadir un elemento encima de todos los elementos.
top() => Consulta cual es elemento que esta en el ultimo elemento introducido.
pop() => Elimina el ultimo elemento introducido.
empty() => Verifica si esta actualmente vacia devuelbe truo o false.
size() => Devuelbe cuantos elementos dispone la fila.

### FIFO
Estructura de datos FIFO, first in first out.

El perimero en llegar es el primero en salir.
#include <queue>
queue<int> cola;

push(e) => Añadir en elemento en el final de la cola.
front() => Devuelbe el valor del primer elemento de la cola.
pop() => Elimina el primer elemento de la cola.
empty() => Verifica si la cola esta vacia, y devuelbe true o false.
size() =>  Devuelbe el tamaño de los 
elementos de la cola.

### Colas dobles
Estructura de datos colas dobles, en ella los dos extremos son accesibles.

#include<deque>
deque<int> dcola;

push_front(e), push_back(e) => Añade el elemento del principio o del final.
front(), back => Devuelbe el elemento del principio del final.
pop_front(), pop_back() => Elimina el elemento por el principio o del final. 
empty() => Verifica si se encuentra vacia, y devuelbe true o false.
size() =>  Devuelbe el tamaño de los elementos en las colas.

### Listas
Estrucura de datos desde la uq epodemos acceder a los elementos en cualquier posición, utilizando iteradores.

#include <list>
list<int> lista;

las mismas de deque
begin(), end() => Conseguir un iterador al primero. "it = lista.begin()" Es un objeto y it apuntya al perimer elemento mientras que "it= lista.end()" apunta al ultimo elemento.
at(3) => Devuelbe el elemento de la posicion tres.
rbegin, rend() => Se uilizan para recorrer la lista al revés.
insert(it,e), erase(it) => Añade pero no quita los elementos sin depender del tamaño de la lista, si tenemos un irterador que esta apuntado a el, insert no mopdifica ekl iterador una vez a sido insertado. En este ejemplo: (e=elemento && it==iterador)
*, ++, --, ==, != => El asterisco "*" devuelbe el valor al que esta apuntado el iterador, "++" es para pasar al siguiente elemento, y "--" lo contrario.

### Vector
Estructura de datos que consiste en elementos consecutivos a los que podemos acceder en cualquier posición, utilizando índices. Le podemos asignar el tamaño al crearlo y podremos aaceder a ellos desde indices [].

#include <vector>
vector<int> v(tam);

puish_back(e), pop_back() =>
[], at() =>
size() =>
insert(it,e), erase(it) =>
begin(), end() =>
*/ 