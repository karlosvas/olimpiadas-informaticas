package p73LaCuerdaDeLaCometa;

import java.io.FileNotFoundException;
import java.util.Scanner;

public class LaCuerdaDeLaCometa {
    static Scanner in;

    static class Pair {
        int longitud, precio;

        Pair(int longitud, int precio) {
            this.longitud = longitud;
            this.precio = precio;
        }
    }

    public static boolean solve() {
        if (!in.hasNextInt()) return false;

        // Número de cordeles N
        int N = in.nextInt();
        // Longitud de la cuerda L
        int L = in.nextInt();

        // Lista de cuerdas con sus longitudes y precios
        Pair[] list = new Pair[N];
        for (int i = 0; i < N; i++) {
            int longitud = in.nextInt();
            int precio = in.nextInt();
            list[i] = new Pair(longitud, precio);            
        }

        // Llamada a la función de programación dinámica
        int result = bottomUp(N, L, list);
        int resultMin = bottomUpMin(N, L, list);
        int resultMinCost = bottomUpMinCost(N, L, list);
        if (result > 0)
            System.out.println("SI " + result+ " " + resultMin + " " + resultMinCost);
        else
            System.out.println("NO");

        return true;
    }

    // Formas de obtener una cuerda de longitud r usando cuerdas de longitud y precio dados
    // Programación dinámica ascendente
    public static int bottomUp(int n, int r, Pair[] list) {
        int[] dp = new int[r + 1];
        // Solo hay una forma de formar una cuerda de longitud 0: no usar ninguna cuerda
        dp[0] = 1; 

        // Iteramos sobre cada cuerda
        for (int i = 0; i < n; i++) {
            int longitud = list[i].longitud;

            // Actualizamos dp de forma descendente para evitar usar la misma cuerda varias veces
            for (int j = r; j >= longitud; j--) {
                dp[j] += dp[j - longitud];
            }
        }

        // Formas de formar la cuerda de longitud r
        return dp[r];
    }

    // Formas de obtener uan cuerda tamaño r con el mínimo número posible de cuerdas a utilizar
    // Programación dinámica ascendente
    public static int bottomUpMin(int n, int r, Pair[] list) {
        int[] dp = new int[r + 1];
        // Inicializamos el array con un valor grande
        for (int i = 1; i <= r; i++) {
            dp[i] = Integer.MAX_VALUE;
        }
        // Solo hay una forma de formar una cuerda de longitud 0 no usar ninguna cuerda
        dp[0] = 0; 

        // Iteramos sobre cada cuerda
        for (int i = 0; i < n; i++) {
            int longitud = list[i].longitud;

            // Actualizamos dp de forma descendente para evitar usar la misma cuerda varias veces
            for (int j = r; j >= longitud; j--) {
                if (dp[j - longitud] != Integer.MAX_VALUE) {
                    // Si la cuerda de longitud j - longitud se puede formar, actualizamos el mínimo
                    // número de cuerdas necesarias para formar la cuerda de longitud j
                    dp[j] = Math.min(dp[j], dp[j - longitud] + 1);
                }
            }
        }

        // Formas de formar la cuerda de longitud r
        return dp[r] == Integer.MAX_VALUE ? -1 : dp[r];
    }

    // Forma de crear una cometa con una cuerda de longitud r mas barata
    public static int bottomUpMinCost(int n, int r, Pair[] list) {
        int[] dp = new int[r + 1];
        // Inicializamos el array con un valor grande
        for (int i = 1; i <= r; i++) {
            dp[i] = Integer.MAX_VALUE;
        }
        // Solo hay una forma de formar una cuerda de longitud 0: no usar ninguna cuerda
        dp[0] = 0; 

        // Iteramos sobre cada cuerda
        for (int i = 0; i < n; i++) {
            int longitud = list[i].longitud;
            int precio = list[i].precio;

            // Actualizamos dp de forma descendente para evitar usar la misma cuerda varias veces
            for (int j = r; j >= longitud; j--) {
                if (dp[j - longitud] != Integer.MAX_VALUE) {
                    // Si la cuerda de longitud j - longitud se puede formar, actualizamos el mínimo
                    // número de cuerdas necesarias para formar la cuerda de longitud j
                    dp[j] = Math.min(dp[j], dp[j - longitud] + precio);
                }
            }
        }

        // Formas de formar la cuerda de longitud r
        return dp[r] == Integer.MAX_VALUE ? -1 : dp[r];
    }

    public static void main(String[] args) throws FileNotFoundException {
        boolean isDebug = false;
        if (isDebug)
            in = new Scanner(new java.io.File("DOMjudge-2024/LaCuerdaDeLaCometa/input.txt"));
        else
            in = new Scanner(System.in);

        while (solve());

        in.close();
    }
}