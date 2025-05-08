package p70HayQueCompartir;

import java.io.FileNotFoundException;
import java.util.Scanner;

public class HayQueCompartir70 {
    static Scanner in;

    public static boolean solve() {
        // Obtenemos al cantidad de comensales (comensales)
        long comensales = in.nextLong();
        in.nextLine();

        if (comensales == 0) return false;
        
        // Obtenemos los macarrones de cada comensal
        String[] macarrons = in.nextLine().split(" ");
        // Creamos dos arrays para guardar los numeradores y denominadores de cada fracción
        long[] numeradores = new long[(int) comensales];
        long[] denominadores = new long[(int) comensales];
        
        // Obtenemos el mínimo común múltiplo de todos los denominadores
        long actualDenominador = 1;
        for (int i = 0; i < macarrons.length; i++) {
            // Obtenemos la fracción y la almacenamos
            String[] part = macarrons[i].split("/");   
            long numerador = Integer.parseInt(part[0]);
            long denominador = Integer.parseInt(part[1]);
            numeradores[i] = numerador;
            denominadores[i] = denominador;
            // Calculadmos el mínimo común múltiplo de todos los denominadores
            actualDenominador = mcm(actualDenominador, denominador);
        }

        int sol = 0;
        // Una vez sablemos el mcm de todos los denominadores, calculamos el total de macarrones que sobran de la fracción
        for (int j = 0; j < comensales; j++) {
            // Numerador
            long numerador = numeradores[j];
            // Denominador
            long denominador = denominadores[j];
            // Factor para igualar denominadores, una vez igualados se suman los numeradores para obtener el total corresponiente a esa fracción
            long factor = actualDenominador / denominador;
            numerador = numerador * factor;
            sol += numerador;
        }

        System.out.println(actualDenominador-sol);
        return true;
    }

    // Funciones para el cálculo del mínimo común múltiplo y 
    public static long mcm(long a, long b) {
        return (a * b) / gcd(a, b);
    }

    // máximo común divisor
    public static long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    public static void main(String[] args) throws FileNotFoundException {
        in = new Scanner(System.in);
        while (solve());
        in.close();
    }
}
