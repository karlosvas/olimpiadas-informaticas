# ¡Las noticias vuelan!
En una red social hay una serie de usuarios que se comunican entre ellos dentro de una serie de grupos de amigos.
Queremos analizar el proceso de distribución de noticias entre estos usuarios.
Inicialmente, algún usuario recibe una noticia de una fuente
externa.
Entonces envía la noticia a sus amigos en la red (dos usuarios son amigos si hay al menos un grupo al que pertenezcan ambos). Los amigos envían a su vez esa noticia a sus amigos y el proceso continua.
así hasta que no exista una pareja de amigos tal que uno de ellos conozca la noticia y el
otro no.
Para cada usuario de la red, queremos saber cuántos usuarios terminarían conociendo la
noticia si inicialmente solamente ese usuario la conocía.

## Entrada
La entrada está formada por una serie de casos, cada uno de los cuales ocupa varías líneas. En la primera línea de cada caso aparecen dos números: el número N de usuarios
de la red y el número M de grupos (1 ≤ N, M ≤ 100.000). A continuación aparecen M líneas describiendo esos grupos. Para cada grupo, la descripción comienza con el número
de usuarios del grupo (entre 0 y N) seguido de los identificadores de esos usuarios (todos
distintos), números entre 1 y N. La suma de los tamaños de todos los grupos no es mayor
que 500.000.

## Salida
Para cada caso se escribirá una línea con N números. El número i-ésimo indicará el número
de usuarios que terminarían conociendo la noticia si el usuario i fuera quien comenzara a
distribuirla.

## Entrada de ejemplo
7 5  
3 2 5 4  
0  
2 1 2  
1 1  
2 6 7  
4 2  
1 1  
1 3  

## Salida de ejemplo
4 4 1 4 4 2 2  
1 1 1 1  