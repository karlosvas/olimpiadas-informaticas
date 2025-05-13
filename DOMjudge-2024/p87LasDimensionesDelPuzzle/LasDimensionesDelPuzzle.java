package p87LasDimensionesDelPuzzle;

import java.io.FileNotFoundException;
import java.util.Scanner;

public class LasDimensionesDelPuzzle {
    static Scanner in;

    public static boolean solve() {
        int n;
        n = in.nextInt();

        if(n == 0)
            return false;
        
        // Encontramos cual es el mayor divisor de n
        int divisor = 1;
        for (int i = 1; i*i<=n; i++) {
            if(n%i==0)
                divisor = i;
        }

        // El lado mas largo del puzle será igual al mayor divisor
        System.out.println(n/divisor);
        return true;
    }

    public static void main(String[] args) throws FileNotFoundException {
        boolean isDebug = false;
        if (isDebug)
            in = new Scanner(new java.io.File("DOMjudge-2024/p87LasDimensionesDelPuzzle/input.txt"));
        else
            in = new Scanner(System.in);
        while (solve());

        in.close();
    }
}