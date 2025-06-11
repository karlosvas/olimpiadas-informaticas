# Peaje a la sombra

El precio de la electricidad está por las nubes y el ayuntamiento ha decidido implantar un novedoso sistema
para reducir el gasto en alumbrado público: el peaje a
la sombra. Inspirándose en la iluminación accionada por
monedas de ciertos monumentos, cada tramo de calle
entre dos intersecciones se ha dotado en sus extremos
de sendas máquinas de cobro. Si el viandante quiere
que las farolas de un tramo se iluminen durante el tiempo necesario para recorrerlo, tiene
que insertar un euro en la máquina correspondiente y activar un interruptor. Y así sucesivamente en cada intersección.
Esto es una faena para Alex y Lucas que tienen que desplazarse a la panadería donde
trabajan antes del alba, recorriendo las ahora oscuras calles de la ciudad. Ambos desean
llegar a su trabajo con luz suficiente, sin pegarse ningún trastazo ni dejarse medio sueldo
en el intento. Cada uno vive en un punto distinto de la ciudad, pero han pensado que si se
reunen en un punto intermedio y hacen el resto del recorrido juntos se ahorrarán en ese
camino común la mitad de las monedas que se gastarían si fueran por separado.
Por ejemplo, si Alex debe recorrer 5 tramos de calle sin Lucas y Lucas 4 tramos sin Alex,
pero luego juntos recorren otros 3 tramos, el viaje les costaría en total 5 + 4 + 3 = 12 euros.
El desafío que tienen por delante es encontrar la ruta más eficiente para minimizar el gasto
total, o equivalentemente, el número de tramos recorridos.

## Entrada

La entrada está compuesta por diversos casos de prueba, ocupando cada uno de ellos
varias líneas.
En la primera línea aparecen 5 números: el número N (entre 3 y 20.000) de intersecciones
en la ciudad; el número C (entre 2 y 200.000) de tramos de calle (entre intersecciones); y
las intersecciones donde se situan la casa de Alex, la casa de Lucas y su trabajo (números
distintos entre 1 y N).
A continuación, aparece una línea por cada tramo de calle con dos enteros (números entre 1
y N) que indican los números de las intersecciones que une el tramo, en ambos sentidos.
Nunca hay un tramo de calle que conecte una intersección consigo misma, ni dos tramos
que conecten el mismo par de intersecciones.
La ciudad siempre está bien conectada, es decir, se puede ir desde cualquier punto a cualquier otro utilizando sus calles.

## Salida

Para cada caso de prueba se escribirá una línea con la cantidad mínima que deben gastar
Alex y Lucas (de forma conjunta) para llegar a su trabajo desde sus casas.

### Entrada de ejemplo

6 7 1 3 6  
1 2  
2 3  
2 5  
3 4  
5 4  
5 6  
4 6  
4 3 4 1 3  
1 2  
2 3  
3 4

### Salida de ejemplo

4  
3
