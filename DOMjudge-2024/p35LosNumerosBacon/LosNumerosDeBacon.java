package LosNumerosBacon35;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Set;

public class LosNumerosDeBacon {
    // Vectopr de dist
    public static Map<String, Integer> dist;

    // BFS Busqueda en anchura, Breadth First Search, , para encontrar la distancia
    // de Kevin Bacon
    static int bfs(Map<String, Set<String>> adj, String actorInicio) {
        // Cola de actores (q), y mapa de distancias (dist)
        Queue<String> q = new LinkedList<>();
        dist = new HashMap<>();

        // Añadimos el actor de inicio a la cola y su distancia a 0
        q.add(actorInicio);
        dist.put(actorInicio, 0);

        // Mientras la cola no esté vacía seguimos buscando actores
        while (!q.isEmpty()) {
            String curr = q.poll();

            // Para cada actor conectado, le damos su distancia y lo añadimos a la cola
            for (String vecino : adj.getOrDefault(curr, new HashSet<>())) {
                // Si no hemos visitado este actor
                if (!dist.containsKey(vecino)) {
                    dist.put(vecino, dist.get(curr) + 1);
                    q.add(vecino);
                }
            }
        }

        // Si no encontramos camino
        return Integer.MAX_VALUE;
    }

    public static boolean solve(BufferedReader br, BufferedWriter bw) throws IOException {
        String line;
        if ((line = br.readLine()) == null || line.isEmpty())
            return false;

        // Peliculas(p)
        int P = Integer.parseInt(line);

        // Grafo de actores
        Map<String, Set<String>> g = new HashMap<>();

        for (int i = 0; i < P; i++) {
            // Título y número de actrices
            String[] parts = br.readLine().split(" ");
            // Título (title), no es necesario
            // String title = parts[0];

            // Número de actores y actrices (n)
            int n = Integer.parseInt(parts[1]);
            Set<String> actors = new HashSet<>(n);

            // Obtenemos todos los actores y los guardamos en una lista
            for (int j = 2; j < n + 2; j++)
                actors.add(parts[j]);

            // Para cada actor, generamos un set de adyacencia de actores, si ya tiene
            // uno lo añadimos a la lista de actores previos
            for (String actor : actors)
                g.computeIfAbsent(actor, k -> new HashSet<>()).addAll(actors);
        }

        // Hacer BFS para encontrar la distancia de Kevin Bacon
        bfs(g, "KevinBacon");

        // Número de actores a buscar(N)
        int N = Integer.parseInt(br.readLine());
        for (int j = 0; j < N; j++) {
            // Actor a buscar su distancia con KevinBacon(actorToBacon)
            String actorToBacon = br.readLine();

            // Si no encontramos camino a Kevin Bacon mostramos INF, si nno mostramos la
            // distancia a el
            int baconNumber = dist.getOrDefault(actorToBacon, Integer.MAX_VALUE);
            if (baconNumber == Integer.MAX_VALUE)
                bw.write(actorToBacon + " INF\n");
            else
                bw.write(actorToBacon + " " + baconNumber + "\n");
        }

        bw.write("---\n");
        return true;
    }

    public static void main(String[] args) throws IOException {
        boolean isDebug = false;
        BufferedReader br;
        BufferedWriter bw;
        if (isDebug) {
            br = new BufferedReader(new java.io.FileReader("DOMjudge-2024/LosNumerosBacon35/input.txt"));
            bw = new BufferedWriter(new java.io.FileWriter("DOMjudge-2024/LosNumerosBacon35/output.txt"));
        } else {
            br = new BufferedReader(new InputStreamReader(System.in));
            bw = new BufferedWriter(new OutputStreamWriter(System.out));
        }
        while (solve(br, bw))
            ;
        bw.flush();
        bw.close();
        br.close();
    }
}