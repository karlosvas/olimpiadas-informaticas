import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

public class LosAmigosDeMisAmigosSonMisAmigos {
    static ArrayList<Set<Integer>> g;
    static boolean[] visit;

    public static void main(String[] args) throws IOException {
        // Usamos BufferedReader y StringBuilder para mejorar la eficiencia
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int cases = Integer.parseInt(br.readLine().trim());
        // Casos de prueba
        while (cases-- > 0)
            solve(br, bw);
        bw.flush();
    }

    public static void solve(BufferedReader br, BufferedWriter bw) throws IOException {
        // Cantidad de vertices del grafo (N) amigos y cantidad de aristas (M)
        // relaciones de amistad

        String[] input = br.readLine().trim().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);

        // Creamos el grafo que es una lista de listas de adyacencia
        g = new ArrayList<>(N);
        for (int i = 0; i < N; i++)
            g.add(new HashSet<>());

        // Llenamos el grafo con las aristas o relaciones
        for (int i = 0; i < M; ++i) {
            input = br.readLine().trim().split(" ");
            int a = Integer.parseInt(input[0]) - 1;
            int b = Integer.parseInt(input[1]) - 1;
            // Es un grafo no dirigido por lo que a puede ser amigo de b y b de a
            g.get(a).add(b);
            g.get(b).add(a);
        }

        // Maximo de amigos que puede tener una persona en una componente conexa
        // (maximo)
        int maximo = 0;
        // Creamos un array para saber si ya visitamos un nodo
        visit = new boolean[N];

        // Si no esta visitado es una nueva componente conexa y buscamos el maximo
        for (int v = 0; v < N; ++v) {
            int tam = dfs(v);
            if (maximo < tam) {
                maximo = tam;
            }
        }
        // Mostramos el resultado
        bw.write(maximo + "\n");
    }

    public static int dfs(int v) {
        // Marcamos como visitado el nodo y devolbemos el tamaño de la componente conexa
        visit[v] = true;
        int size = 1;
        // Relaciones de v (w)
        for (int w : g.get(v))
            if (!visit[w])
                size += dfs(w);
        return size;
    }
}