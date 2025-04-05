package p47PetrolerosUnidos;

import java.util.Arrays;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class PetrolerosUndidos {
    public static UFDS ufdsInstance;
    public static DFS dfsInstance;
    public static boolean[][] visited;
    public static String[][] mar;
    public static int[] df = {-1,  0, 1,  0, -1, -1, 1,  1};
    public static int[] dc = { 0,  1, 0, -1, -1,  1, -1, 1};

    public static class UFDS {
        // Para cada nodo: p[i] < 0 indica que i es raíz y que el tamaño del conjunto es -p[i]
        public int numSets;
        private int[] p;  
    
        // Union-Find Disjoint Sets (UFDS) con compresión de caminos
        public UFDS(int N) {
            // Inicializamos con N conjuntos individuales
            numSets = N;
            p = new int[N];
            Arrays.fill(p, -1);
        }
    
        // Método find con compresión de caminos
        public int find(int i) {
            if (p[i] < 0) {
                return i;
            } else {
                p[i] = find(p[i]);
                return p[i];
            }
        }
    
        // Comprueba si dos elementos pertenecen al mismo conjunto
        public boolean related(int i, int j) {
            return find(i) == find(j);
        }
    
        // Une los conjuntos que contienen i y j (union por tamaño)
        public void join(int i, int j) {
            int x = find(i);
            int y = find(j);
            if (x == y) return; // Ya están en el mismo conjunto
    
            // Si p[x] < p[y] significa que el conjunto de x es más grande
            if (p[x] < p[y]) {
                // Intercambiamos para que x sea el representante del conjunto más pequeño
                int temp = x;
                x = y;
                y = temp;
            }
            // Se une el conjunto de x al de y
            p[y] += p[x];
            p[x] = y;
            numSets--;
        }
    
        // Devuelve el tamaño del conjunto al que pertenece i
        public int size(int i) {
            return -p[find(i)];
        }
    }

    public static class DFS {
        public String[][] mar;
        public int F;
        public int C;
        // Miramos en 8 direcciones

        public DFS (int F, int C, String[][] mar) {
            this.F = F;
            this.C = C;
            this.mar = mar;
        }
        
        // Depth First Search (búsqueda en profundidad)
        public void dfs(int f, int c) {
            visited[f][c] = true;

            for (int d = 0; d < 8; d++){
                int nf = f + df[d];
                int nc = c + dc[d];

                // Si la nueva posicion es valida y no ha sido visitada, la visitamos
                if (nf < 0 || nf >= F || nc < 0 || nc >= C) continue;

                // Coordenadas en el eje cartesioano
                int cellIndex = f * C + c;
                int newIndex = nf * C + nc;

                // Verificamos si hay petroleo, si no la ignoramos
                if(mar[nf][nc].equals("#")){
                    // Si no pertenecen al mismo conjunto, los unimos
                    if (!ufdsInstance.related(cellIndex, newIndex)) {
                        ufdsInstance.join(cellIndex, newIndex);
                    }
                    // Si no ha sido visitada, la visitamos
                    if(!visited[nf][nc])  {
                        dfs(nf, nc);
                    }
                }
            }
        }
    
    };

    static Scanner in;

    public static boolean solve() {
        if (!in.hasNextInt()) return false;
        
        // Filas (F) y columnas de la matriz que representa el mar (C)
        int F, C;
        F = in.nextInt();
        C = in.nextInt();
        in.nextLine(); // Consume la linea de salto

        // Lleemos la matriz que representa el mar
        // Inicializamos la matriz con el tamaño correspondiente
        mar = new String[F][C];
        for (int f = 0; f < F; f++) {
            String[] line = in.nextLine().split("");
            for (int c = 0; c < C; c++) {
                mar[f][c] = line[c];
            }
        }

        // Inicializamos el objeto de la clase DFS
        // Inicializamos el objeto de la clase UFDS
        // Inicializamos la matriz visitados
        dfsInstance = new DFS(F, C, mar);
        ufdsInstance = new UFDS(F * C);
        visited = new boolean[F][C];
        // Máxima componente conexa de petroleo encontrada
        int maxSize = 0;

        for (int f = 0; f < F; f++) {
            for (int c = 0; c < C; c++) {
                // Si hay petroleo y no esta vsiiatda hay una componente conexa que devemos visitar
                if(mar[f][c].equals("#") && !visited[f][c]) {
                    // Recorremos la componente conexa y vemos su tamaño gracias a la clase UFDS
                    dfsInstance.dfs(f, c);
                    maxSize = Math.max(maxSize, ufdsInstance.size(f * C + c));
                }
            }
        }

        // Imprimimos el tamaño del mayor conjunto de islas
        System.out.print(maxSize);

        // Questiones
        int N;
        N = in.nextInt();
        for (int n= 0; n < N; n++) {
            int f, c;
            f = in.nextInt() -1;
            c = in.nextInt() -1;

            // Añadimos la nueva casilla de petroleo al mar
            mar[f][c] = "#";

            // Miramos en las 8 casillas adyacentes
            // Si hay petroleo, unimos los conjuntos
            int cellIndex = f * C + c;
            for (int i = 0; i < 8; i++) {
                int nf = f + df[i];
                int nc = c + dc[i];
                int newIndex = nf * C + nc;
                if(nf < 0 || nf >= F || nc < 0 || nc >= C) continue;
                if (mar[nf][nc].equals("#") && !ufdsInstance.related(cellIndex, newIndex))
                    ufdsInstance.join(cellIndex, newIndex);
            }

            // Actualizamos el nuevo tamaño del conjunto
            maxSize = Math.max(maxSize, ufdsInstance.size(cellIndex));
            System.out.print( " " + maxSize);
        }
        System.out.println();

        return true;
    }

    public static void main(String[] args) throws FileNotFoundException {
        boolean isDebug = false;
        if (isDebug)
            in = new Scanner(new java.io.File("DOMjudge-2024/p47PetrolerosUnidos/input.txt"));
        else
            in = new Scanner(System.in);
        while (solve());

        in.close();
    }
}