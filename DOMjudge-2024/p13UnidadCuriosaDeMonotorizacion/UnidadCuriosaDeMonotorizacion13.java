package p13UnidadCuriosaDeMonotorizacion;

import java.util.PriorityQueue;
import java.util.Comparator;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Registro {
    int id;
    int periodo;
    int momento;

    public Registro(int id, int periodo, int momento) {
        this.id = id;
        this.periodo = periodo;
        this.momento = momento;
    }
}

public class UnidadCuriosaDeMonotorizacion13 {
    public static boolean solve(BufferedReader br) throws IOException {
        // Casos de prueba (N)
        int N = Integer.parseInt(br.readLine().trim());
        
        if (N == 0) return false;

        // Implementa el Comparator usando una expresión lambda
        Comparator<Registro> registroComparator = (a, b) -> {
            if (a.momento != b.momento) {
                return Integer.compare(a.momento, b.momento);
            } else {
                return Integer.compare(a.id, b.id);
            }
        };

        // Crea la PriorityQueue con el Comparator
        PriorityQueue<Registro> pq = new PriorityQueue<>(registroComparator);

        // Leer los registros de los usuarios
        for (int i = 0; i < N; i++) {
            String[] parts = br.readLine().trim().split(" ");
            int id = Integer.parseInt(parts[0]);
            int periodo = Integer.parseInt(parts[1]);
            pq.add(new Registro(id, periodo, periodo));
        }
        
        // Momentos en los que se envían las alertas (K)
        int k = Integer.parseInt(br.readLine().trim());

        // Usar StringBuilder para acumular los resultados y luego imprimirlos de una vez
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < k; i++) {
            if (pq.isEmpty()) break;
            // Obtenemos el registro con el momento más pequeño y lo mostramos
            Registro r = pq.poll();
            sb.append(r.id).append("\n");
            // Actualizamos el momento del registro y lo añadimos a la cola
            r.momento += r.periodo;
            pq.add(r);
        }

        // Imprimir todos los resultados de una vez
        System.out.print(sb.toString());
        System.out.println("---");
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (solve(br));
    }
}