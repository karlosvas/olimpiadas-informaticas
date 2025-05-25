package p96LigasEscolares;

import java.io.FileNotFoundException;
import java.util.Scanner;

public class p96LigasEscolares {
    static Scanner in;

    public static void main(String[] args) throws FileNotFoundException {
        boolean isDebug = false;
        if (isDebug)
            in = new Scanner(new java.io.File("DOMjudge-2024/p96LigasEscolares/input.txt"));
        else
            in = new Scanner(System.in);
        
        
        int q = in.nextInt();
        for (int i = 0; i < q; i++) {
            // Numero de alumnos que tienen interes en jugar determinado deporte en las ligas escolares (N)
            // Tamaño de los equipos (E)
            long n = in.nextLong();
            long e = in.nextLong();

            
            // Podemos obtener el complemento ya que elegir e elementos es equivalente a elegir los n - e que se quedan fuera.
            if (e > n - e) e = n - e;
            
            // Iteativo para evitar overflow de calcular factoriales grandes
            long res = 1;
            for (long j = 1; j <= e; j++) {
                res *= (n - j + 1); // !n = n * (n - 1) * ... * (n - e + 1)
                res /= j; // j! = j * (j - 1) * ... * 1
            }
            System.out.println(res);
        }

        in.close();
    }
}