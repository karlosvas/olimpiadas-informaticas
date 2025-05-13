package p88PrimoDeRiesgo;

import java.io.FileNotFoundException;
import java.util.Scanner;

public class PrimoDeRiesgo {
    static Scanner in;

    // Función que verifica si el numero dado es primo
    public static boolean esPrimo(long i){
        if (i < 2) {
            return false;
        } else if (i == 2) {
            return true;
        }
        // Vemos que número multiplicado por si mismo es menor o igual a el nuemro dadno, ya que no hay ningun divisor mas aya de la raiz cuadrada de el numero dado
        // Para hacerlo mas eficiente recorremos los imapres, y devolbemos false si no es primo, y true si lo es
        int z = 3;
        while(z*z <= i){
            if(i%z==0) return false;
            z+=2;
        }
        return true;
    }

    public static boolean solve() {
        // Obtenemos el valor ascci de la cadena, al empezar en -1 empezamos desde ese nuemro -1
        String letter;
        letter = in.nextLine();

        long sum = -1;
        for (char c : letter.toCharArray()) 
            sum += (int) c;

        // Si es par lo descartamos
        if(sum % 2 == 0) sum--;

        // Buscamos desde ese numero en valores inferiores a el para obtener su primo inferior mas cercano
        for (long i = sum; i >= 3; i-=2) {
            if(esPrimo(i)) {
                System.out.println(i);
                break;
            }
        }
        
        return true;
    }

    public static void main(String[] args) throws FileNotFoundException {
        boolean isDebug = false;
        if (isDebug)
            in = new Scanner(new java.io.File("DOMjudge-2024/p88PrimoDeRiesgo/input.txt"));
        else
            in = new Scanner(System.in);

        int N;
        N = in.nextInt();
        while (N-- >= 0){
            solve();
        };

        in.close();
    }
}