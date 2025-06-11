package p14ReinaDelSuper;

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.Comparator;


class Caja {
    int id; // Identificador de la caja osea su posición
    int momento; // Momento en el que se atenderá al siguiente cliente

    public Caja(int id, int momento) {
        this.id = id;
        this.momento = momento;
    }
}


public class ReinaDelSuper14 {
    public static boolean solve(BufferedReader br) throws IOException {
        // Leer la línea completa y dividirla en partes
        String[] parts = br.readLine().trim().split(" ");
        // Numero de cajas(N) y numero de clientes(C)
        int N = Integer.parseInt(parts[0]);
        int C = Integer.parseInt(parts[1]);

        if (N + C == 0) return false;

        // Implementa el Comparator usando una expresión lambda
        Comparator<Caja> registroComparator = (a, b) -> {
            if (a.momento != b.momento) {
                // Si los tiempos son diferentes elije el de menor momento
                return Integer.compare(a.momento, b.momento);
            } else {
                // Si los tiempos son iguales elije la caja mas cercana
                return Integer.compare(a.id, b.id);
            }
        };

        // Crea la PriorityQueue con el Comparator
        PriorityQueue<Caja> pq = new PriorityQueue<>(registroComparator);

        // Si hay mas clientes que cajas tiene que esperar dos turnos por lo que inicaializamos el tiempo en 0 todas las cajas
        for (int i = 1; i <= N; i++) {
            pq.add(new Caja(i, 0));
        }

        String[] tiempo = br.readLine().trim().split(" ");
        for (int i = 1; i <= C; i++) {
            // Número de segundos que trada el cliente en ser atendido
            int T = Integer.parseInt(tiempo[i-1]);
            // De la mejor opción esperamos a que se quede libre y lo volbemos a añadir por si hubiera mas clientes que cajas,
            // para que le toque al siguiente pero no a nosotros ua que hay mas clientes esperando
            Caja cliente = pq.poll();
            cliente.momento += T;
            pq.add(cliente);
        }

        // Mostramos el top de la cola, que es la primera caja que se quedará libre
        System.out.println(pq.poll().id);

        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (solve(br));
    }
}