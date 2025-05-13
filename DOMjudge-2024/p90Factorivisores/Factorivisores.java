package p90Factorivisores;

import java.io.FileNotFoundException;
import java.util.Scanner;

public class Factorivisores {
    static Scanner in;

    public static boolean solve() {
        if (!in.hasNextLong()) return false;

        long f = in.nextLong();
        long d = in.nextLong();

        if (d == 0) {
            System.out.printf("%d no divide a %d!%n", d, f);
            return true;
        }

        if (isDivisibleByFactorial(f, d)) {
            System.out.printf("%d divide a %d!%n", d, f);
        } else {
            System.out.printf("%d no divide a %d!%n", d, f);
        }

        return true;
    }

    public static boolean isDivisibleByFactorial(long f, long d) {
        long remaining = d;

        for (long i = 2; i * i <= remaining; i++) {
            int count = 0;
            while (d % i == 0) {
                d /= i;
                count++;
            }

            // Contar cuántas veces aparece i en f!
            long factorCount = 0;
            for (long j = i; j <= f; j *= i) {
                factorCount += f / j;
            }

            if (factorCount < count)
                return false;
        }

        // Si queda un primo mayor que sqrt(d)
        if (d > 1) {
            long factorCount = 0;
            for (long j = d; j <= f; j *= d) {
                factorCount += f / j;
            }

            if (factorCount < 1)
                return false;
        }

        return true;
    }

    public static void main(String[] args) throws FileNotFoundException {
        boolean isDebug = false;
        if (isDebug)
            in = new Scanner(new java.io.File("DOMjudge-2024/p90Factorivisores/input.txt"));
        else
            in = new Scanner(System.in);

        while (solve());

        in.close();
    }
}
