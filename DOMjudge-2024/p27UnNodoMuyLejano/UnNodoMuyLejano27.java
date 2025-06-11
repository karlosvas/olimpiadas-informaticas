package p27UnNodoMuyLejano;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class UnNodoMuyLejano27 {
    // Grafo explicito
    private static List<List<Integer>> g;

    // Recorrido en anchura (BFS) para encontrar los nodos a los que no se puede
    // llegar desde un origen con un TTL dado
    public static int bfs(int origen, int TTL) {
        // Vector de distancias inicualizadfo a -1 si no hemos llegado a ese nodo
        int[] dist = new int[g.size()];
        for (int i = 0; i < g.size(); i++)
            dist[i] = -1;
        dist[origen] = 0;

        // Creamos una cola para el recorrido en anchura y añadimos el nodo origen
        Queue<Integer> q = new LinkedList<>();
        q.add(origen);

        while (!q.isEmpty()) {
            // Sacamos el nodo superiror de la cola y buscamos su adyacentes
            int v = q.poll();
            for (int w : g.get(v)) {
                // SI no esta visitado lo visitamo
                if (dist[w] == -1) {
                    dist[w] = dist[v] + 1;
                    q.add(w);
                }
            }
        }

        // Contamos los nodos a los que no hemos llegado
        int count = 0;
        for (int i = 0; i < g.size(); i++) {
            // Si su distancia es mayor al TTL o no hemos llegado a el
            if (dist[i] > TTL || dist[i] == -1)
                count++;
        }

        // Retornamos el numero de nodos a los que no hemos llegado
        return count;
    }

    public static boolean solve(BufferedReader br, BufferedWriter bw) throws IOException {
        String line;
        if ((line = br.readLine()) == null || line.isEmpty())
            return false;

        // Numero de nodos en la red (N)
        int N = Integer.parseInt(line.trim());
        // Nuemro de conexiones (C)
        int C = Integer.parseInt(br.readLine());

        // Creamos un grafo con N nodos
        g = new ArrayList<>(N);
        for (int i = 0; i < N; i++)
            g.add(new ArrayList<>());

        // Leemos las conexiones
        for (int i = 0; i < C; i++) {
            String[] input = br.readLine().trim().split(" ");
            int a = Integer.parseInt(input[0]);
            int b = Integer.parseInt(input[1]);
            a--;
            b--;
            // Añadimos las conexiones al grafo
            g.get(a).add(b);
            g.get(b).add(a);
        }

        int K = Integer.parseInt(br.readLine());
        for (int i = 0; i < K; i++) {
            String[] input = br.readLine().trim().split(" ");
            // Nodo inicial(v), distancia maxima que puede recorrer (TTL)
            int v = Integer.parseInt(input[0]);
            int TTL = Integer.parseInt(input[1]);
            v--;
            // Buscamos los nodos a los que no podemos llegar y los escribimos
            bw.write(bfs(v, TTL) + "\n");
        }
        bw.write("---\n");

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