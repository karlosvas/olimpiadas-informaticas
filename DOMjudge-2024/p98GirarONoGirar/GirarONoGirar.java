package p98GirarONoGirar;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class GirarONoGirar {
    static Scanner in;

    public static boolean solve() {
        if (!in.hasNext()) return false;
        
        String s = in.next();
        int longitud = s.length();
        
        int unos = 0, ceros = 0;
        for (int i = 0; i < longitud; i++) {
            // Como sabemos que se disparo antes de utilizarla, las posibles posiciones son las que van despues de un cero
            if (s.charAt(i) == '0') {
                if (s.charAt((i + 1) % longitud) == '0') ceros++;
                else unos++;
            }
        }

        
        // Obtenemos la probabilidad de no girar
        float noGirar = (float)((float)ceros / (float)(ceros+unos));
        // Si giramos, la probabilidad de no encontrarse una bala en la siguiente posición es cantidad de 0 / cantidad de posibilidades
        float girar = (float)((float)(ceros+unos) / (float)longitud);

        if(girar == noGirar)
            System.out.println("Da igual");
        else if(girar > noGirar)
            System.out.println("Girar");
        else
            System.out.println("No girar");

        return true;
    }

    public static void main(String[] args) throws FileNotFoundException {
        boolean isDebug = false;
        if (isDebug)
            in = new Scanner(new java.io.File("DOMjudge-2024/p99GirarONoGirar/input.txt"));
        else
            in = new Scanner(System.in);
        while (solve());

        in.close();
    }
}