package p60_ElDesafioDeAleph;

import java.util.Scanner;

public class ElDesafioDeAleph60 {
    static Scanner in;

    // Preguntamos si es mayor o menos que el numero buscado
    public static boolean quest(int mid) {
        System.out.println("? " + mid);
        System.out.flush();
        return in.nextLine().equals("<=");
    }

    public static boolean solve() {
        // Rango en el que se encuetra el numero(N, M)
        int N = in.nextInt();
        int M = in.nextInt();
        in.nextLine();

        if(N + M == 0) return false;

        int left = N;
        int right = M;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // El número es <= mid, por lo que debe estar en [left, mid]
            // El número es > mid, por lo que debe estar en [mid+1, right]
            if (quest(mid)) right = mid - 1;
            else left = mid + 1;
        }

        // Mostramos el upperbound del numero buscado
        System.out.println("Respuesta: " + left);
        System.out.flush();
        return true;
    }

    public static void main(String[] args) {
        in = new Scanner(System.in);
        while (solve());
        in.close();
    }
}
