package p01_SietePicos;

import java.io.FileNotFoundException;
import java.util.Scanner;

public class SietePicos1 {
    static Scanner in;

    static int numPicos(int[] v) {
        int picos = 0;
        int n = v.length;
        
        // Desde el segundo elemento hasta el penúltimo para no salirnos de rango
        for (int i = 1; i < n - 1; ++i) {
            if (v[i - 1] < v[i] && v[i] > v[i + 1])
                ++picos;
        }
        
        // Comprobamos los extremos
        if (v[n - 1] < v[0] && v[0] > v[1])
            picos++;
            
        if (v[n - 2] < v[n - 1] && v[n - 1] > v[0])
            picos++;
            
        return picos;
    }
    
    static boolean solve(Scanner sc) {
        // Veces que se ha anotado la altura del recorrido (n)
        int n = sc.nextInt();
        if (n == 0) return false;
        
        // Guardamos las alturas de la monatña rusa
        int[] v = new int[n];
        for (int i = 0; i < n; i++) 
            v[i] = sc.nextInt();
        
        // Calculamos las veces que la montaña rusa ha alcanzado un pico
        int picos = numPicos(v);
        System.out.println(picos);
        
        return true;
    }

    public static void main(String[] args) throws FileNotFoundException {
        boolean isDebug = false;
        if (isDebug)
            in = new Scanner(new java.io.File("DOMjudge-2024/SietePicos1/input.txt"));
        else
            in = new Scanner(System.in);
        while (solve(in));

        in.close();
    }
}