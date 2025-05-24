package p97EtiquetandoSobres;

import java.io.FileNotFoundException;
import java.util.Scanner;

public class p98EtiquetandoSobres {
    static Scanner in;
    static final int MOD = 1_000_000_007;
    static final int MAX_N = 2_000_000;
    static int[] desarreglos = new int[MAX_N + 1];

    public static void main(String[] args) throws FileNotFoundException {
        boolean isDebug = false;
        if (isDebug)
            in = new Scanner(new java.io.File("DOMjudge-2024/p98EtiquetandoSobres/input.txt"));
        else
            in = new Scanner(System.in);

        int N = in.nextInt();

        // Formula de recurrencia de los deesarreglos o subfactorial
        // !n = (n-1)*(!(n-1)+ !(n-1))
        desarreglos[0] = 1;
        desarreglos[1] = 0;
        for (int i = 2; i <= MAX_N; i++) 
            desarreglos[i] = (int)(((long)(i - 1) * (desarreglos[i - 1] + desarreglos[i - 2])) % MOD);

        while (N-- > 0){
             int n = in.nextInt();
            // !n subfactorial: cuantas formas hay de desordenar un componente n objetos, es decir, que ninguno quede en su sitio original.
            System.out.println(desarreglos[n]);
        };
    }
}