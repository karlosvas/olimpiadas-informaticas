package p21ColocarLosGuardias;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

// Clase Pair para almacenar si un nodo ha sido visitado y su color
class Pair {
    boolean visited;
    Boolean color;

    Pair(boolean visited, Boolean color) {
        this.visited = visited;
        this.color = color;
    }
}

public class ColocandoGuardias21 {
    static Pair[] boleans; // Array de white para almacenar el estado de visitado y el color de cada nodo
    static ArrayList<Set<Integer>> g; // Lista de adyacencia para representar el grafo
    static int white = 0; // Contador de nodos con color true (white)
    static int black = 0; // Contador de nodos con color false (black)

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        while (solve(br, bw))
            ;
        bw.flush();
    }

    public static boolean solve(BufferedReader br, BufferedWriter bw) throws IOException {
        String line;
        if ((line = br.readLine()) == null || line.isEmpty())
            return false;

        // Cruces (N), Calles (C)
        int N = Integer.parseInt(line); // Número de nodos
        int C = Integer.parseInt(br.readLine()); // Número de aristas

        g = new ArrayList<>(N);
        for (int i = 0; i < N; i++)
            g.add(new HashSet<>());

        for (int i = 0; i < C; i++) {
            String[] input = br.readLine().trim().split(" ");
            int a = Integer.parseInt(input[0]) - 1;
            int b = Integer.parseInt(input[1]) - 1;
            // Añade las aristas al grafo
            g.get(a).add(b);
            g.get(b).add(a);
        }

        boleans = new Pair[N]; // Inicializamos el array de white
        // Todos no estan visitados y sin color asignado
        for (int i = 0; i < N; i++)
            boleans[i] = new Pair(false, null);

        int minmo_conexas = 0; // Contador para el mínimo de componentes conexas
        // Visitamos todas las componentes conexas y sumamos los resultados
        for (int i = 0; i < N; i++) {
            if (!boleans[i].visited) {
                // Reinicia el contador de nodos
                white = 0;
                black = 0;

                if (!dfs(i, true)) {
                    // Si no es bipartito, imprime "IMPOSIBLE" y termina
                    bw.write("IMPOSIBLE\n");
                    return true;
                } else {
                    // Suma el mínimo de nodos white o black en la componente conexa
                    minmo_conexas += Math.min(white, black);
                }
            }
        }

        // Imprime el resultado
        bw.write(minmo_conexas + "\n");

        return true;
    }

    // Función DFS para verificar si el grafo es bipartito
    public static boolean dfs(int v, boolean parity) {
        // Marca el nodo como visitado asigna el color al nodo
        boleans[v].visited = true;
        boleans[v].color = parity;

        // Incrementa el contador de el color de los nodos
        if (parity)
            white++;
        else
            black++;

        // Recorre los nodos adyacentes
        for (int w : g.get(v)) {
            // Si el nodo adyacente tiene el mismo color, no es posible
            if (boleans[w].color == boleans[v].color)
                return false;
            if (!boleans[w].visited) {
                // Si el nodo adyacente no ha sido visitado, realiza DFS en él con el color
                // opuesto
                if (!dfs(w, !parity))
                    return false;
            }
        }
        // Si no hay conflictos de color, el grafo es bipartito
        return true;
    }
}