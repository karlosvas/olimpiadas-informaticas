# Estructuras de datos no lienales.
Las estructuras de datos no lineales son organizaciones de datos en las que los elementos no se almacenan de manera secuencial como en las estructuras de datos lineales, como las matrices o las listas enlazadas. En lugar de eso, los datos se organizan de manera más compleja y jerárquica. Algunas de las estructuras de datos no lineales más comunes.
## Colas de prioridad
Los elementos salen segun su prioridad primero el mas prioritartio.

#include <queue>
priority_queue<int> pq; // cola de máximos

metodos
push(e) => Añadir un elemento.  
top() => Reevisar el elemento superior.  
pop() => Eliminar el ultimo elemento.  
empty() => Devuelbe un valoir booleano si esta vacio la cola o no.  
size() => Devuelbe el tamaño de da cola.  

# Unidad curiosa de monitorizacion.
## Conjuntos.
Son colecciones de elementos únicos y ordenados.

#include <set>  
int<set> cjto;  

insert(e) => Inserta un nuevo elemento.  
erase(e) => Elimina el elemento indicado, no da error si intentas eliminar un elemento que no esta definido.  
count(e) => Devuelbe 0 en el caso de  que ele elemento no este.  
empty() => Para saver si el conjunto esta vacio.  
size() => Devuelbe cuantos elementos tiene el conjunto.  

## Dicionarios.

#include <map>  
map<string, int> dicc;  

insert(key_value) => Recive un par clave valor.  
erase(key) => Borrar la clave junto con su valor.  
count(key) => Se utiliza para saver si la clave etsa definida da 1, si no lo esta deviuelbe.  
at[key], [key] => Se utiliza para saver si el valor esta relacionado cun una llaves, si no esta da error. dicionario["ejemplo"] devuelbe value. Los [] modifica el diccioanrio, el at solo lo consulta.  
empty(), size() => Devuelbe un valor boleanoi si esta vacia, Devuelbe el tramaño de el diccionario.