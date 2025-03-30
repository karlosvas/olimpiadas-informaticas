package p72_Unos;

import java.util.Scanner;

public class Unos72 {
    static Scanner in;

    public static boolean solve() {
        if (!in.hasNextInt()) return false;
        // Numero inpar no termina en 5 dado por el usuario (n)
        int n = in.nextInt();
        
        // Digitos de unos que deven ser divisores de n, ya que es lo mismo que
        // encontrar un nnumero x que al multiplicarlo por n de como resultado (unos)
        // Buscar el número mínimo de unos consecutivos divisible por n
        long unos = 1;
        long digitos = 1;
        while (unos % n != 0) {
            // 1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111
            unos = (unos * 10 + 1) % n; 
            digitos++;
        }

        System.out.println(digitos);
        return true;
    }

    public static void main(String[] args) {
        in = new Scanner(System.in);
        while (solve());
        in.close();
    }
}
