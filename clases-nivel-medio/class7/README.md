# Clase de repaso
De esta manera podremos tranformar código exadecimala código binario.
La linea en una secuencia de valores booleanos almacenados en un vector v.

### Parámetros de la función:
string const &linea: Una referencia constante a una cadena de caracteres. La función toma la cadena linea como entrada sin modificarla.
vector<bool> &v: Una referencia a un vector de booleanos. La función modificará este vector para almacenar la salida.
Bucle Externo:

```cpp
for (int i = 0; i < linea.length(); i++)
```
Itera a través de cada caracter en la cadena linea.
Conversión de Caracter a Valor Entero:

```cpp
int interval = (linea[i] >= 'a') ? (linea[i] - 'a' + 10) : (linea[i] - '0');
```
Convierte el caracter actual en un valor entero. Si el caracter es una letra minúscula, se resta 'a' y se suma 10; de lo contrario, se resta '0'. Esto es típico en la conversión de caracteres hexadecimales.
Bucle Interno:

```cpp
Copy code
for(int  j = 3; j >= 0; --j)
```
Itera sobre cada bit del valor entero obtenido en el paso anterior.
Asignación de Valores al Vector:

```cpp
v[4*i+j] = (interval % 2) ? negro : blanco;
```
Asigna el valor del bit actual al elemento correspondiente en el vector v. El operador ternario se utiliza para determinar si el bit es 0 o 1, y se asigna negro o blanco en consecuencia.
División por 2:

```cpp
interval /= 2;
```
Divide el valor entero por 2 para moverse al siguiente bit.
Fin del Bucle Interno y Bucle Externo:

Después de completar el bucle interno, el bucle externo continúa con el siguiente caracter en la cadena linea.
Fin de la Función:

La función termina después de procesar todos los caracteres en la cadena linea
```cpp
void hexa_to_bin(string const &linea, vector<bool> &v){
    for (int i = 0; i < linea.lenght(); i++){
        int interval = (linea[i] >= 'a') ? (line[i] - 'a' + 10) : (linea[i] - '0')
        for(int  j = 3; j >= 0; --j){
            v[4*i+j] = (interval % 2) ? negro : blanco;
            interval /= 2;
        }
    }
    
}
```
# Pistas
## Ejercicio 18
Quitar el fondo vertical y horizontal.

## Ejercicio 23
Hay que buscar el camino mas barato utilizando v[a]+v[l]+v[t] a cada uno de los vertices.

## Ejercicio 19
Hacer un grafo dirijido.
Con tres aristas +1,*2 y /3. Un solo grafo por cada caso de prueba.
No puede dar mas de 23.

## Ejercicio 22
Si hay muro o recorrido del sensor = true en el vector de visitados. Preprocesamiento y depués lectura.