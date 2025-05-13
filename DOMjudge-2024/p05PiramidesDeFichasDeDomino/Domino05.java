package p05PiramidesDeFichasDeDomino;
import java.util.Scanner;

public class Domino05 {

    // Calcula la altura de la pirámide más alta que se puede construir con las fichas dadas
    public static int calcularAltura(int fichas) {
        // La altura es la diferencia entre los dos punteros al array imaginario
        int a = 1, b = 1;
        // Fichas utilizadas entre a y b (fu)
        int fu = 0;
        
        // Probamos a construir una pirámide con el método de Gauss con una ventana deslizante desde a hasta b
        while(fu != fichas){
            fu = (b - a + 1) * (a + b) / 2;
            if(fu < fichas){
                // Me faltan fichas para construir la pirámide por lo que hago la ventana mas grande
                b++;
            }else if(fu > fichas){
                // Me sobran fichas para construir la pirámide por lo que hago la ventana mas pequeña
                a++;
            }
        }
        
        return Math.abs(a - b) + 1;
    }

    public static boolean solve(Scanner sc)  {
        // Si no hay entrada terminamos
        if (!sc.hasNext()) return false;
        int n = sc.nextInt();

        // Calculamos la mayor altura de la pirámide que se puede construir permitiendo truncarla
        System.out.println(calcularAltura(n));
        return true;
    }

    public static void main(String[] args)  {
        Scanner sc = new Scanner(System.in);
        while (solve(sc));
        sc.close();
    }
}