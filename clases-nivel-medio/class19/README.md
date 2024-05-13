## Problemas matemáticos 3

## Combinatoria

El arte de contar sin enumerar directamente todos los casos posibles que pueden darse en un suceso determinado.  
Da métodos de conteo para calcular de cuántas formas puede ocurrir un determinado suceso.

¿De cuántas formas podemos elegir 2 colores entre 3?

1. rojo y azul
2. rojo y verde
3. azul y verde

## Principios fundamentales del conteo

### Principio de adición

Si un succeso A puede ocurrir de n formas, y un suceso B puede ocurrir de m formas, entonces el suceso A o B puede ocurrir de n + m formas.
Si tengo un conjunto A y un conjunto B que son disjuntos |A U B| = |A| + |B|

Quiero comprarme un móvil. Puede ser un iPhone o un Samsung. Hay 8 modelos de iPhone y 5 de Samsung. ¿De cuántas formas me puedo comprar el móvil?

> [!NOTE]
> Principio de adición (regla de suma)
> Si tenemos m objetos distribuidos en n cajas y m > n\*r, entonces al menos una caja contiene r+1 objetos.

> [!NOTE]
> Princio del producto (regla de multiplicación)
> Si un suceso A puede ocurrir de n formas y un suceso B puede ocurrir de m formas, entonces el suceso A y B puede ocurrir de n\*m formas.

Si hay p formas de hacer una cosa y q formas de hacer otra, entonces hay p\*q formas de hacer ambas.

Si se desea realizar una actividad que consta de r pasos, donde el primer paso puede ser llevado a cabo de N1, formas, el segundo paso de N2 formas y el r-esimo de Ni fromas, la actividad pùede ser llevada a cabo de N(1)\*N(2)\*N(3)\*...\*Nr

Si en el equipaje de tu último viaje te has llevado 3 pantalones y 8 camisetas, ¿Cuántos días puedes estar sin repetir combinación?
3\*8 = 24
Cuántos números pares de 4 dígitos se pueden crear con los digitos del 0 al 6 si se pueden repetir?
6\*7\*7\*4 = 1176

## Recurrencias

Muchos problemas de conteo se resuelven con recurrencias
Recuerdan a programación dinámica
Los números combinatorios se calculan con una recurrencia que se usa como ejemplo de programación dinámica

¿Cuántos números binarios de n bits hay que no tengan dos ceros seguidos?
S(n): cantidad de números binarios de n bits no tienen dos ceros seguidos
S(0) = 0("")
S(1) = 1("0", "1")

En las recurrencias hay que confiar en los casos base y crear la recurrencia a partir de ellos
A veces es posible crear una fórmula cerrada a partir de la recurrencia
Existen técnicas específicas para buscarlas
A veces se puede llegar a más de una fórmula

## Permutaciones

Nos vamos a comer un postre de 3 piezas de fruta, ¿De cuantas formas podemos hacerlo?
Permutaciones: posibles ordenaciones de un conjunto de elementos distintos
Recurrencia:
P(n): número de ordenaciones de n elementos
P(0) = 1
P(n) = n\*P(n-1)
P(N) = n!

