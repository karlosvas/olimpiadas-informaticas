# Estructuras de datos
Implementan una serie de operaciones.
Como usuarios nos interesa qué conjunto de operaciones tienn su complejidad.
### Ejemplos
priority_queue, set, map, ufds  
Set insert(elm), erase(elm), count(elm), size(), empty().

## Implementación de conjutno de enteros
Vector con elementos quizá repetidos  
Vector con elemenetos sin repetir  
Vector ordenado  

| Operacion | No ordenado repetidos | No ordenados sin repetir | Ordenado    |
|-----------|-----------------------|--------------------------|-------------|
| Insert    | Constante             | Lineal                   | Lineal      |
| Erase     | Lineal                | Lineal                   | Lineal      |
| Count     | Lineal                | Lineal                   | Logarítmico |
| Size      | Cuadrático            | Constante                | Constante   |
| Empty     | Constante             | Constante                | Constante   |


## Segment Trees motivación
Dado un vector de enteros v[0...n), queremos saber cuánto vale la suma de un intervalo, v[a...b](Esto se le conoce como Range Sum Query, RSQ).

Si solo se va a haer una consulta, se recorre el intervalo y se contesta.
Si va a haber muchas consultas ¿Hay alguna alternativa mejor?
<table style="margin: auto; margin-bottom: 20px;">
  <tr style="background-color: #FFA500;">
    <th>i</th>
    <th>0</th>
    <th>1</th>
    <th>2</th>
    <th>3</th>
    <th>4</th>
    <th>5</th>
    <th>6</th>
    <th>7</th>
    <th>8</th>
  </tr>
  <tr style="background-color: #FFA07A;">
    <td>v[i]</td>
    <td>1</td>
    <td>6</td>
    <td>0</td>
    <td>7</td>
    <td>3</td>
    <td>5</td>
    <td>6</td>
    <td>0</td>
    <td>3</td>
  </tr>
  <tr style="background-color: #FFA07A;">
    <td>acu[i]</td>
    <td>1</td>
    <td>7</td>
    <td>7</td>
    <td>14</td>
    <td>17</td>
    <td>22</td>
    <td>28</td>
    <td>28</td>
    <td>31</td>
  </tr>
</table>


### ¿Y si?...
... en lugar de la suma de intervalo es la multiplicación?  
...en lugar de la suma del intervalo es el elemento mas pequeño (Range minimum query RMQ)?  
...además de consultar la suma queremos poder cambiar un valor?

## Segment Trees utilidad
(Intervalos de segmentos de un árbol binario)
init(v[]), update(pos, val), query(ini, fin)

Estructura de datos que implementa de forma eficiente operaciones de consulta y modificación sobre un vector("percibido").  

**Dos alternativas:**  
Actualización puntual, consulta de rango point-update / range query (RSQ anterior)  
Actualziación de rango, consulta puntual (o de rango): rnage update / point-query

### Idea general
- Tener precalculadas las repuestas para algunos intervalos y convinarlas en el momento de las consultas  
La combinación depende de la operación concreta impuesta por el problema 

- Los intervalos están organizados en forma de árbol binario  
El vector completo se divide en dos intervalos  
Cada uno de ellos a su vez se divide en dos  
Al final quedan intervalos de longitud 1

- Cada nodo del árbol binario representa un intervalo del vector percibido y almacena resultado de la consulta

## Implementaciones recursivas
update(nodo, pos, val) actualiza el nodo y los hijos para que v[pos] = val.  
update(nodo, a, b, val) actualiza el nodo y los hijos para que v[a...b] = val.  
query(nodo,a,b) consulta la información de v[a...b] si el nodo no cubre todo el intervalo, solo de la parte cubierta por éste.  
query(nodo, pos) consulta la información de v[pos], el mismo resultado que query(nodo, pos, pos), no la haremos
init(nodo, v) actualiza el nodo y lso hijos que  guarden la información de v.

Habrá poca diferencia de las implementaciones ante cambios de operaciones  
Intentaremos identificar  aisalr la parte específica de la operación.

```cpp
int query(nodo, a, b){
    assert(parte de [a...b] pertenece al nodo);
    if(nodo completo dentro de [a..b])
        return val;
    if([a...b] solo toca al hijo iquierdo);
        return query(hijoIzquiero, a, b);
    if([a...b] solo toca al hijo derecho);
        return query(hijoDerecho, a, b);
    return query(hijoIzquerdo,a ,b) + query(hijoDerecho,a , b);
}
```

