package p71_VelasBinarias;

import java.io.FileNotFoundException;
import java.util.Scanner;

public class VelasBinarias71 {
    static Scanner in;

    public static boolean solve() {
        // Leer número entero largo
        if (!in.hasNextLong()) return false;
        
        long N = in.nextLong();
        
        // Condición de terminación
        if (N == 0) 
            return false;
        
        // Convertir a binario, eliminando ceros iniciales
        StringBuilder binary = new StringBuilder();
        boolean foundOne = false;
        
        // Iterar por cada bit (de 63 a 0)
        for (int i = 63; i >= 0; i--) {
            // Comprobar si el bit i-ésimo está activado
            if (((N >> i) & 1) == 1) {
                binary.append("1");
                foundOne = true;
            } else if (foundOne) {
                binary.append("0");
            }
        }
        
        // Eliminar ceros finales
        int end = binary.lastIndexOf("1");
        String binaryStr = binary.substring(0, end + 1);
        
        // Crear el string reverso
        StringBuilder reverseBinary = new StringBuilder(binaryStr).reverse();
        
        // Comprobar si es palíndromo
        if (binaryStr.equals(reverseBinary.toString())) {
            System.out.println("SI");
        } else {
            System.out.println("NO");
        }
        
        return true;
    }

    public static void main(String[] args) throws FileNotFoundException {
        boolean isDebug = false;
        if (isDebug)
            in = new Scanner(new java.io.File("DOMjudge-2024/ClassName/input.txt"));
        else
            in = new Scanner(System.in);
        while (solve());

        in.close();
    }
}
