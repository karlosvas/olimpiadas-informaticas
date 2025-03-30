import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class OvejasNegras {
    static boolean[][] visited;
    static int[] dx = { 0, 0, 1, -1 };
    static int[] dy = { 1, -1, 0, 0 };
    static int F, C;

    public static void dfs(int f, int c, char[][] g) {
        // Marcar como visitado el nodo actual interior de la oveja
        visited[f][c] = true;

        // Recorremos todos su adyacentes
        for (int i = 0; i < 4; i++) {
            // Calculamos la nueva fila y columna, horizontal y verticalmente
            int nf = f + dx[i];
            int nc = c + dy[i];

            // Nos aseguramos de que la nueva fila y columna estén dentro de los límites
            nf = Math.max(0, Math.min(nf, F - 1));
            nc = Math.max(0, Math.min(nc, C - 1));

            // Si no ha sido visitado y es '.' es un nodo válido, osea interior de oveja, lo
            // visitamos
            if (!visited[nf][nc] && g[nf][nc] == '.')
                dfs(nf, nc, g);
        }
    }

    public static boolean solve(BufferedReader br, BufferedWriter bw) throws IOException {
        String line;
        if ((line = br.readLine()) == null || line.isEmpty())
            return false;

        // Leemos las dimensiones del terreno, F filas y C columnas
        String[] parts = line.trim().split(" ");
        C = Integer.parseInt(parts[0]);
        F = Integer.parseInt(parts[1]);

        // Cremoas la matriz de caracteres que representa una foto a ovejas y la matriz
        // de visitados
        char[][] g = new char[F][C];
        visited = new boolean[F][C];

        // Leemos la foto de ovejas de la entrada
        for (int i = 0; i < F; i++) {
            String row = br.readLine();
            for (int j = 0; j < C; j++) {
                g[i][j] = row.charAt(j);
            }
        }

        // Contamos el número de ovejas blancas, osea que tienen '.' en su interior,
        // componentes conexas
        int whiteSheep = 0;
        for (int f = 0; f < F; f++) {
            for (int c = 0; c < C; c++) {
                if (!visited[f][c] && g[f][c] == '.') {
                    dfs(f, c, g);
                    whiteSheep++;
                }
            }
        }

        // Escribimos el número de ovejas blancas menos 1, ya que es el fondo
        bw.write((whiteSheep - 1) + "\n");
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