## Implementación sin nodos
Guardaremos el árbol binario en un vector, la información de cada nodo en una posición del vector
La informacion asiciada a la raiz, en la posición 1
Si un nodo está en la posición i del vector, el hijo izquierdo estará en 2*i y en el derecho en 2*i+1.

> [!CAUTION]  
> !No mezclar conceptos¡
Vector percibido vs vector con el árbol
Para un vector percibido de tamaño n, ¿Que tamaño tiene tener el vector para guardar el arbol? No mas de 4*n (relacionado con la > altura máxima del árbol)

Las implementaciones recursivas reciben
El índice del vector donde se guarda la información asociada a ese nodo
El intervalo que representan

## Point-Update
Atributos
Actualización puntual
Construcción
Consulta del rango

```cpp
#include <vector>
#include <cassert>
using namespace std;

inline int IZDA(int n) {return 2*n;};
inline int DCHA(int n) {return 2*n+1;};

struct segment_tree {
  vector<int> st;
  int numElms;

  segment_tree(int n) : numElems(n), st(4*n, 0) {

  }
  segment_tree(const vector<int> &v) : numElems(v.size()), st(4*v.size(), 0) {
    init(1, 0, numElems-1, v);
  }

  int query(int a, int b){
    query(1,0,numElms-1,a,b);
  }

  int update(int pos, int val){
    update(1,0, numElms -1, pos. val);
  }

  void update(int node, int l, int r, int pos, int val){
    assert((l <= pos) && (pos <= r));
    if(l == r) {
      st[node] = val;
      return;
    }
    int m = (l+r) / 2;
    // Actualización implica al hijo izquierdo
    // Si no actualización implica al hijo derecho
    if(pos <= m) update(IZDA(node), l, m, pos, val);
    else update(DCHA(node), m+1, r, pos, val);
    // Actualizamos la información del nodo
    st[node] = st[IZDA(node)] + st[DCHA(node)];
  }

  int query(in tnode, int l, int r, int a, int b){
    // Sanity-chack: [a..b] interseca [l..r]
    assert((l <= b) && (a <= r));
    if((a <= l) && (r <= b)) return st[node];

    // Caso recursivo
    int m = (l+r) / 2;
    int izd, dcha;

    // Parte de la consulta esta en el hijo izquierdo
    if(a<=m)
      izda = query(IZDA(node), l, m, a, b);
    // Parte de la consulta esta en el hijo derecho
    if(m<b)
      dcha =query(DCHA(node, m+1, r,a,b));

    if(b<=m) return izda;
    if(m<a) return dcha;
    return izda + dcha;
  }

  void init(const vector<int> &v, int node, int l, int r) {
    if(l==r) {
      st[node] = v[l];
      return; 
    }
    int m = (l+r) / 2;
    init(v, IZDA(node), l, m);
    init(v, DCHA(node), m+1, r);
    st[node] = st[IZDA(node)] + st[DCHA(node)];
  }
};
```
## ¿Y si...
...quisieramos devolber el mínimo del rango en lugar de la suma?
...quisieramos tener dos funciones de consulta, una ¡que devuelba la suma y otro mínimo?
...quisiéramos devolber la resta entre el máximo y el mínimo?
...quisiéramos devolber la posición del mínimo en el vector percivido(en lugar del valor)?
.. quisieramos modificación de rango en lugar de puntual?
Ej: Poner todos lols elementos de v[a...b] a 5
Ej: Incrementa todos los elementos de v[a...b] en 12 unidades

<table style="color: #fff;background-color: #121212; margin:auto;">
  <tr">
    <th></th>
    <th>Preprocesado</th>
    <th>Consulta</th>
  </tr>
  <tr">
    <td>Vector Original</td>
    <td style="text-align: center;">O(1)</td>
    <td style="text-align: center;">O(n)</td>
  </tr>
  <tr">
    <td>Sumas acumuladas</td>
    <td style="text-align: center;">O(n)</td>
    <td style="text-align: center;">O(1)</td>
  </tr>
</table>

