import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;

public class LaMaquinaCalculadora26 {

    // Función que devuelve los nodos adyacentes según la operación definida por i
    public static int adyacentes(int v, int i) {
        if (i == 0)
            return (v + 1) % 10000;
        else if (i == 1)
            return (v * 2) % 10000;
        else
            return v / 3;
    }

    // Función que realiza un BFS para encontrar el camino más corto para llegar de
    // un numero a otro, en este caso es un bfs implicito, osea que no esta definido
    // por unos nodos si no que se va creando conforme buscamos en el
    public static int bfs(int origin, int destination) {
        // Si el origen y el destino son iguales, la distancia es 0
        if (origin == destination)
            return 0;

        // Creamos un array de distancias, de 0 a 9999 inicializado a -1 porque aun no
        // lo hemos visitado
        int[] dist = new int[10000];
        for (int i = 0; i < 10000; i++)
            dist[i] = -1;

        // La distancia del origen es 0
        dist[origin] = 0;

        // Creamos una cola para el BFS que empieza con el origen
        Queue<Integer> q = new LinkedList<>();
        q.add(origin);

        while (!q.isEmpty()) {
            // Obtenemos el primer elemento de la cola
            int v = q.poll();
            // Recorremos los 3 adyacentes de v
            for (int i = 0; i < 3; i++) {
                int w = adyacentes(v, i);
                // Si no hemos visitado w, entonces la distancia de w es la distancia de v + 1
                if (dist[w] == -1) {
                    dist[w] = dist[v] + 1;
                    // Si w es el destino, devolvemos la distancia si no lo añadimos a la cola para
                    // seguir buscando
                    if (w == destination)
                        return dist[w];
                    else
                        q.add(w);
                }
            }
        }
        // Si no encontramos el destino, devolvemos -1
        return -1;
    }

    public static boolean solve(BufferedReader br, BufferedWriter bw) throws IOException {
        String line;
        if ((line = br.readLine()) == null || line.isEmpty())
            return false;

        // Obtenemos los valores de a y b de la entrada, origen(a), destino(b)
        String[] parts = line.split(" ");
        int a = Integer.parseInt(parts[0]);
        int b = Integer.parseInt(parts[1]);

        // Mostamos la distancia minima de a a b
        bw.write(bfs(a, b) + "\n");
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