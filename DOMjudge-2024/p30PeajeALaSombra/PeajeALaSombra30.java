package p30PeajeALaSombra;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class PeajeALaSombra30 {
    // Grafo de calles y sus intersecciones farolas
    private static List<List<Integer>> g;

    // BFS explicito para ecnontrar el mejor camino de a hasta t
    private static int[] bfs(int n, int c, int origen, int t) {
        // Distancia de la interseccion origen la interseccion t
        // Vector de distancias inicizaliadndo los no visitados a -1
        int[] dist = new int[n];
        Arrays.fill(dist, -1);

        // La distancia del origen es 0
        dist[origen] = 0;

        // Creamos una cola para ir recorriendo las intersecciones y calcular distancias
        Queue<Integer> q = new LinkedList<>();
        q.add(origen);

        while (!q.isEmpty()) {
            // Sacamos la interseccion de la cola
            int v = q.poll();
            for (int u : g.get(v)) {
                // Si no hemos pasado por la interseccion es el mejor camino
                if (dist[u] == -1) {
                    // Le añaadimos la distancia de la interseccion anterior + 1 que representa el
                    // pago de las farolas
                    dist[u] = dist[v] + 1;
                    q.add(u);
                }
            }
        }

        // Retornamos el vector de distancias que contendra el mejor camino a cada
        // interseccion
        return dist;
    }

    public static boolean solve(BufferedReader br, BufferedWriter bw) throws IOException {
        String line;
        if ((line = br.readLine()) == null || line.isEmpty())
            return false;
        String[] input = line.split(" ");
        // Interseciones en la ciudad(n)
        int n = Integer.parseInt(input[0]);
        // Calles en la ciudad(m)
        int c = Integer.parseInt(input[1]);
        // Casa de alex (a) y lucas (b)
        int a = Integer.parseInt(input[2]);
        int b = Integer.parseInt(input[3]);
        a--;
        b--;
        // Trabajo (t)
        int t = Integer.parseInt(input[4]);
        t--;

        // Creamos el un grafo que representa las interseciones entre ellas
        g = new ArrayList<>(n);
        for (int i = 0; i < n; i++)
            g.add(new ArrayList<>());

        // Leemos los intersecciones entre calles
        for (int i = 0; i < c; i++) {
            input = br.readLine().split(" ");
            int d = Integer.parseInt(input[0]);
            int e = Integer.parseInt(input[1]);
            d--;
            e--;
            g.get(d).add(e);
            g.get(e).add(d);
        }

        // Obtenemos los caminos de alex, luis y el trabajo
        int[] alex = bfs(n, c, a, t);
        int[] luis = bfs(n, c, b, t);
        int[] trabajo = bfs(n, c, t, t);

        // Calculamos el mejor camino entre alex, luis y el trabajo
        int best_path = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++)
            best_path = Math.min(best_path, alex[i] + luis[i] + trabajo[i]);

        bw.write(best_path + "\n");

        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        while (solve(br, bw))
            ;
        bw.flush();
        bw.close();
        br.close();
    }
}