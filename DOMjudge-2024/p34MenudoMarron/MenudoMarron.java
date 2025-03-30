package p34_MenudoMarron;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class MenudoMarron {
    // Mapa de adyacencia
    private static Map<Integer, List<Integer>> adjacencyMap;

    // Nodos visitados
    private static Map<Integer, Boolean> visited;

    // Array de supermercados con el precio del papel
    private static Map<Integer, Integer> suppermarket;

    // Mínimo valor de papel en cada componente conexa
    private static int min = Integer.MAX_VALUE;

    // DFS Depth First Search, recorrido en profundidad
    private static void dfs(Integer start) {
        // Si ya hemos visitado el nodo, no hacemos nada
        if (visited.getOrDefault(start, false))
            return;

        // Actualizamos el precio del papel antes de marcar el nodo como visitado
        if (suppermarket.getOrDefault(start, Integer.MAX_VALUE) != Integer.MAX_VALUE)
            min = Math.min(suppermarket.get(start), min);

        // Marcamos el nodo como visitado y actualizamos el precio del papel
        visited.put(start, true);

        for (Integer neighbor : adjacencyMap.get(start))
            if (!visited.get(neighbor))
                dfs(neighbor);
        // Cuando visitó todos los nodos de la componente, actualizamos el precio del
        // papel en la componente conexa
        suppermarket.put(start, min);
    }

    public static boolean solve(BufferedReader br, BufferedWriter bw) throws IOException {
        String line;
        if ((line = br.readLine()) == null || line.isEmpty())
            return false;

        String lines[] = line.split(" ");
        // Puntos en la ciudad calles (n)
        int n = Integer.parseInt(lines[0]);
        // Calles en la ciudad (c)
        int c = Integer.parseInt(lines[1]);

        // Inicializamos el mapa de adyacencia y los nodos visitados para el dfs
        // Inicializamos los supermercados con el precio del papel en cada ciudad
        adjacencyMap = new HashMap<>(n);
        visited = new HashMap<>(n);
        suppermarket = new HashMap<>(n);
        for (int i = 0; i < n; i++) {
            visited.put(i, false);
            adjacencyMap.put(i, new ArrayList<>());
            suppermarket.put(i, Integer.MAX_VALUE);
        }

        for (int i = 0; i < c; i++) {
            // Dos puntos en la ciudad de doble sentido
            String[] parts = br.readLine().split(" ");
            int a = Integer.parseInt(parts[0]) - 1;
            int b = Integer.parseInt(parts[1]) - 1;
            // Añadimos las aristas en ambas direcciones (grafo bidireccional)
            adjacencyMap.get(a).add(b);
            adjacencyMap.get(b).add(a);
        }

        // Puntos en la ciudad donde comprar papel(s)
        int s = Integer.parseInt(br.readLine());
        for (int i = 0; i < s; i++) {
            // Actualizamos aquellos supermercados que venden papel con su precio
            String[] info = br.readLine().split(" ");
            suppermarket.put(Integer.parseInt(info[0]) - 1, Integer.parseInt(info[1]));
        }

        // Posiciones de los compradores en búsqueda de su supermercado mas barato(k)
        int k = Integer.parseInt(br.readLine());
        // Recorremos cada componente conexa
        for (int i = 0; i < n; i++) {
            if (!visited.get(i)) {
                min = Integer.MAX_VALUE;
                dfs(i);
            }
        }

        // Recorremos los compradores y mostramos el precio del papel en el supermercado
        // mas barato de los que tienen acceso
        String[] ki = br.readLine().split(" ");
        for (int i = 0; i < k; i++) {
            int x = Integer.parseInt(ki[i]) - 1;
            if (suppermarket.get(x) == Integer.MAX_VALUE)
                bw.write("MENUDO MARRON\n");
            else
                bw.write(suppermarket.get(x) + "\n");
        }

        bw.write("---\n");
        return true;
    }

    public static void main(String[] args) throws IOException {
        boolean isDebug = true;
        BufferedReader br;
        BufferedWriter bw;
        if (isDebug) {
            br = new BufferedReader(new java.io.FileReader("DOMjudge-2024/MenudoMarron34/input.txt"));
            bw = new BufferedWriter(new java.io.FileWriter("DOMjudge-2024/MenudoMarron34/output.txt"));
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
