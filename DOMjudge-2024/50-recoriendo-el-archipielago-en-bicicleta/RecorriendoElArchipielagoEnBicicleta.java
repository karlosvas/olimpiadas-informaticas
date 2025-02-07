
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;

public class RecorriendoElArchipielagoEnBicicleta {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    
    // Union-Find Disjoint Sets
    public static class UFDS {
        private int numSets;
        private int[] p;

        // Constructor
        public UFDS(int N) {
            numSets = N;
            p = new int[N];
            Arrays.fill(p, -1);
        }

        // Encuentra el representante del conjunto al que pertenece el elemento i
        public int find(int i) {
            if (p[i] < 0) {
                return i;
            } else {
                return p[i] = find(p[i]); // Compresión de ruta
            }
        }

        // Verifica si los elementos i y j están en el mismo conjunto
        public boolean related(int i, int j) {
            return find(i) == find(j);
        }

        // Une los conjuntos que contienen los elementos i y j
        public void join(int i, int j) {
            int x = find(i);
            int y = find(j);
            if (x == y) {
                return;
            }
            if (p[x] < p[y]) {
                int temp = x;
                x = y;
                y = temp;
            }
            p[y] += p[x];
            p[x] = y;
            --numSets;
        }

        // Devuelve el tamaño del conjunto que contiene el elemento i
        public int size(int i) {
            return -p[find(i)];
        }

        // Devuelve el número de conjuntos disjuntos
        public int getNumSets() {
            return numSets;
        }
    }

    static class Node {
        int a,b,c;
        Node(int a, int b, int c){
            this.a = a;
            this.b = b;
            this.c = c;
        }
        public int getC() {
            return c;
        }
    }

    public static boolean solve() throws IOException{
        String line;
        if ((line = br.readLine()) == null || line.isEmpty())
            return false;

        int I = Integer.parseInt(line.trim()); // Islas
        int P = Integer.parseInt(br.readLine().trim()); // Puentes
        
        // Tuplas de puentes, añadimos las uniones de los puentes
        ArrayList<Node> islas = new ArrayList<>();
        for (int i = 0; i < P; i++) {
            String[] split = br.readLine().trim().split(" ");
            // Islas a y b, y el costo de construirlo c
            int a,b,c; 
            a = Integer.parseInt(split[0]);
            b = Integer.parseInt(split[1]);
            c = Integer.parseInt(split[2]);
            // Índice basado en 0
            a--;
            b--;
            islas.add(new Node(a, b, c));
        }

        // Ordenar por costo utilizando UFDS conocido como algoritmo de Kruskal
        islas.sort((n1, n2) -> Integer.compare(n1.getC(), n2.getC()));
        UFDS uf = new UFDS(I);
        // Minimo costo de conectar todos las islas, al estar ordenadas, se asegura que se conectan las islas con menor costo
        int min = 0;
        for (int j = 0; j < islas.size(); j++) {
            // Si no estan relacionadas se relacionan y se suma el costo
            if(!uf.related(islas.get(j).a, islas.get(j).b)){
                uf.join(islas.get(j).a, islas.get(j).b);
                min += islas.get(j).c;
            }
            // Si ya se conectaron todas las islas, se termina
            if(uf.getNumSets() == 1)
                break;
        }

        // Si no se conectaron todas las islas, no hay puentes suficientes
        if (uf.numSets > 1)
            bw.write("No hay puentes suficientes\n");
        else
            bw.write(min + "\n");

        return true;
    }
    public static void main(String[] args) throws IOException {
        while(solve());
        bw.flush();
        br.close();
        bw.close();
    }
}
