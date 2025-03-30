package Aibofobia;

import java.io.FileNotFoundException;
import java.util.Scanner;

public class Aibofobia {
    static Scanner in;
    static int[][] P;

    public static boolean solve() {
        if (!in.hasNextLine()) return false;
        
        String patitos = in.nextLine();

        int N = patitos.length();

        P = new int[N][N];
        P[N-1][N-1] = 1;
        for (int i = N-2; i >= 0; --i) {
            P[i][i] = 1;
            P[i+1][i] = 0;
            for (int j = i+1; j < N; ++j) {
                if (patitos.charAt(i) == patitos.charAt(j)) {
                    P[i][j] = P[i+1][j-1] + 2;
                } else {
                    P[i][j] = Math.max(P[i+1][j], P[i][j-1]);
                }
            }
        }

        int minLettersToAdd = N - P[0][N-1];
        String palindrome = construirPalindromo(0, N-1, patitos);
        
        System.out.println(minLettersToAdd + " " + palindrome);

        return true;
    }


    public static String construirPalindromo(int i, int j, String patitos) {
        if (i > j) return "";
        if (i == j) {
            return String.valueOf(patitos.charAt(i));
        } else if (patitos.charAt(i) == patitos.charAt(j)) {
            return patitos.charAt(i) + construirPalindromo(i+1, j-1, patitos) + patitos.charAt(j);
        } else if (P[i][j] == P[i+1][j]) {
            return patitos.charAt(i) + construirPalindromo(i+1, j, patitos) + patitos.charAt(i);
        } else {
            return patitos.charAt(j) + construirPalindromo(i, j-1, patitos) + patitos.charAt(j);
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        boolean isDebug = false;
        if (isDebug)
            in = new Scanner(new java.io.File("DOMjudge-2024/Aibofobia/input.txt"));
        else
            in = new Scanner(System.in);
        while (solve());

        in.close();
    }
}