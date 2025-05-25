package p12CojeElSobreYCorre;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class CojeElSobreYCorre {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (solve(sc));
    }

    public static boolean solve(Scanner sc) {
        // Numero de sobres que guarda en el cajon 1 < n < 500.000
        int n = sc.nextInt();
        // Numero de sobres que tiene que cojer para ir a la cena 1 < k < n
        int k = sc.nextInt();

        if (k + n == 0) return false;

        // Cola de sobres que guarda en el cajon ordenados por llegada
        Deque<Integer> dq = new ArrayDeque<>();
        // Mejor sobre que ha visto en ese rango
        Deque<Integer> best = new ArrayDeque<>();

        for (int i = 0; i < k; i++) {
            int actual = sc.nextInt();
            // Añadimos el nuevo
            dq.addLast(actual);
            // Si no esta vacio y el ultimo intoducido es menor que el actual, vamos eliminandolos
            while (!best.isEmpty() && best.peekLast() < actual) {
                best.removeLast();
            }
            best.addLast(actual);
        }
        System.out.print(best.peekFirst());

        for (int i = k; i < n; i++) {
            int actual = sc.nextInt();
            // Añadimos el nuevo a el rango de saobres a elegir
            dq.addLast(actual);

            // Si el primero de los que estan en rango es igual a el primer mejor, lo eliminamos
            // porque ya no esta en rango
            if (dq.peekFirst().equals(best.peekFirst())) {
                best.removeFirst();
            }

            // Quitamos el primero de la cola, viejo porque ya no esta en el rango de sobres a elegir
            dq.removeFirst();

            // Si no esta vacio y el ultimo intoducido es menor que el actual, vamos eliminandolos
            while (!best.isEmpty() && best.peekLast() < actual) {
                best.removeLast();
            }
            best.addLast(actual);

            // Mostramos el mejor sobre actual
            System.out.print(" " + best.peekFirst());
        }

        System.out.println();
        return true;
    }
}