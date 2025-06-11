package p24JugandoAlBuscaminas;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class JugandoAlBuscaminas24 {
    static int F, C;
    static int[] dx = { -1, -1, -1, 0, 0, 1, 1, 1 };
    static int[] dy = { -1, 0, 1, -1, 1, -1, 0, 1 };
    static boolean[][] visited;

    // DFS para descubrir casillas
    public static void dfs(int f, int c, char[][] board, char[][] PlayerBoard) {
        // Marcar casilla como visitada
        visited[f][c] = true;

        // Numero de bombas adyacentes
        int bomb = 0;
        for (int i = 0; i < 8; i++) {
            int nc = c + dx[i];
            int nf = f + dy[i];

            if (nc >= 0 && nf >= 0 && nc < C && nf < F && board[nf][nc] == '*')
                bomb++;
        }

        // Se hay bombas adyacentes, mostrar el numero de bombas en el tablero del
        // jugador si no, mostrar espacio '-'
        if (bomb > 0)
            PlayerBoard[f][c] = (char) (bomb + '0');
        else
            PlayerBoard[f][c] = '-';

        // Recorrer las casillas adyacentes en busca de casillas vacias, si el board no
        // hay bomba y el PlayerBoard se ha descubierto que es una casilla sin
        // adyacentes se llama a dfs
        for (int i = 0; i < 8; i++) {
            int nc = c + dx[i];
            int nf = f + dy[i];

            nc = Math.max(0, Math.min(nc, C - 1));
            nf = Math.max(0, Math.min(nf, F - 1));

            if (!visited[nf][nc] && board[nf][nc] == '-' && PlayerBoard[f][c] == '-')
                dfs(nf, nc, board, PlayerBoard);
        }
    }

    public static boolean solve(BufferedReader br, BufferedWriter bw) throws IOException {
        String line;
        if ((line = br.readLine()) == null || line.isBlank())
            return false;

        String input[] = line.trim().split(" ");

        // Filas (F) y columnas (C) del tablero
        F = Integer.parseInt(input[0]);
        C = Integer.parseInt(input[1]);

        // Inicializar tableros, board es el tablero con las bombas y PlayerBoard es el
        // tablero del jugador, visited es un tablero para marcar las casillas que ya
        // fueron visitadas
        char[][] board = new char[F][C];
        char[][] PlayerBoard = new char[F][C];
        visited = new boolean[F][C];

        // Llenar tablero con la entrada
        for (int f = 0; f < F; f++) {
            String line2 = br.readLine().trim();
            for (int c = 0; c < C; c++) {
                board[f][c] = line2.charAt(c);
                PlayerBoard[f][c] = 'X';
            }
        }

        // Numero de casos de prueba
        int K = Integer.parseInt(br.readLine().trim());

        for (int i = 0; i < K; i++) {
            int a, b;
            String[] input2 = br.readLine().trim().split(" ");
            a = Integer.parseInt(input2[0]);
            b = Integer.parseInt(input2[1]);
            // Las casillas se cuentan desde 1 por lo que se resta 1
            a--;
            b--;

            // Si la casilla tiene una bomba, mostrar GAME OVER y terminar el juego
            if (board[a][b] == '*') {
                bw.write("GAME OVER\n");
                return true;
            }
            // Si no simular el descubrimiento de casillas
            dfs(a, b, board, PlayerBoard);
        }

        // Mostrar tablero del jugador que es el resultado
        for (int f = 0; f < F; f++) {
            for (int c = 0; c < C; c++)
                bw.write(PlayerBoard[f][c]);
            bw.write("\n");
        }

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