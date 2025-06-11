package p28HaciendoTrampasEnSerpientesYEscaleras;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;

public class HaciendoTrapmasEnSerpientesYEscaleras28 {
    // Tablero
    static int[] board;

    // BFS implicito
    static public int bfs(int O, int D, int K) {
        // Vector de diatancias -1 si no se ha alcanzado
        int[] dist = new int[D];
        for (int i = 0; i < D; i++)
            dist[i] = -1;
        // Desde el origen la distancia es 0
        dist[O] = 0;

        // Creamos una cola para ir visitando los nodos, y añadimos el nodo de origen
        Queue<Integer> q = new LinkedList<>();
        q.add(O);

        while (!q.isEmpty()) {
            // Obtenemos el primer elemento de la cola
            int v = q.poll();
            // Lanzamos el dado [1, K] veces desde v
            for (int i = 1; i <= K; i++) {
                // Nodo al que llegamos (w)
                int w = board[v + i];
                // Si no esta visitado y es menor que D ya que el final es N*N-1, entonces lo
                // visitamos
                if (dist[w] == -1 && w < D) {
                    // La distancia es la distancia del nodo anterior + 1
                    dist[w] = dist[v] + 1;
                    // Si hemos llegado al final retornamos la distancia, si no añadimos el nodo a
                    // la cola de nodos pendientes
                    if (w == D - 1)
                        return dist[w];
                    else
                        q.add(w);
                }
            }
        }

        // Si no hemos llegado al final retornamos -1
        return -1;
    }

    public static boolean solve(BufferedReader br, BufferedWriter bw) throws IOException {
        String[] input = br.readLine().trim().split(" ");
        // Dimension del tablero (N)
        int N = Integer.parseInt(input[0]);
        // Caras del dado (K)
        int K = Integer.parseInt(input[1]);
        // Numero de serpientes (S)
        int S = Integer.parseInt(input[2]);
        // Numero de escaleras (E)
        int E = Integer.parseInt(input[3]);

        if (N + K + S + E == 0)
            return false;

        // Creamos un tablero de N casillas
        board = new int[N * N];
        for (int i = 0; i < N * N; i++)
            board[i] = i;

        // Leemos las serpientes y escaleras
        for (int i = 0; i < E + S; i++) {
            String[] line = br.readLine().trim().split(" ");
            int a = Integer.parseInt(line[0]);
            int b = Integer.parseInt(line[1]);
            a--;
            b--;
            board[a] = b;
        }

        // Origen, Destino, Caras del dado, llamamos a bfs implictito con esos datos y
        // lo mostramos
        bw.write(bfs(0, N * N, K) + "\n");

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