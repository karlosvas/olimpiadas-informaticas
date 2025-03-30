import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.PriorityQueue;

public class LasPartiturasDeLaOrquesta16 {
    public class Pair {
        int musicos, partituras;

        Pair(int musicos, int partituras) {
            this.musicos = musicos;
            this.partituras = partituras;
        }

        // Musicos entre las partituras más el resto, utilizando ceil para redondear
        // hacia arriba
        int maxMusiciansPerAtril() {
            return (int) Math.ceil((double) musicos / partituras);
        }
    }

    public static boolean solve(BufferedReader br) throws IOException {
        String line;
        if ((line = br.readLine()) == null || line.isEmpty())
            return false;

        // Número de partitura que podemos comparar (p), numero de intrumentos
        // diastintos (n)
        // Almenos una partitura por cada tipo de instrumento
        String parts[] = line.trim().split(" ");
        int p = Integer.parseInt(parts[0]);
        int n = Integer.parseInt(parts[1]);

        // Implementamos un PriorityQueue para llevar un seguimiento de los atriles mas
        // conpartidos, tiene mas priioridad el atril con mas músicos entre partituras
        // osea el mas compartido
        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> b.maxMusiciansPerAtril() - a.maxMusiciansPerAtril());

        // Cantidad de partituras sin asignar a un instrumento y por lo que devemos
        // repartir
        int musicos;
        String m[] = br.readLine().trim().split(" ");
        for (int i = 0; i < n; i++) {
            // Cantidad de musicos tocando ese (n) instrumento <= 1000
            musicos = Integer.parseInt(m[i]);
            Pair pair = new LasPartiturasDeLaOrquesta16().new Pair(musicos, 1);
            pq.add(pair);
        }

        // Se garantiza que p => n
        // Obtenemos el resto de partituras que no se han asignado
        p -= n;
        // Siempre que se pueda repartir más partituras lo repartiremos en el atril mas
        // compartido para buscar asi la mayor disperión de musicos en atriles
        while (p-- > 0) {
            Pair max = pq.poll();
            // Accedemos a la cantidad de musicos que se encuentran en el atril mas
            // compartido para repartir las partituras sobrantes
            max.partituras++;
            pq.add(max);
        }

        // Número de músicos que se agaloparan en el atril mas conpartido, minimazando
        // la cantidad de gente
        Pair max = pq.poll();
        System.out.println(max.maxMusiciansPerAtril());
        return true;
    }

    public static void main(String[] args) throws IOException {
        // Usamos BufferedReader y StringBuilder para mejorar la eficiencia
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (solve(br))
            ;
    }
}

// Antigua implementación
// if (max % 2 == 0) {
// // Ejemplo 8/2 = 4 y 4
// pq.add(max / 2);
// pq.add(max / 2);
// } else {
// // Ejemplo 5/2 = 2 y 3
// pq.add(max / 2);
// pq.add((max / 2) + 1);
// }