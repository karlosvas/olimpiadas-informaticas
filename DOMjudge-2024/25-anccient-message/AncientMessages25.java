import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

// Ankh: A
// Wedjat: J
// Djed: D
// Scarab: S
// Was: W
// Akhet: K

public class AncientMessages25 {

    static boolean visited[][];
    // Direcciones posibles en el tablero vertical y horizontal
    static int dx[] = { 0, 0, 1, -1 };
    static int dy[] = { 1, -1, 0, 0 };
    // Filas y columnas del tablero
    static int H, W;

    // DFS para descubrir casillas blancas y marcar como visitadas, a toda la
    // componente conexa
    public static void delWhite(int i, int j, char[][] board) {
        // Marcamos el nodo como visitado
        visited[i][j] = true;

        // Recorremos las 4 direcciones posibles
        for (int k = 0; k < 4; k++) {
            // Posiciones adyacentes en el tablero tanto en filas como en columnas
            int ni = i + dx[k];
            int nj = j + dy[k];

            // Si está en rango y no ha sido visitado, entonces lo visitamos, siempre que
            // sea blanca
            if (ni >= 0 && nj >= 0 && ni < H && nj < W && !visited[ni][nj] && board[ni][nj] == '0')
                delWhite(ni, nj, board);
        }
    }

    // DFS para descubrir casillas negras y contar las componentes conexas blancas
    // que se escuentra o que tiene la figura
    public static int delBlack(int i, int j, char[][] board) {
        // Marcamos el nodo como visitado
        visited[i][j] = true;

        // Contador de casillas blancas
        int blancas = 0;
        for (int k = 0; k < 4; k++) {
            // Posiciones adyacentes en el tablero tanto en filas como en columnas
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni >= 0 && nj >= 0 && ni < H && nj < W && !visited[ni][nj]) {
                // Si esta en rango o marcamos la componente conexa blanca haciendo un floatfill
                // o marcamos la siguiente posición negra de la figura
                if (board[ni][nj] == '0') {
                    blancas++;
                    delWhite(ni, nj, board);
                } else if (board[ni][nj] == '1')
                    blancas += delBlack(ni, nj, board);
            }
        }
        return blancas;
    }

    // Convertir de hexadecimal a binario
    public static StringBuilder getBinaryToHexa(char hexadecimal, StringBuilder binary, char[][] board, int i, int j) {
        // Convertimos el carácter hexadecimal a un entero
        int numberHexa = Character.digit(hexadecimal, 16);

        // Convertimos el número hexadecimal a binario
        while (numberHexa > 0) {
            binary.insert(0, numberHexa % 2);
            numberHexa /= 2;
        }

        // Añadimos ceros a la izquierda si el número hexadecimal es menor a 4 bits
        while (binary.length() < 4)
            binary.insert(0, 0);

        return binary;
    }

    public static boolean solve(BufferedReader br, BufferedWriter bw, int C) throws IOException {
        String input[] = br.readLine().trim().split(" ");

        // Filas (F) y columnas (C) del tablero
        H = Integer.parseInt(input[0]);
        W = Integer.parseInt(input[1]);

        if (W + H == 0)
            return false;

        // Tablero en el que vamos a jugar y visitados
        char board[][] = new char[H * 4][W * 4];
        visited = new boolean[H * 4][W * 4];

        for (int i = 0; i < H; i++) {
            String row = br.readLine().trim();
            for (int j = 0; j < W; j++) {
                // Obtenemos el valor hexadecimal dle tablero y lo transformamos a binario
                char hexadecimal = row.charAt(j);

                // Binario resultante (binary) de la conversion de hexadecimal a binario
                StringBuilder binary = new StringBuilder();
                binary = getBinaryToHexa(hexadecimal, binary, board, i, j);

                for (int k = 0; k < 4; k++)
                    board[i][(j * 4) + k] = binary.charAt(k);
            }
        }

        // Aumentamos el tamaño del tablero * 4 porque cada uno de los digitos o letras
        // en hexadecimal ocupa 4 bits
        W *= 4;

        // Quitamos el fondo recorriendo los bordes del tablero
        for (int i = 0; i < H; i++) {
            if (i == 0 || i == H - 1) {
                for (int j = 0; j < W; j++)
                    if (!visited[i][j] && board[i][j] == '0')
                        delWhite(i, j, board);
            } else {
                if (!visited[i][0] && board[i][0] == '0')
                    delWhite(i, 0, board);
                if (!visited[i][W - 1] && board[i][W - 1] == '0')
                    delWhite(i, W - 1, board);
            }
        }

        // Lista de solucciones
        List<Character> list = new ArrayList<>();
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                // Hacemos un DFS para encontrar las figuras negras y contar las componentes
                if (!visited[i][j] && board[i][j] == '1') {
                    // Cada figura tiene mas o menos componentes blancas
                    int blancas = delBlack(i, j, board);
                    switch (blancas) {
                        case 0:
                            // Was: W
                            list.add('W');
                            break;
                        case 1:
                            // Ankh: A
                            list.add('A');
                            break;
                        case 2:
                            // Akhet: K
                            list.add('K');
                            break;
                        case 3:
                            // Wedjat: J
                            list.add('J');
                            break;
                        case 4:
                            // Scarab: S
                            list.add('S');
                            break;
                        case 5:
                            // Djed: D
                            list.add('D');
                            break;
                    }
                }
            }
        }

        // Lo ordenamos alfabeticamente y lo guardamos en un string (result)
        Collections.sort(list);
        String result = "";
        for (Character ch : list)
            result += ch;

        // Mostar el resultado
        bw.write("Case " + C + ": " + result + "\n");
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        // Cada caso de prueba (C) que se va a resolver
        int C = 1;
        while (solve(br, bw, C))
            C++;
        bw.flush();
        bw.close();
        br.close();
    }
}