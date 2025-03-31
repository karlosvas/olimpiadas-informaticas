package p39NavegandoSinTeclado;

import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Scanner;

public class p39NavegandoSinTeclado {
    static Scanner in;
    public static Map<Integer, Integer> times = new HashMap<>();

    // Clase para representar un nodo en el grafo, con su vertice y la distancia
    private static class Node {
        int vertex;
        int distance;

        public Node(int vertex, int distance) {
            this.vertex = vertex;
            this.distance = distance;
        }
    }

    // Implementación del algoritmo de Dijkstra para encontrar el camino más corto
    // entre dos nodos en un grafo dirigido
    static int dijkstra(List<List<Node>> graph, int start, int end) {
        // Inizalizamos el vector de distancias con el valor maximo posible
        int[] dist = new int[graph.size()];
        Arrays.fill(dist, Integer.MAX_VALUE);
        // LA distancia al origen es 0
        dist[start] = times.get(start);
        
        // COla de prioridad para que tengan prioridad las que menos tardan
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        pq.add(new int[]{times.get(start), start}); 

        while (!pq.isEmpty()) {
            // Obtenemos el nodo con la menor distancia
            int[] current = pq.poll();
            int d = current[0], node = current[1];
            
            // Si la distancia es mayor a la que tenemos guardada, lo ignoramos
            if (d > dist[node]) continue; 

            for (Node edge : graph.get(node)) {
                // La nueva distancia es la suma de la distancia actual mas lo que cuesta
                // encontrar ir a la siguiente pagina que seria la distancia, mas el 
                // tiempo que tarda en cargar la pagina
                int newDist = d + edge.distance + times.get(edge.vertex);
                if (newDist < dist[edge.vertex]) {
                    // ACtualiza el mejor camino si es menor que el actual
                    // y lo añade a la cola de prioridad
                    dist[edge.vertex] = newDist;
                    pq.add(new int[]{newDist, edge.vertex});
                }
            }
        }
        return dist[end];
    }

    public static boolean solve() {
        // Paginas manejadas (N)
        int N = in.nextInt();
        if(N == 0) return false;

        for (int n = 0; n < N; n++) {
            // Tiempo en milisegundos de cada pagina (t)
            int t = in.nextInt();
            times.put(n, t);
        }
        
        // Creamos un grafo dirigido ya que no se puede ir de una pagina a otra en ambas direcciones,
        // si no que solo de a a b
        List<List<Node>> G = new ArrayList<>();
        for (int i = 0; i < N; i++) 
            G.add(new ArrayList<>());

        // Numeros de enlaces en cada pagina (M)
        int M = in.nextInt();
        for (int m = 0; m < M; m++) {
            // Pagina en la que está (a)
            int a = in.nextInt() - 1;
            // Página a la que va (b)
            int b = in.nextInt() - 1;
            // Tiempo que tarda en ir de una a otra (t)
            int t = in.nextInt();
            G.get(a).add(new Node(b, t));
        }

        // Calculamos el tiempo mínimo para ir de la página 0 a la página N-1
        int sol = dijkstra(G, 0, N-1);
        
        if (sol != Integer.MAX_VALUE){
            // SI hay solucion la mostramos
            System.out.println(sol);
        } else {
            System.out.println("IMPOSIBLE");
        }

        
        return true;
    }

    public static void main(String[] args) throws FileNotFoundException {
        boolean isDebug = false;
        if (isDebug)
            in = new Scanner(new java.io.File("DOMjudge-2024/p38NavegandoSinTeclado/input.txt"));
        else
            in = new Scanner(System.in);
        while (solve());

        in.close();
    }
}