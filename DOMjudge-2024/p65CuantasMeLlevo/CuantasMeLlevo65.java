package p65_CuantasMeLlevo;

import java.io.FileNotFoundException;
import java.util.Scanner;

public class CuantasMeLlevo65 {
    static Scanner in;

    public static boolean solve() {
        String nStr = in.next();
        String mStr = in.next();
        
        if (nStr.equals("0") && mStr.equals("0"))
            return false;
        
        // Procesar como strings directamente
        int count = 0;
        int carry = 0;
        
        // Determinar longitud máxima
        int maxLength = Math.max(nStr.length(), mStr.length());
        
        // Rellenar con ceros a la izquierda para facilitar el procesamiento
        nStr = String.format("%" + maxLength + "s", nStr).replace(' ', '0');
        mStr = String.format("%" + maxLength + "s", mStr).replace(' ', '0');
        
        // Procesar de derecha a izquierda
        for (int i = maxLength - 1; i >= 0; i--) {
            int digitN = nStr.charAt(i) - '0';
            int digitM = mStr.charAt(i) - '0';
            
            int sum = digitN + digitM + carry;
            
            if (sum >= 10) {
                count++;
                carry = 1;
            } else {
                carry = 0;
            }
        }
        
        
        System.out.println(count);
        
        return true;
    }

    public static void main(String[] args) throws FileNotFoundException {
        in = new Scanner(System.in);
        while (solve());
        in.close();
    }
}