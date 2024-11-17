import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;

public class DifundiendoUnRumor19 {
    // Grafo
    static class Pair {
        int w;
        int c;

        Pair(int w, int c) {
            this.w = w;
            this.c = c;
        }
    }

    static ArrayList<Set<Integer>> g;
    static boolean[] visit;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // Entrada del usuario
        while (solve(br, bw))
            ;

        // Mostramos lo resultados
        bw.flush();
    }

    public static boolean solve(BufferedReader br, BufferedWriter bw) throws IOException {
        // Entrada del usuario
        String line;

        if ((line = br.readLine()) == null || line.isEmpty())
            return false;

        String[] input = line.trim().split(" ");

        // Numero de personajes del Overcity (N)
        int N = Integer.parseInt(input[0]);

        // Numero de pares de amigos (M)
        int M = Integer.parseInt(input[1]);

        // Grafo de personajes
        g = new ArrayList<>();
        HashMap<Integer, Integer> m = new HashMap<>();

        // Cantidad de oro que requiere cada personaje desde 0 a N-1
        input = br.readLine().trim().split(" ");
        for (int i = 0; i < N; i++) {
            // Leemos la entrada, se lo añadimos al set y lo agregamos a el grafo
            m.put(i, Integer.parseInt(input[i]));
            g.add(new HashSet<>());
        }

        // Cantidad de gente que son amigos
        for (int i = 0; i < M; i++) {
            input = br.readLine().trim().split(" ");
            int a = Integer.parseInt(input[0]) - 1;
            int b = Integer.parseInt(input[1]) - 1;
            g.get(a).add(b);
            g.get(b).add(a);
        }

        // Suma de todos los minimos de las componentes conexas
        int sumas_min = 0;
        // Array de boleanos para saber cual fue visitado
        visit = new boolean[N];
        // Si no esta visitado sumamos el valor del nodo que menos cueste que comienze
        // el rumor en la componente conexa
        for (int i = 0; i < N; i++) {
            if (!visit[i])
                sumas_min += dfs(i, m);
        }
        bw.write(sumas_min + "\n");
        return true;
    }

    public static int dfs(int v, HashMap<Integer, Integer> m) {
        // El actual esat visitado
        visit[v] = true;
        int actual = m.get(v);
        // Para cada v buscamos en minimo precio de sus adyacentes
        for (int w : g.get(v)) {
            // Minimo entre el cosye de vecinos (w) y el (v)
            if (!visit[w])
                actual = Math.min(dfs(w, m), actual);
        }
        // Coste de que el empieze a difundir es secreto
        return actual;
    }

}
