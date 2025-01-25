import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class RatonesEnUnLaberinto {
    // Clase del grafo
    static class Graph<T> {
        // Nodos adyacentes
        private Map<T, Map<T, Integer>> adjacencyMap;

        // Constructor
        public Graph() {
            this.adjacencyMap = new HashMap<>();
        }

        // Añadir un vertice y una arista
        public void addVertex(T vertex) {
            adjacencyMap.putIfAbsent(vertex, new HashMap<>());
        }

        public void addEdge(T source, T destination, int weight) {
            adjacencyMap.get(source).put(destination, weight);
        }

        // Encontrar el camino mínimo desde un nodo a todos los demas
        public Map<T, Integer> findAllShortestPaths(T start) {
            // Creamos un vector de distancias una cola de prioridad de nodos
            Map<T, Integer> distances = new HashMap<>();
            PriorityQueue<Node<T>> pq = new PriorityQueue<>((a, b) -> Integer.compare(a.distance, b.distance));

            // Inicializamos las distancias a un valor alto
            for (T vertex : adjacencyMap.keySet())
                distances.put(vertex, Integer.MAX_VALUE);

            // Para llegar a el mismo hay distancia 0
            distances.put(start, 0);
            pq.offer(new Node<>(start, 0));

            while (!pq.isEmpty()) {
                // Obtenemos los nodos o ratones con los que está conectado por aristas
                Node<T> current = pq.poll();
                T currentVertex = current.vertex;

                // Si la ditancia actual es mayor no encontraremos mejor camino
                if (current.distance > distances.get(currentVertex))
                    continue;

                // Recorremos todos sus adyacentes para agregarlos a la cola
                for (Map.Entry<T, Integer> neighbor : adjacencyMap.get(currentVertex).entrySet()) {
                    T nextVertex = neighbor.getKey(); // Nodo vecino
                    int weight = neighbor.getValue(); // Peso

                    // Si no está viistado es el mejor camino
                    // Si la nueva sitancia es mejor que la que tenemos almacenada actulizamos
                    int newDistance = distances.get(currentVertex) + weight;
                    if (newDistance < distances.get(nextVertex)) {
                        distances.put(nextVertex, newDistance);
                        pq.offer(new Node<>(nextVertex, newDistance));
                    }
                }
            }
            // Devolbemos el map de distancias
            return distances;
        }

        // Clase de nodo donde amacenamos los nodos en un grafo con distinta informacion
        // implementa comparable para poder comparar entre dos distancias
        private static class Node<T> {
            T vertex;
            int distance;

            Node(T vertex, int distance) {
                this.vertex = vertex;
                this.distance = distance;
            }
        }
    }

    public static boolean solve(BufferedReader br, BufferedWriter bw) throws IOException {
        String line;
        if ((line = br.readLine()) == null || line.isEmpty())
            return false;
        String[] parts = line.split(" ");

        // Número de celdas (n), número de salida(s), número de segundos(t),
        // pasadizos(p)
        int n = Integer.parseInt(parts[0]);
        int s = Integer.parseInt(parts[1]);
        s--; // Convertir a indice 0-base
        int time = Integer.parseInt(parts[2]);
        int p = Integer.parseInt(parts[3]);

        // Creamos le grafo y le asiganamos los vertices
        Graph<Integer> g = new Graph<>();
        for (int i = 0; i < n; i++)
            g.addVertex(i);

        // Leemos los pasadizos en base 0, añadimos los verices de forma inversa a la
        // entrada ya que queremos saber el enor camino desde la salida a cualquier nodo
        for (int i = 0; i < p; i++) {
            parts = br.readLine().split(" ");
            int a = Integer.parseInt(parts[0]) - 1;
            int b = Integer.parseInt(parts[1]) - 1;
            int sec = Integer.parseInt(parts[2]);
            g.addVertex(a);
            g.addVertex(b);
            g.addEdge(b, a, sec);
        }

        // Utilizamos la función necesaria utilizando Dijkstra para encontrar el minimo
        // camino a todos desde la salida
        Map<Integer, Integer> shortestPath = g.findAllShortestPaths(s);

        // Contamos cuantos de ellos podrían haber salido, ya que si el caminimo mínimo
        // a la salida es menor o igual a el tiempo, significa que podrían haber salido
        int count = 0;
        if (shortestPath != null) {
            for (int i = 0; i < shortestPath.size(); i++) {
                if (shortestPath.get(i) <= time)
                    count++;
            }
        }

        // Mostramos el resultado restando menos uno, ya que es el mismo
        bw.write((count - 1) + "\n");
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