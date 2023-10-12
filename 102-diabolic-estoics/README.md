# Cuadrados diabólicos y esotéricos

Tiempo máximo: 4,000 s  Memoria máxima: 10240 KiB
Se considera un cuadrado mágico diabolico a la disposición de una serie de números enteros en un cuadrado de forma tal que la suma de los números por columna, fila y diagonales principales sea la misma. A esta suma se le llama constante mágica (CM). Para nuestro desarrollo consideraremos el cuadrado como una matriz con igual número de filas que de columnas.

Si suponemos n la cantidad de filas o columnas del cuadrado, un cuadrado mágico diabólico es esotérico cuando, además de ser diabólico, cumple las siguientes condiciones:

Tiene las mismas cifras que el número de casillas. Es decir, siguen la serie de números naturales de 1 a n².
La suma de sus esquinas debe ser la constante mágica 2 (CM2) que cumple que:
CM2=4⋅CMn
Si n es impar:
La suma de las cifras de las cuatro casillas de la mitad de los laterales suman la constante mágica 2.
Si se multiplica el valor de la casilla central por 4, se obtiene la constante mágica 2.
22	47	16	41	10	35	4
5	23	48	17	42	11	29
30	6	24	49	18	36	12
13	31	7	25	43	19	37
38	14	32	1	26	44	20
21	39	8	33	2	27	45
46	15	40	9	34	3	28	
n = 7
Constante mágica = 175
Constante mágica 2 = 100
Esquinas	22 + 4 + 46 + 28 = 100 (CM2)
Centro	4 · 25 = 100 (CM2)
Centro lados	41 + 13 + 37 + 9 = 100 (CM2)
Si n es par:
La suma de las dos casillas centrales de cada uno de los cuatro laterales suman el doble de la constante mágica 2 (2 · CM2)
La suma de las cuatro casillas centrales da como resultado la constante mágica 2.
1	63	62	4	5	59	58	8
56	10	11	53	52	14	15	49
48	18	19	45	44	22	23	41
25	39	38	28	29	35	34	32
33	31	30	36	37	27	26	40
24	42	43	21	20	46	47	17
16	50	51	13	12	54	55	9
57	7	6	60	61	3	2	64	
n = 8
Constante mágica = 260
Constante mágica 2 = 130
Esquinas	1 + 8 + 57 + 64 = 130 (CM2)
Centro	28 + 29 + 36 + 37 = 130 (CM2)
Centro lados	4 + 5 + 25+ 33 + 60 + 61 + 32 + 40
= 260 (2 · CM2)
Entrada
El programa leerá de la entrada estándar un cuadrado mágico tras otro. Cada cuadrado mágico consistirá en dos líneas. La primera línea contendrá el valor de n (2 ≤ n ≤ 1024). La segunda línea será los valores de las n² celdas, uno detrás de otro.

La entrada termina cuando al leer el tamaño del siguiente cuadrado mágico se recibe un 0.

Salida
Para un cuadrado esotérico, el programa escribirá ESOTERICO, para un cuadrado mágico diabólico (no esotérico) escribirá DIABOLICO. Para cualquier otro cuadrado, mostrará NO.

Entrada de ejemplo
3
4 9 2 3 5 7 8 1 6
2
1 2 3 4
4
16 3 2 13 5 10 11 8 9 6 7 12 4 15 14 1
3
28 21 26 23 25 27 24 29 22
3
2 8 1 6 3 5 7 4 9 
0
Salida de ejemplo
ESOTERICO
NO
ESOTERICO
DIABOLICO
NO

## Apuntes
CM es la constante mágica original (la suma que todas las filas, columnas y diagonales deben alcanzar).
n es el tamaño del cuadrado (el número de filas o columnas).

CM2 => La constante mágica 2 (CM2) se basa en la suma de las filas (o columnas) multiplicada por 4, y luego dividida por el número de casillas en el cuadrado.

CM2 => Deve ser igual que la suma de las esquians del cuadrado.

CM2 => if(n%2==0) El centro del cuadrado multiplicado por 4 deve ser icual a CM2. && La suma de la mitad de cada uno de los lados debe ser igual a CM2.

CM2 => if(n%2!=0) La suma de las cifras del con correlacion, vease en el medio de toda la tabla veritical y horizaontalmente. && La suma de las dos casillas centrales debe ser igual a CM2 * 2.

### Diabolico y Estoico
Determinar si el cuadrado mágico es "diabólico" =>  
    std::bool diabolico = false;
    if(La suma de los números en todas las filas, columnas y diagonales principales debe ser igual a la constante mágica (CM)){
        diabolico = true;
        std::cout<<"DIABOLICO";
    
Verificar si el cuadrado mágico es "esotérico" =>  
        if(diabólico && allOkWhit(CM2)){
            std::cout<<"ESOTERICO";
        }
    }

No encontro ni diabolico ni essotérico;
    else {
        std::cout<<"NO";
    }