package p22InviertiendoEnJaen;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class InvirtiendoEnJaen22 {

    static boolean[][] visited;
    static int[] dx = { 0, 0, 1, -1 };
    static int[] dy = { 1, -1, 0, 0 };
    static int F, C;

    public static int dfs(int f, int c, char[][] g) {
        // El actual olivo ya ha sido visitado
        visited[f][c] = true;

        // Contador de olivos en la componente conexa 1 en cada llamada
        int count = 1;

        for (int i = 0; i < 4; i++) {
            // Calculamos la nueva posicion en la matriz tanto fila como columna
            int nf = f + dx[i];
            int nc = c + dy[i];

            // Nos aseguramos de que la nueva posicion este dentro de la matriz
            nf = Math.max(0, Math.min(nf, F - 1));
            nc = Math.max(0, Math.min(nc, C - 1));

            // Si la nueva posicion no ha sido visitada y es un olivo (#) llamamos a dfs
            // recursivamente
            if (!visited[nf][nc] && g[nf][nc] == '#')
                count += dfs(nf, nc, g);
        }

        return count;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        while (solve(br, bw))
            ;
        bw.flush();
        br.close();
        bw.close();
    }

    public static boolean solve(BufferedReader br, BufferedWriter bw) throws IOException {
        String line;
        if ((line = br.readLine()) == null || line.isEmpty())
            return false;

        String[] parts = line.trim().split(" ");
        // Filas (F) y columnas (C)
        F = Integer.parseInt(parts[0]);
        C = Integer.parseInt(parts[1]);

        // Matriz de caracteres que representan olivos y matriz de si han sido visitados
        char[][] g = new char[F][C];
        visited = new boolean[F][C];

        // Rellenamos los olivos con los datos de la entrada
        for (int i = 0; i < F; i++) {
            String row = br.readLine();
            for (int j = 0; j < C; j++) {
                g[i][j] = row.charAt(j);
            }
        }

        // Mamixma componente conexa encontrada
        int maxConexa = 0;
        // Recorremos todo el campo de olivos en busca de la sucesion de olivos (#) mas
        // grande con un dfs
        for (int i = 0; i < F; i++) {
            for (int j = 0; j < C; j++) {
                if (!visited[i][j] && g[i][j] == '#')
                    maxConexa = Math.max(maxConexa, dfs(i, j, g));
            }
        }

        // Escribimos la salida
        bw.write(maxConexa + "\n");
        return true;
    }
}
/*
 * 8 8
 * -#-#---#
 * -###---#
 * ----####
 * #-------
 * -#-#----
 * -###-##-
 * ###--##-
 * --#-----
 */