### Netx_permutation

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
   vector<string> palabras = {"pera", "manzana", "platano"};
   sort(palabras.begin(), palabras.end());

   do{
      for(auto &p: palabras)
         cout << p << " ";
      cout << "\n";
   } while(next_permutation(palabras.begin(), palabras.end()));
}
```

## Variaciones

Nos vamos a comer de postre 2 piezas de fruta de las 4 que tenemos ¿De cuántas fromas podemos hacerlo?
Variaciones: posibles ordenaciones de r elementos distintos seleccionados de un conjunto de tamaño n
Recurrencia:
V(n, r) = Número de variaciones de n elementos tomados de r en r (n >= r)
V(n, 0) = 1
V(n, r) = n\*V(n-1, r-1) = n\*(n-1)\*(n-2)...(n-r+1)
V(n, r) = n!/r!

> [!CAUTION]
> Cuidado con los desbordamientos. La aritmética modular no se lleva bien con las divisiones

## Variaciones con repetición

¿Cuántos números distintos hasta cuatro dígitos se pueden fromar en base 8?
8\*8\*8\*8 = 8^4

Variaciones con repetición: posibles ordenaciones de r elementos distintos seleccionados de un conjunto de tamaño n permitiendo repeticiones
Recurrencia:
VR(n, r) = n^r
Queremos llevar en la mochila 2 piezas de fruta de las 4 que tenemos. ¿De cuántas formas podemos hacerlo (Ya no importa el orden)?

## Combinaciones

Combinaciones: Posibles subconjuntos de r elementos distintos seleccionados de un conjunto de tamaño n
Recorrencia: visita el día de programación dinámica
C(n, r) = Combinacionmes de n elementos tomados de r en r (N >= r)
C(n, 0) = C(n.n) = 1
C(n, r) = C(n-1, r-1) + C(n-1, r)

Al elejir las r piezas de fruta podemos añadir la pera o no añadirla.
Principio de adición
C(n, r) = Subconjuntos de r elementos que tienen la pera + subconjutnos de r elementos que no la tienen
Los subconjuntos que tienen la pera luego tienen r-1 elementos escojidos de las n-1 piezas de fruta restantes (sin la pera):
C(n-1, r-1)
Los subconjutnos que no tienen la pera deben tener r elementos escojidos de las n-1 piezas de fruta restantes(sin la pera, que no se escoje):
C(n-1, r)

Si el orden no importa entre las dos primeras (r) ni entre las dos últimas (n-r) entonces se puede usar la fórmula de las combinaciones

> [!IMPORTANT]
> (n r) = n!/(r!(n-r)!)

## Combinaciones con repetición

Cominaciones con repetición: Distintas formas de selecionar elementos del conjutno permitido que la seleción pueda repetirse
Sleción de un munticonjunto cuyos elementos pertenecen al conjunto dado
El orden en el que están los elementos no importa

## Permutaciones con repetición

Permutaciones con repetición: posibles ordenaciones de un conjutno de n elementos distintos donde hay n1 que son iguales, otros n2 que son iguales... otros nr que son iguales (n >= n1 + n2 + ... + nr)

Permutaciones con repetición: n!/(n1!\*n2!\*...\*nr!)

## Desregalos

Tres amigos quieren jugar al amigo invisible donde cada uno hace un regalo a otro. ¿De cuántas formas pueden regalar sin que nadie se regale a sí mismo?
Desarreglos: permutaciones en las que ninguno de sus elementos esté en si posición original
Recurrencia:
D(0) = 1
D(1) = 0
D(n) = Número de desarreglos de n elementos

El número de desarreglos es menor que el numero de permutaciones. Pero ¿cuánto menor?

Principio de inclusión-exclusión: Diagrama de Venn
D(n) = n!\*-n(n -1)! + n(n-2)! - 1(n-n)!
D(3) = 3! \* (1 - 1/1! + 1/2! - 1/3!)

## Subfactoriales

EL subfactorial escrito como !n (aunque noe sta aceptado universalmente) es el número de formas de permutar n valores dsitintos sin que ninguno esté en su posición original
!n = n!\*(1 - 1/1! + 1/2! - 1/3! + ... + (-1)^n/n!)

la expresión del sumatorio es 1/e cuando n tiende a infinito
e = 2.71828182845904523536028747135266249775724709369995

lim(!n)=n!/e

Hay una recurrencia que evita la división aunque no es una forma cerrada
D(n) = !n = (n-1)\*D(n-1) + D(n-2)
Lo importante es un desarreglo de n elementos que cada uno se puede mapear a n-1 (todos tienen exactamente uno prohibido)

La primera persona puede regalar a (n-1) personas distintas. Asumamos que lo hace a la persona número i.
Hay dos opciones:
La persona i regala a la primera (ciclo): Quedan n-2 personas para regalarse entre ellas
La persona i no regala a la primera: Quedan n-1 personas para regalarse entre ellas, cada una tiene a otra prohibida (a i nno le dejamos en este subconjutno regalar a la primera)

## Números de Catalan

Cn+1 = sumatorio desde i=0 hasta n de C(i)C(n-i)
C0 = 1

## Probabilidad

La probabilidad es una medida de incertidumbre de que un suceso ocurra
Valor entre 0 (imposible) y 1 (seguro)
Se mide empíricamente repitiendo un suceso y contando los resultados favorables
Si todas las opciones son igual de probables matematicamente se calcula como:
P(x) = Número de casos favorables/Número de casos posibles
