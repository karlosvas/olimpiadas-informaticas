package LosParasoles;

import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Random;

public class LosParasoles64 {
    static Scanner in;
    static boolean isDebug = false;
    static Random rand = new Random();
    static int tamX, tamY;
    static int cantidadDePruebas = 0;

    static class Pair {
        int first;
        int second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    // Consulta al juez o devuelve la respuesta en modo debug
    public static boolean query(int midX, int midY){
        // Si la zona esta afectada por el parasol, devolvemos true (1), si no, devolvemos false (0)
        // O en caso de ser el juez el contestará por nosotros
        if(isDebug){
            return (midX >= tamX && midY >= tamY);
        } else {
            System.out.println("? " + midX + " " + midY);
            System.out.flush();
            return in.next().equals("1");
        }
    }

    // Busqueda binaria en los dos ejes
    public static Pair binarySearch(int x, int y) {
        // Busqueda binaria en el eje X
        int left = 0;
        int rightX = x;
        // Busqueda binaria tipo abierto cerrado (left, rightX] en base a las respuestas del juez
        while(left + 1 < rightX){
            int mid = (left + rightX) / 2;
            if(query(mid, y)) rightX = mid;
            else left = mid;
        }

        // Busqueda binaria en el eje Y
        int down = 0;
        int downY = y;
        // Busqueda binaria tipo abierto cerrado (down, downY] en base a las repuestas del jeuz
        while(down + 1 < downY){
            int mid = (down + downY) / 2;
            if(query(x, mid)) downY = mid;
            else down = mid;
        }

        return new Pair(rightX, downY);
    }

    public static boolean solve() {
        if (isDebug) {
            // Si es debug significa que estamos probando el programa
            tamX = rand.nextInt(100) + 1; 
            tamY = rand.nextInt(100) + 1;
            System.out.println("Solucion: " + tamX + " " + tamY);
        } else{
            // Si no es debug significa que estamos en el juez
            tamX = in.nextInt();
            tamY = in.nextInt();
        }
        
        // Si ambos son 0, terminamos
        if (tamX+tamY == 0) return false;
        
        // Llamamos a la funcion que hace la busqueda binaria en los dos ejes
        // Sumamos uno a la cantidad de pruebas para que cuando llegue a 10, termine en el caso de estar en modo debug
        Pair result = binarySearch(tamX, tamY);
        System.out.println("=> " + result.first + " " + result.second);
        
        if (isDebug) {
            cantidadDePruebas++;
            return cantidadDePruebas < 10;
        }
        return true;
    }

    public static void main(String[] args) throws FileNotFoundException {
        in = new Scanner(System.in);
        while (solve());
        in.close();
    }
}