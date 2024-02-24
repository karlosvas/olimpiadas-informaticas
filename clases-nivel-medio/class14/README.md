# Problemas matemáticos

En los conscursos de programación suelen aparecer problemas que necesitan matemáticas para resolverse.
Las matemáticos son muy amplias, aritmética, sucesiones, teoria de números, combinatorio, geometría, etc.

Vamos a ver algunas cosas, pero muchas se quedarán en el tintero, muchos problemas que necesitan matemáticas son acertijos.

## Los números dentro de un ordenador

Una cantidad se puede representar de mcuhas furomas.
/, VII, > (Sseta o zeta griega), siete, ||||| ||
Lo normal es usar notación en base 10, tenemos 10 símbolos para indicar dígitos 0,1,2,3,4,5,6,7,8,9.
Cuando se nos acaban damos la vuelta y ponemos un digito nuevo a la izquierda.
Se pueden utilizar bases diferentes con un nuúmero diferente de dígitos internamente los ordeandores usan base2.
En base 2 solo hay dos dígitos 0 y 1.

Para poner el 11 en base 10, 11/10 = 1 y 1 de resto, 10 +1
Para poner el 11 en base 2, 11/2 = 5 y 1 de resto, 5/2 = 2 y 1 de resto, 2/2 = 1 y 0 de resto, 1/2 = 0 y 1 de resto, 1011.

Utilizar números reales para guardar números enteros grendes es muy mala idea.
Un float o un duble puede guardar números altos pero no puede guardarlos todos("tiene agujeros").

```cpp
int i = 0;
float f = i;

while(i == f){
   ++i;
   ++f;
}
```

## Aritmética modular

Cuando el resultado de un problema puede ser muy alto, muchos enunciados piden el resultado modulo m.
El resultado de una operación modulo m es el resto de la división entre el resultado y m.
El m suele ser un número primo, pero no siempre, por ejemplo 1.000.000.0007, solo puede tomar calores entro 0 y m-1 y hace pequeño un número grande.

Imagniemos que nos piden la suma de 45+65+70 modulo 47.
(45+65+70)%47 = 180%47 = 39 (180=47\*3+39)
Y si esatamos en un ordenador que solo puede guardar dos dígitos deciamles.

Aprobecha la aritmetica del reloj para volber al rango de la representacion antes de salirnos.
Propiedad de la suina (simetricamente resta):
(a+b)%m = (a%m + b%m)%m
(a+b+c)%m = ((a+b)%m + c%m)%m

## MCM y MCM

Maximo común Divisor (CMD o GCD en inglés), de dos números a y b.
Mayor número que divide simultaneamente a y b.
Factores primos comunes al menor exponente.

Mínimo Común Múltiplo (MCM o LCM en inglés) de dos números a y b.
Menor número que es múltiplo de a y b simultaneamente de a y de b.
Factores primos comunes y no comunes al mayor exponente.

## El algoritmo de Euclides

- MCD

Los segmentes AD y CD se dice que son conmensurables si existe un tercer segmento s tal que AB y CD pueden ambos medirse de forma exacta utilizando el segmento s como "unidad".
A|---------------|B
C|--------|D
S|---|
La longirtud de los segmentos s es un divisor de la longitud de los segmentos AB y CD.
Puede demostrerse que es el maximo común divisor de AB y CD.

Procedemos a programarlo con una funcion recursiva.

```cpp
int gcd(int a, int b){
   if(b == 0) return a;
   return gcd(b, a%b);
}
```

- MCM

El mínimo común múltiplo se puede calcular a partir del máximo común divisor.
MCM(a,b) factores primos comunes al menor exponente.
MCD(a,b) factores primos comunes y no comunes al mayor exponente.
a x b factores primos comunes al de menor exponente dos veces y los no comunes una vez.

```cpp
int lcm(int a, int b){
   return a*b/gcd(a,b);
}
```

## Factorial

El factorial de un número positivo n representado como n! es el producto de todos los números naturales desde 1 hasta n.

```cpp
// Recursivo
long long factorialRec(int n){
   if(n == 0) return 1;
   return n*factorialRec(n-1);
}
// Iterativo
long long factorialIt(int n) {
  ll r = 1;
  while (n > 0) {
    r *= n;
    --n;
  }
  return r;
}
```

## Progresiones aritméticas y geométricas

Suma de una progressión aritmética de n términos.
1+2+3+4+5+...+n = n(n+1)/2
a+(a+d)+(a+2d)+...+(a+(n-1)d) = n(a+a+(n-1)d)/2 = n(2a+(n-1)d)/2

Suma de una progressión geométrica de n términos.
1+2+4+8+16+...+2^n = 2^(n+1)-1
b^0+b^1+b^2+...+b^n = (b^(n+1)-1)/(b-1)
