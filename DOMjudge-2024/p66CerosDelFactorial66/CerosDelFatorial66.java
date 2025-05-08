package p66CerosDelFactorial66;

import java.util.Scanner;

public class CerosDelFatorial66 {
    static Scanner in;

    // Cerosntidad de ceros en el factorial de un número !k
    public static long factoriaZero(long k) {
        // La cantidad de ceros finales en un factorial está determinada por 
       // la cantidad de factores 5 en la descomposición factorial
       // Cada factor 5 añade un cero, cada factor 25 añade otro cero adicional, etc.
       long zeros = 0, i = 5;
       while ((k / i) >= 1) {
         zeros += k / i;
         i *= 5;
       }
       return zeros;
    }

    public static void main(String[] args)  {
        in = new Scanner(System.in);
        int n = in.nextInt();
        while (n-- > 0) {
            int k = in.nextInt();
            if(k < 5)
                System.out.println(0);
            else 
                System.out.println(factoriaZero(k));
        }
        in.close(); 
    }
}
