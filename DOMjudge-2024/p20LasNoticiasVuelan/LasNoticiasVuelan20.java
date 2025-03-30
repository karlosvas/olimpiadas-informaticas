import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;

public class LasNoticiasVuelan20 {
    static boolean[] visited;
    static ArrayList<Set<Integer>> g;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        while (solve(br, bw))
            ;
        bw.flush();
    }

    public static boolean solve(BufferedReader br, BufferedWriter bw) throws IOException {
        String line;

        if ((line = br.readLine()) == null || line.isEmpty())
            return false;

        String[] input = line.trim().split(" ");

        // Usuarios en la red (N)
        int N = Integer.parseInt(input[0]);
        // Numero de grupos (M)
        int M = Integer.parseInt(input[1]);

        // Creamos el grafo y lo inicializamos
        g = new ArrayList<>(N);
        for (int i = 0; i < N; i++)
            g.add(new HashSet<>());

        // Leemos las relaciones de los nodos (aristas)
        for (int i = 0; i < M; i++) {
            input = br.readLine().trim().split(" ");
            int aristas = Integer.parseInt(input[0]);

            // Identificador de cada nodo, anterior(a), actual(b)
            int a = -1;
            for (int j = 1; j <= aristas; j++) {
                // Componente conexa por lo que se conocen entre ellos
                int b = Integer.parseInt(input[j]) - 1;
                // Si es la primera vez guardamos el valor de a
                if (j == 1) {
                    a = b;
                } else {
                    // Si es >= que la primera, se conocen grafo no dirijido a->b y b->a
                    g.get(a).add(b);
                    g.get(b).add(a);
                    // El actual se convierte en el anterior
                    a = b;
                }
            }
        }

        // Indice de la componente conexa
        int indice = 0;
        // Mapa de la componente conexa en la que se encuentra cada nodo
        HashMap<Integer, Integer> map = new HashMap<>();
        // Mapa de la cantidad de personas en cada componente conexa
        HashMap<Integer, Integer> tam = new HashMap<>();

        visited = new boolean[N];
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                int count = dfs(i, indice, map);
                // Guardamos en el map de tamaños a que id de componente conexa pertenece, y
                // cuantos son
                tam.put(indice, count);
                indice++;
            }
        }

        // Mostramos lo resultados, sera en el map de tamaños obtenemos la id de la
        // componente conexa utilizando map.get(i), entonces tamaño accedera a la
        // componente conexa que asocia a su cantidad
        for (int i = 0; i < N; i++) {
            if (i == N - 1)
                bw.write(tam.get(map.get(i)) + "\n");
            else
                bw.write(tam.get(map.get(i)) + " ");
        }

        return true;
    }

    // Necesitamos que en cada nodo se guarde el numero de personas en esa
    // componnente conexa
    public static int dfs(int v, int indice, HashMap<Integer, Integer> map) {
        // Guardamos en cada nodo a que componente conexa pertenece
        map.put(v, indice);
        visited[v] = true;
        int count = 1;
        for (int u : g.get(v))
            if (!visited[u])
                count += dfs(u, indice, map);
        return count;
    }
}