## Range-Update
Una operación de actualización de rango "descendiente" por el árbol hasta llegar a todas las hojas afectadas
Cuando la actualización afecta a todo el nodo se retrasa la actualización en los hijos
Se actualiza la información de ese nodo/intervalo
La información del nodo está actualizada, pero la de los descendientes no
Las actualizaciónes pendientes no se ejecutarán hasta que no haya operaciones de consulta sobre esos nodos

Se conoce como actualización perezosa(lazy update)
La actualización perezosa es posible si se puede calcular el valor del intervalo a partir del valor enterior y de la operación
Los nodos pueden
Esatr actualizados
Tener operaciones de actualización pendientes
Las actualizaciones perezasas pueden acumularse
sumav[3...10],2 y suma v[3...10],3 = suma(v[3...10],5)
Por cada nodo la implementación guarda
El valor asociado a ese rango
La operación pendiente de ejecutar sobre él (y sobre sus descendientes)

```cpp
inline int IZDA(int n) { return 2 * n; };
inline int DCHA(int n) { return 2 * n + 1; };

struct segment_tree {

	vector<int> st;
	vector<int> pending;
	int numElems;

	segment_tree(int n) : numElems(n), st(4 * n, 0), pending(4*n, 0) {}
	segment_tree(const vector<int>& v) : numElems(v.size()), st(4 * v.size(), 0), pending(4 * v.size(), 0){
		init(v, 1, 0, numElems-1);
  }
  
	void init(const vector<int>& v, int node, int l, int r) {
		if (l == r) {
			st[node] = v[l];
			return;
		}

		int m = (l + r) / 2;
		init(v, IZDA(node), l, m);
		init(v, DCHA(node), m + 1, r);
		st[node] = st[IZDA(node)] + st[DCHA(node)];
	}

	int query(int a, int b) return query(1, 0, numElems - 1, a, b);

	int query(int node, int l, int r, int a, int b) {
		// Sanity-check: parte del rango a actualizar toca el nodo
		assert((l <= b) && (a <= r));
		// Resolvemos cualquier operación pendiente
		solvePendingUpdates(node, l, r);
		// Resto queda igual
			// El nodo está dentro del rango consultado
		if ((a <= l) && (r <= b))
			return st[node];
		// Consultamos los hijos
		int m = (l + r) / 2;
		int izda, dcha;
    // Rango toca hijo izquierdo
    // O rango toca hijo derecho
		if (a <= m)
			izda = query(IZDA(node), l, m, a, b);
		if (m < b)
			dcha = query(DCHA(node), m + 1, r, a, b);
		// Combinamos
    // Solo hijo izquierdo
    // O solo hijo derecho
		if (b <= m)
			return izda;
		if (m < a)
			return dcha;
		return izda + dcha;
	}
	void updateRange(int a, int b, int val)
		updateRange(1, 0, numElems - 1, a, b, val);
	// Al salir, el nodo no tendrá operaciones pendientes
	void updateRange(int node, int l, int r, int a, int b, int val) {
		solvePendingUpdates(node, l, r);
		if ((b < l) || (r < a))
			// La actualización no nos afecta
			return;
		if ((a <= l) && (r <= b)) {
			// Actualización afecta por completo
			addPendingUpdate(node, l, r, val);
			// Eliminamos operaciones pendientes
			solvePendingUpdates(node, l, r);
			return;
		}
		// Caso recursivo. Actualizamos ambos hijos
		// (garantizamos que no les quedan operaciones por resolver)
		int m = (l + r) / 2;
		updateRange(IZDA(node), l, m, a, b, val);
		updateRange(DCHA(node), m+1, r, a, b, val);
		// Actualizamos nuestra información
		st[node] = st[IZDA(node)] + st[DCHA(node)]; // OP
	}


	void addPendingUpdate(int node, int l, int r, int val)
		pending[node] += val;

	void solvePendingUpdates(int node, int l, int r) {
		if (pending[node] == 0)
			return;

		// Actualizamos el nodo
		st[node] += (r - l + 1) * pending[node]; // OP
		// Trasladamos a los hijos (si tenemos)
		if (l != r) {
			int m = (l + r) / 2;
			addPendingUpdate(IZDA(node), l, m, pending[node]);
			addPendingUpdate(DCHA(node), m + 1, r, pending[node]);
		}
    
		// Borramos operaciones pendientes
		pending[node] = 0; // OP
	}
};
```