#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// Binary Search básico - versión iterativa
int binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // Evita overflow

        if (arr[mid] == target)
            return mid;  // Elemento encontrado
        else if (arr[mid] < target)
            left = mid + 1;  // Buscar en la mitad derecha
        else
            right = mid - 1;  // Buscar en la mitad izquierda
    }

    return -1;  // Elemento no encontrado
}

// Binary Search - versión recursiva
int binarySearchRecursive(vector<int>& arr, int target, int left, int right) {
    if (left > right)
        return -1;  // Elemento no encontrado

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return binarySearchRecursive(arr, target, mid + 1, right);
    else
        return binarySearchRecursive(arr, target, left, mid - 1);
}

// Encontrar la primera ocurrencia de un elemento
int findFirst(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;
            right = mid - 1;  // Continuar buscando a la izquierda
        } else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return result;
}

// Encontrar la última ocurrencia de un elemento
int findLast(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;
            left = mid + 1;  // Continuar buscando a la derecha
        } else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return result;
}

// Buscar el elemento más pequeño >= target (lower bound)
int lowerBound(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}

// Buscar el elemento más pequeño > target (upper bound)
int upperBound(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] <= target)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}

// Binary Search en números flotantes
double binarySearchFloat(double left, double right, double target,
                         double (*func)(double), double epsilon = 1e-9) {
    while (right - left > epsilon) {
        double mid = (left + right) / 2.0;
        double value = func(mid);

        if (abs(value - target) < epsilon)
            return mid;
        else if (value < target)
            left = mid;
        else
            right = mid;
    }

    return (left + right) / 2.0;
}

// Función para encontrar la raíz cuadrada usando binary search
double sqrtBinarySearch(double x) {
    if (x < 0) return -1;  // No existe raíz real
    if (x == 0 || x == 1) return x;

    double left = 0;
    double right = x > 1 ? x : 1;
    double epsilon = 1e-9;

    while (right - left > epsilon) {
        double mid = (left + right) / 2.0;
        double square = mid * mid;

        if (abs(square - x) < epsilon)
            return mid;
        else if (square < x)
            left = mid;
        else
            right = mid;
    }

    return (left + right) / 2.0;
}

// Binary Search en array rotado
int searchRotatedArray(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        // Determinar qué lado está ordenado
        if (arr[left] <= arr[mid]) {
            // Lado izquierdo está ordenado
            if (target >= arr[left] && target < arr[mid])
                right = mid - 1;
            else
                left = mid + 1;
        } else {
            // Lado derecho está ordenado
            if (target > arr[mid] && target <= arr[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}

// Encontrar el pico en un array (elemento mayor que sus vecinos)
int findPeak(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] < arr[mid + 1])
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}

// Función de ejemplo para binary search en flotantes
double exampleFunction(double x) {
    return x * x;  // f(x) = x²
}

// Función de pruebas y ejemplos
int main() {
    cout << "=== Algoritmo Binary Search (Búsqueda Binaria) ===" << "\n";

    // Ejemplo 1: Binary Search básico
    cout << "\n1. Binary Search básico:" << "\n";
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 7;

    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    int result = binarySearch(arr, target);
    cout << "Buscando " << target << ": ";
    if (result != -1)
        cout << "Encontrado en índice " << result << "\n";
    else
        cout << "No encontrado" << "\n";

    // Ejemplo 2: Binary Search recursivo
    cout << "\n2. Binary Search recursivo:" << "\n";
    target = 13;
    result = binarySearchRecursive(arr, target, 0, arr.size() - 1);
    cout << "Buscando " << target << " (recursivo): ";
    if (result != -1)
        cout << "Encontrado en índice " << result << "\n";
    else
        cout << "No encontrado" << "\n";

    // Ejemplo 3: Array con duplicados
    cout << "\n3. Primera y última ocurrencia:" << "\n";
    vector<int> arrDup = {1, 2, 2, 2, 3, 4, 4, 5, 6};
    target = 2;

    cout << "Array con duplicados: ";
    for (int x : arrDup) cout << x << " ";
    cout << "\n";

    int first = findFirst(arrDup, target);
    int last = findLast(arrDup, target);
    cout << "Elemento " << target << ": primera ocurrencia = " << first
         << ", última ocurrencia = " << last << "\n";

    // Ejemplo 4: Lower y Upper bound
    cout << "\n4. Lower y Upper bound:" << "\n";
    target = 4;
    int lb = lowerBound(arrDup, target);
    int ub = upperBound(arrDup, target);
    cout << "Para elemento " << target << ":" << "\n";
    cout << "Lower bound (>=): índice " << lb << "\n";
    cout << "Upper bound (>): índice " << ub << "\n";

    // Ejemplo 5: Raíz cuadrada
    cout << "\n5. Raíz cuadrada usando binary search:" << "\n";
    double num = 25.0;
    double sqrt_result = sqrtBinarySearch(num);
    cout << "Raíz cuadrada de " << num << " = " << sqrt_result << "\n";

    // Ejemplo 6: Array rotado
    cout << "\n6. Búsqueda en array rotado:" << "\n";
    vector<int> rotated = {4, 5, 6, 7, 0, 1, 2};
    target = 0;

    cout << "Array rotado: ";
    for (int x : rotated) cout << x << " ";
    cout << "\n";

    result = searchRotatedArray(rotated, target);
    cout << "Buscando " << target << " en array rotado: ";
    if (result != -1)
        cout << "Encontrado en índice " << result << "\n";
    else
        cout << "No encontrado" << "\n";

    // Ejemplo 7: Encontrar pico
    cout << "\n7. Encontrar pico en array:" << "\n";
    vector<int> peakArr = {1, 3, 20, 4, 1, 0};

    cout << "Array: ";
    for (int x : peakArr) cout << x << " ";
    cout << "\n";

    int peakIndex = findPeak(peakArr);
    cout << "Pico encontrado en índice " << peakIndex
         << " con valor " << peakArr[peakIndex] << "\n";

    // Ejemplo 8: Binary search en flotantes
    cout << "\n8. Binary search en números flotantes:" << "\n";
    cout << "Buscando x tal que x² = 16 en el rango [0, 10]:" << "\n";
    double floatResult = binarySearchFloat(0.0, 10.0, 16.0, exampleFunction);
    cout << "Resultado: x = " << floatResult << ", verificación: "
         << floatResult << "² = " << floatResult * floatResult << "\n";

    return 0;
}

/*
Complejidad del algoritmo Binary Search:
- Tiempo: O(log n)
- Espacio: O(1) para versión iterativa, O(log n) para recursiva

Prerrequisitos:
- El array debe estar ordenado

Variantes importantes:
1. Binary Search básico - buscar un elemento
2. First/Last occurrence - encontrar primera/última aparición
3. Lower/Upper bound - encontrar límites
4. Binary Search en flotantes - para funciones continuas
5. Binary Search en arrays rotados
6. Encontrar picos o valles

Casos de uso comunes:
- Búsqueda en arrays ordenados
- Encontrar límites en rangos
- Optimización en funciones unimodales
- Búsqueda de raíces de funciones
- Problemas de "adivinar y verificar"

Ventajas:
- Muy eficiente: O(log n)
- Fácil de implementar
- Aplicable a muchos problemas

Desventajas:
- Requiere que los datos estén ordenados
- No funciona bien con acceso secuencial
*/