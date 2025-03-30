package p03Erasmus03;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Erasmus03 {

    // Calcula el total de parejas heterogéneas posibles
    public static BigInteger erasmus(List<BigInteger> students) {
        // Total de parejas heterogéneas
        BigInteger ret = BigInteger.ZERO;
        // Suma de todos los elementos desde (v[o], v[i-1])
        BigInteger suma = BigInteger.ZERO;

        // Se recorren todos los estudiantes
        for (int i = 0; i < students.size(); ++i) {
            // El actual multiplicado por la suma de todos los anteriores
            ret = ret.add(students.get(i).multiply(suma));
            // Sumamos todos los valores anteriores de v[i] para añadirlo a la zona de oscuridad (recorrido)
            suma = suma.add(students.get(i));
        }

        return ret;
    }

    public static boolean solve(Scanner sc) {
        // Paises totales representados
        int n = sc.nextInt();
        
        if (n == 0) return false;

        // Cantidad de estudiantes por cada país
        List<BigInteger> students = new ArrayList<>(n);
        for (int i = 0; i < n; ++i) {
            students.add(sc.nextBigInteger());
        }

        System.out.println(erasmus(students));
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (solve(scanner));
        scanner.close();
    }
}