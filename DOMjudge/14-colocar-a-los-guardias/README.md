## Colocar a los guardias

En el pequeño país de Abudajh hay algunas calles y cruces. Cada calle conecta dos cruces. El rey de Abudajh quiere colocar guardias en algunos cruces de forma que todas las calles queden custodiadas por ellos.
Un guardia en un cruce puede vigilar todas las calles adyacentes a él.
Pero los guardias no son muy gentiles. Si una calle está custodiada por dos guardias, estos terminarán peleándose. Y el rey no quiere que los guardias se peleen.

Dada la información sobre las calles y cruces de Abudajh, ayuda al rey a encontrar la cantidad mínima de guardias necesarios para proteger todas las calles de su país sin
que haya peligro de peleas.

### Entrada
La entrada está compuesta por diversos casos de prueba. Para cada caso, primero aparece el
número N de cruces en el país (entre 1 y 50.000) y a continuación el número de calles C entre
cruces (entre 0 y 200.000). En las siguientes C líneas se describen estas calles, dando los cruces
que conectan (numerados entre 1 y N)

### Salida
Para cada caso de prueba se escribirá el número mínimo de guardias necesarios para vigilar todas
las calles. Si no fuera posible colocar los guardias para que todas las calles quedaran custodiadas
y no hubiera peleas, entonces se escribirá IMPOSIBLE.

# Entrada de ejemplo
8  
6  
1 3  
2 3  
3 4  
4 5  
6 4  
7 8  
//
3  
1  
1 2
//  
3  
3  
1 2  
2 3  
3 1  

## Salida de ejemplo
4  
1  
IMPOSIBLE