package p37CamionesDeReparto;

import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Scanner;

public class p37CamionesDeReparto {
    static Scanner in;
    public static boolean[] visited;
    public static ArrayList<ArrayList<Pair>> G;

    // Pares de datos
    public static class Pair {
        int node, weight;
        public Pair(int node, int weight) {
            this.node = node;
            this.weight = weight;
        }
    }

   // (DFS) Depth First Search
   public static void dfs(int v, int maxWidth) {
        visited[v] = true;
        for (Pair i : G.get(v)) {
            if (!visited[i.node] && i.weight >= maxWidth) {
                dfs(i.node, maxWidth);
            }
        }
    }

    public static boolean solve() {
        if (!in.hasNextInt()) return false;
        
       // Intersecciones (V)
       int V = in.nextInt();
       // Cales entre interseciones (E)
       int E = in.nextInt();

       // Grafo no dirijido bidireccional
       G = new ArrayList<>(V + 1);
       for (int i = 0; i <= V; i++) 
            G.add(new ArrayList<>()); 

       for (int i = 0; i < E; i++) {
            // Interseciones que hay en esa calle  (a, b)
            int a = in.nextInt();
            int b = in.nextInt();
            // Anchura máxima de la calle (w)
            int w = in.nextInt();

            // Añadimos la calle a la lista de adyacencia
            G.get(a).add(new Pair(b, w));
            G.get(b).add(new Pair(a, w));
        }

       // Consultas(k)
       int K = in.nextInt();
       

       for (int i = 0; i < K; i++) {
            int origen = in.nextInt();
            int destino = in.nextInt();
            int anchura = in.nextInt();

            visited = new boolean[V + 1];
            dfs(origen, anchura);
            
            if(visited[destino]) {
                System.out.println("SI");
            } else {
                System.out.println("NO");
            }
       }
       
       return true;
    }

    public static void main(String[] args) throws FileNotFoundException {
        boolean isDebug = false;
        if (isDebug)
            in = new Scanner(new java.io.File("DOMjudge-2024/p37CamionesDeReparto/input.txt"));
        else
            in = new Scanner(System.in);
        while (solve());

        in.close();
    }
}