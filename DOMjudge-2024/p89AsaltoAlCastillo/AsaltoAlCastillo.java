package p89AsaltoAlCastillo;

import java.io.FileNotFoundException;
import java.util.Scanner;

public class AsaltoAlCastillo {
    static Scanner in;

    public static boolean solve() {
        int n;
        n = in.nextInt();

        if(n == 0) return false;
        
        int count = 0;
        for (int i = 1; i*i <= n; i++) {
            if(n%i == 0){
                if(i*i == n) count++;
                else count+=2;
            }
        }

        System.out.println(count);
        return true;
    }

    public static void main(String[] args) throws FileNotFoundException {
        boolean isDebug = false;
        if (isDebug)
            in = new Scanner(new java.io.File("DOMjudge-2024/p89AsaltoAlCastillo/input.txt"));
        else
            in = new Scanner(System.in);
        while (solve());

        in.close();
    }
}