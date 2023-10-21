# Repaso de ejercicios
Podemos utilizar si queremos asegurarnos si el getline lo a leido correctaemnte.
```cpp
if (!cin) return false;
```  

Si eleminamos un elemento en una lista el iterador apuntara a un elemento en la lista que ya no existe poor lo que deveremos asignarle el valor de lo que devuelbe erase(it), que es el nuevo elemento al que deve apuntar, el elemnto siguiente al que hemos borrado, de la siguiente forma.
```cpp
it = list.erase(it);
```  

La diferencia entre estas dos instrucciones, es que "++it" se modifica y puede ser utilizado como expresión en un condicional, deviuelbe el valor despues del incremento de it, mientras que "it++" solo sirva para modificarlo apuntado al siguiente, devuelbe lo que tenia el iterador antes del incremento.
```cpp
++it;
it++;
```  

Para mostrar una lista podemos utilizar un constructor string indicádnole el iterador del principio y el iterador del final.
```cpp
cout<<string(list.begin(), resultado.end())<<"\n";
```  

Es posible crear objetos pair y utilizarlos con contenedores STL como priority_queue, se puede utilizar push objetos pair en una cola de prioridad o en otros contenedores. tambien podremos dar la vuelta a un priority_queue para que lo ordene por el menor ">" con greater.
```cpp
using Ejemplo = pair<int, int>
priority_queue<Caja, vector<Caja>, greater<Caja>> cajas;
cajas.push({0, i});
```