package p38RapidEats;

import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

public class p38RapidEats {
    static Scanner in;

    private static class Node {
        int vertex;
        int distance;

        public Node(int vertex, int distance) {
            this.vertex = vertex;
            this.distance = distance;
        }
    }

    static int dijkstra(List<List<Node>> graph, int start, int end) {
        int V = graph.size();
        int[] dist = new int[V];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[start] = 0;
        
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        pq.add(new int[]{0, start}); 

        while (!pq.isEmpty()) {
            int[] current = pq.poll();
            int d = current[0], node = current[1];

            if (d > dist[node]) continue; 

            for (Node edge : graph.get(node)) {
                int newDist = d + edge.distance;
                if (newDist < dist[edge.vertex]) {
                    dist[edge.vertex] = newDist;
                    pq.add(new int[]{newDist, edge.vertex});
                }
            }
        }
        return dist[end];
    }

    

    public static boolean solve() {
        if (!in.hasNextInt()) return false;
        
        // Número de puntos de recarga/recojida/entrega (N)
        int N = in.nextInt();
        // Número de tramos de calles entre puntos (C)
        int C = in.nextInt();

        // Creamos el grafo con los puntos y las calles
        List<List<Node>> G = new ArrayList<>();
        for (int i = 0; i < N; i++) G.add(new ArrayList<>());


        for (int i = 0; i < C; i++) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1; 
            int t = in.nextInt();
            G.get(a).add(new Node(b, t));
            G.get(b).add(new Node(a, t));
        }
        
        // Número de preguntas(K)
        int K = in.nextInt();
        for (int i = 0; i < K; i++) {
            // Origen (origen) y destino (destino) de la pregunta
            int origen = in.nextInt() - 1;
            int destino = in.nextInt() - 1;

            int sol = dijkstra(G, origen, destino);

            // Si hay camino lo imprimimos, si no lo hay imprimimos "NO LLEGA"
            if(sol != Integer.MAX_VALUE){
                System.out.println(sol);
            } else {
                System.out.println("NO LLEGA");
            }
        }

        System.out.println("---");
        return true;
    }

    public static void main(String[] args) throws FileNotFoundException {
        boolean isDebug = false;
        if (isDebug)
            in = new Scanner(new java.io.File("DOMjudge-2024/p38RapidEats/input.txt"));
        else
            in = new Scanner(System.in);
        while (solve());

        in.close();
    }
}
