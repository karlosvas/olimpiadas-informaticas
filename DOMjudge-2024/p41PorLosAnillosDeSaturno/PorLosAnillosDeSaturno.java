package p41PorLosAnillosDeSaturno;

import java.util.*;
import java.io.*;

public class PorLosAnillosDeSaturno {
    // Representa cada conexión en un anillo: 
    // 'degree' es el grado destino y 'ring' el anillo destino.
    static class Edge {
        int degree, ring;
        Edge(int degree, int ring) {
            this.degree = degree;
            this.ring = ring;
        }
    }

    // Representa un estado en Dijkstra: costo acumulado, anillo y grado actual.
    static class State implements Comparable<State> {
        int dist, ring, degree;
        State(int dist, int ring, int degree) {
            this.dist = dist;
            this.ring = ring;
            this.degree = degree;
        }
        public int compareTo(State other) {
            return Integer.compare(this.dist, other.dist);
        }
    }

    static final int INF = 1000000000;

    // Lista de anillos: cada anillo es una lista de conexiones ("edges")
    static ArrayList<ArrayList<Edge>> rings;
    // Tiempos de movimiento en cada anillo
    static int[] tiempos;

    // Dijkstra: d, g es origen (anillo y grado) y e, h es destino
    static int dijkstra(int d, int g, int e, int h, int N) {
        int[][] dist = new int[N][360];
        for (int i = 0; i < N; i++) {
            Arrays.fill(dist[i], INF);
        }
        dist[d][g] = 0;
        PriorityQueue<State> pq = new PriorityQueue<>();
        pq.add(new State(0, d, g));

        while (!pq.isEmpty()) {
            State cur = pq.poll();
            int curDist = cur.dist;
            int v = cur.ring, gv = cur.degree;

            if(curDist > dist[v][gv])
                continue;

            for (Edge edge : rings.get(v)) {
                int gw = edge.degree; // grado destino
                int w = edge.ring;    // anillo destino
                int diff = Math.abs(gv - gw);
                int angleDist = Math.min(diff, 360 - diff); // distancia angular mínima
                int additional = angleDist * tiempos[v];    // costo de moverse en el anillo v

                if (dist[v][gv] + additional < dist[w][gw]) {
                    dist[w][gw] = dist[v][gv] + additional;
                    pq.add(new State(dist[w][gw], w, gw));
                }
            }
        }
        return dist[e][h];
    }

    static void solve(Scanner in) {
        // Leemos: N = número de anillos, K = número de túneles
        int N = in.nextInt(), K = in.nextInt();

        // Inicializamos los anillos; cada anillo es una lista de conexiones (edges)
        rings = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            rings.add(new ArrayList<Edge>());
        }

        // Leemos los túneles: cada túnel conecta dos anillos adyacentes con un grado asociado
        for (int k = 0; k < K; k++) {
            int a = in.nextInt(), b = in.nextInt();
            a--; // Convertimos a 0-indexed
            // Agregamos el túnel en ambos sentidos: 
            // del anillo a al anillo a+1 y viceversa
            rings.get(a).add(new Edge(b, a + 1));
            rings.get(a + 1).add(new Edge(b, a));
        }

        // Leemos los tiempos de recorrido en cada anillo
        tiempos = new int[N];
        for (int n = 0; n < N; n++) {
            tiempos[n] = in.nextInt();
        }

        // Leemos el anillo y grado de origen y destino
        int d = in.nextInt(), g = in.nextInt(), e = in.nextInt(), h = in.nextInt();
        d--; // Convertimos origen a 0-indexed
        e--;

        // Conectamos la salida y la entrada como si fuera un túnel
        rings.get(e).add(new Edge(h, e));
        rings.get(d).add(new Edge(g, d));

        int cost = dijkstra(d, g, e, h, N);
        if (cost == INF)
            System.out.println("IMPOSIBLE");
        else
            System.out.println(cost);
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        while (T-- > 0)
            solve(in);
    }
}