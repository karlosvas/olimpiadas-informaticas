package p67LaPiezaPerdida;

import java.io.FileNotFoundException;
import java.util.Scanner;

public class LaPiezaPerdida67 {
    static Scanner in;

    public static boolean solve() {
        // Cantidad de piezas del puzle(n)
        int n = in.nextInt();
    
        if (n == 0)
            return false;

        // Sumamos toda la entrada
        int suma = 0;
        for (int i = 1; i < n; i++)
            suma += in.nextInt();

        // Utilizamos la formula de la suma de los n primeros numeros naturales de Gauss
        // para calcular la pieza perdida, el resultado es la diferencia entre
        // la suma de las piezas que encuentra y la suma de 1 a n
        System.out.println(Math.abs(suma - (n * (n + 1) / 2)));
        return true;
    }

    public static void main(String[] args) throws FileNotFoundException {
        in = new Scanner(System.in);
        while (solve());
        in.close();
    }
}