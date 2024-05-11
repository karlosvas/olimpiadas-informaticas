# Cine romántico a raudales

A Dinamique Cinema no le gustan las películas de terror tanto como a su
hermana Deborah; ella prefiere el apasionado cine romántico. Y está de
suerte, porque aprovechando el comienzo de la primavera, la filmoteca
ha organizado un maratón de cine romántico: durante 24 horas se proyectarán películas (todas diferentes) en las diversas salas disponibles.
Dinamique ya se ha hecho con el folleto con la programación completa
donde aparecen todas las películas que se van a proyectar durante el maratón; junto con
el título, nombre del director, sala de proyección y otros datos de interés, se indica la hora
de comienzo y duración de la película.

¿Puedes ayudar a Dinamique a planificar su maratón de cine, teniendo en cuenta que su
único objetivo es estar viendo películas durante el mayor tiempo posible?

## Entrada

La entrada consta de una serie de casos de prueba. Cada uno comienza con una línea con
el número N de películas que se proyectarán (0 < N ≤ 1.000). A continuación aparecerán N
líneas con la información de cada película: la hora de comienzo dentro del día de proyección, en el formato HH:MM, y la duración en minutos de la película. Ninguna película acabará
más allá de las 12 de la noche.
La entrada terminará con un caso sin películas, que no debe procesarse.

## Salida

Para cada caso de prueba se escribirá una línea con el máximo tiempo, medido en minutos,
que Dinamique Cinema puede estar viendo películas, suponiendo que siempre necesita 10
minutos libres (para comprar palomitas, cambiar de sala, etc.) entre película y película.

### Entrada de ejemplo

3
11:00 90
12:30 90
12:45 60
3
11:00 90
12:45 60
11:00 180
2
12:00 80
20:00 80
0

### Salida de ejemplo

150  
180  
160
