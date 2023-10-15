# Coge el sobre y corre
Pedro Franqueza fue nombrado tesorero hace unos años.
Desde entonces sus distintos chanchullos le han hecho
una persona muy influyente. En la cajonera que tiene debajo de su mesa guarda una hilera de sobres, cada uno
con una cantidad de dinero conseguido de manera dudosa.
Hoy tiene una cena de negocios en el bar Cenás a la que
irá el presidente y otros nueve compañeros. Para mantenerlos contentos, justo antes de salir del despacho mete
la mano en el cajón y coge diez sobres consecutivos para repartirlos allí mismo. No ha tenido tiempo de mirar cuánto dinero hay en cada sobre, así que habrá que repartirlos sobre
la marcha. Eso sí, el presidente se quedará con el sobre que más dinero tenga.
En el coche yendo hacia el bar va pensando en cómo podría averiguar rápidamente cuánto
dinero le correspondería al presidente en base al grupo de 10 sobres consecutivos seleccionados. Y como tiene aires de grandeza, se plantea si sería capaz de hacerlo si guardara
hasta 500.000 sobres en su cajonera.
Entrada
La entrada está compuesta por distintos casos de prueba que representan días distintos
en la vida de Pedro Franqueza.
Cada caso aparece en dos líneas consecutivas. La primera de ellas contiene dos enteros,
el primero con el número de sobres que guarda en el cajón (1 ≤ n ≤ 500.000) y el segundo
el número de sobres que tiene que coger para ir a la cena, o lo que es lo mismo, el número
de comensales que se llevarán un sobre, incluído el presidente (1 ≤ k ≤ n). La segunda línea
contiene n números mayores o iguales a 1 con el dinero que hay en cada uno de los sobres.
La entrada termina con un caso sin sobres, que no debe procesarse.
Salida
Para cada caso de prueba se escribirá una única línea con n − k + 1 números que indicarán
la cantidad de dinero que se llevará esa noche el presidente dependiendo de qué sobres
coja Pedro. En particular, el primer número será el dinero para el presidente si coge los
k primeros sobres; el segundo si se salta el primer sobre y coge los k siguientes, etc. En
general, el número i-ésimo indica la cantidad que se llevará el presidente si coge los k
sobres desde el sobre i hasta el sobre i + k − 1.

### Entrada de ejemplo
6 1  
3 8 5 12 15 9  
6 3  
3 8 5 12 15 9  
8 3  
3 8 5 12 15 9 3 1  
0 0  

### Salida de ejemplo
3 8 5 12 15 9  
8 12 15 15  
8 12 15 15 15 9  