package p29LaRondaDeNoche;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class LaRondaDeNoche29 {
    private static char[][] g;
    private static int[] dx = { 1, 0, -1, 0 };
    private static int[] dy = { 0, 1, 0, -1 };
    private static int F, C;

    static class Pair {
        int f, c;

        Pair(int f, int c) {
            this.f = f;
            this.c = c;
        }
    }

    // Vista de los sensores de movimiento
    public static void floatfill(int f, int c, int K) {
        // Recorremos las 4 direcciones con una longitud de K
        for (int w = 0; w < 4; w++) {
            for (int i = 1; i <= K; i++) {
                // Obtenemos la nuevas posiciones en x y en y mientras no se salga dae rango
                // y no haya un muro
                int nx = c + dx[w] * i;
                int ny = f + dy[w] * i;
                if (nx < 0 || nx >= C || ny < 0 || ny >= F || g[ny][nx] == '#')
                    break;
                // Nos aseguramos que sea espacio en balnco ya que puede haber otro sensor,
                // puede ser X en cuyo caso nos da igual
                if (g[ny][nx] == '.' || g[ny][nx] == 'P' || g[ny][nx] == 'E')
                    g[ny][nx] = 'X';
            }
        }
    }

    // BFS para encontrar la salida mas corta, busqueda de anchura
    public static int bfs(Pair O, Pair D) {
        if (g[O.f][O.c] == 'X')
            return -1;

        int[] dist = new int[F * C];
        Arrays.fill(dist, -1);
        dist[(O.f * C) + O.c] = 0;
        Queue<Pair> q = new LinkedList<>();
        q.add(O);

        while (!q.isEmpty()) {
            Pair v = q.poll();
            // Obtener la posicion en x y en y en el tablero
            int f = v.f;
            int c = v.c;

            for (int k = 0; k < 4; k++) {
                // Nueva posicion en y
                int ny = f + dy[k];
                // Nueva posicion en x
                int nx = c + dx[k];

                // Si está fuera de rango o hay muro continuamos
                if (nx < 0 || nx >= C || ny < 0 || ny >= F)
                    continue;

                int w = (ny * C) + nx;
                // Si no hemos visitado el nodo lo visitamos hasta encontrar la salida
                if (dist[w] == -1 && (g[ny][nx] == '.' || g[ny][nx] == 'P')) {
                    dist[w] = dist[(f * C) + c] + 1;
                    // Si encontramos la salida retornamos la distancia
                    if (g[ny][nx] == 'P')
                        return dist[w];
                    q.add(new Pair(ny, nx));
                }
            }
        }
        // Si no hay salida retornamos -1
        return -1;
    }

    public static void solve(BufferedReader br, BufferedWriter bw) throws IOException {
        String input[] = br.readLine().split(" ");
        // Columnas (C) y filas (F)
        C = Integer.parseInt(input[0]);
        F = Integer.parseInt(input[1]);
        // Creamos un grafo con C*F nodos
        g = new char[F][C];

        Pair O = new Pair(0, 0); // Origen (O)
        Pair D = new Pair(0, 0); // Destino (D)

        // Llenamos el grafo con la entrada
        for (int f = 0; f < F; f++) {
            String line = br.readLine();
            for (int c = 0; c < C; c++) {
                char actual = line.charAt(c);
                // Guardamos el nodo de origen y destino en el plano cartesiano
                if (actual == 'E')
                    O = new Pair(f, c);
                else if (actual == 'P')
                    D = new Pair(f, c);
                g[f][c] = actual;
            }
        }

        // Agregamos los nodos de los sensores de movimeinto
        // Si es un número es la categoria de sensor, osea la cantidad de casillas que
        // vigila en cada dirección
        for (int f = 0; f < F; f++)
            for (int c = 0; c < C; c++)
                if (Character.isDigit(g[f][c]))
                    floatfill(f, c, Character.getNumericValue(g[f][c]));

        int sol = bfs(O, D);
        if (sol == -1)
            bw.write("NO\n");
        else
            bw.write(sol + "\n");
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int C = Integer.parseInt(br.readLine());
        while (C-- > 0) {
            solve(br, bw);
        }
        bw.flush();
        bw.close();
        br.close();
    }
}
