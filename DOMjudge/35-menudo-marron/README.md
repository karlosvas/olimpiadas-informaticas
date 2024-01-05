# Menudo marrón

Tras el confinamiento, el mundo se ha vuelto loco: griterío en
las calles y en los balcones, lanzamiento de contenedores, manifestaciones clandestinas... No hay quien ande por la ciudad.
Con todo, el papel higiénico se ha vuelto un bien preciado, debido a sus múltiples usos. Los manifestantes los usan para lanzarlos sin herir a nadie, los artistas para hacer mejunje, y hay
gente que lo utiliza hasta como filtro de café.
Y con la demanda el precio ha empezado a subir. Además, la ciudad está patas arriba, por lo
que puede haber numerosas calles cortadas. A lo que se une las restricciones de movilidad.
Por todo ello, has decidido crear una aplicación que dado el conjunto de calles transitables
de la ciudad y el de supermercados, así como el precio del rollo de papel higiénico en cada
supermercado, calcule cuánto le costaría a un comprador el rollo más barato, dependiendo
de dónde se encuentre.
Entrada
La entrada consistirá en una serie de casos de prueba. Cada caso comienza con una línea
con el número N de puntos en la ciudad (1 ≤ N ≤ 25.000) y el número C de calles transitables
(0 ≤ C ≤ 200.000). A continuación, aparecerán C líneas, cada una con dos números (entre 1
y N), describiendo los dos puntos de la ciudad que une una calle de doble sentido.
Tras la descripción de las calles aparecerá el número S de supermercados en la ciudad (0
≤ S ≤ N), seguido de S líneas con dos números: el punto donde está localizado un supermercado en la ciudad y el precio del rollo de papel higiénico en dicho supermercado. Se
garantiza que no habrá dos supermercados en la misma localización.
Finalmente, aparecerá una línea con el número K de consultas (1 ≤ K ≤ N), seguido de esas
consultas, consistente cada una en el punto de la ciudad donde se encuentra el comprador.
Salida
Para cada caso de prueba se escribirá una línea por cada una de las K consultas con el
precio del rollo más barato que se puede comprar desde la localización del comprador.
En caso de que no se pueda alcanzar ningún supermercado desde esa localización, se
escribirá MENUDO MARRON en su lugar.
La salida de cada caso de prueba termina con una línea con tres guiones (---).

## Entrada de ejemplo
7 5  
1 2  
2 3  
3 1  
4 5  
7 6  
3  
2 100  
3 200  
4 50  
4  
1 3 5 6  

## Salida de ejemplo
100  
100  
50  
MENUDO MARRON  
---  