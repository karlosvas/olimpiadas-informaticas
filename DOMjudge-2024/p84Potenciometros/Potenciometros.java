package p84Potenciometros;

import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Potenciometros {
    static Scanner in;

    class SegmentTree {
        private int[] st;
        private int numElems;

        // Constructor para crear una instancia del Segment Tree con un tamaño máximo de 4*n
        public SegmentTree(int n) {
            this.numElems = n;
            this.st = new int[4 * n];
            Arrays.fill(st, 0);
        }

        // Constructor para inicializar el Segment Tree con un vector de resistencias dado
        public SegmentTree(int[] v) {
            this.numElems = v.length;
            this.st = new int[4 * v.length];
            Arrays.fill(st, 0);
            init(v, 1, 0, numElems - 1);
        }

        // Función recursiva para realizar consultas en el Segment Tree
        private int Q(int node, int l, int r, int a, int b) {
            assert((l <= b) && (a <= r));
            if (a <= l && r <= b) {
                return st[node];
            }

            // Caso recursivo
            int m = (l + r) / 2;
            int izda = 0, dcha = 0;

            // Parte de la consulta está en el hijo izquierdo
            if (a <= m) {
                izda = Q(IZDA(node), l, m, a, b);
            }

            // Parte de la consulta está en el hijo derecho
            if (m < b) {
                dcha = Q(DCHA(node), m + 1, r, a, b);
            }

            if (b <= m) return izda;
            if (m < a) return dcha;
            return izda + dcha;
        }

        // Función pública para realizar consultas en el Segment Tree
        public int query(int a, int b) {
            return Q(1, 0, numElems - 1, a, b);
        }

        // Función recursiva para actualizar un valor en el Segment Tree
        private int U(int node, int l, int r, int pos, int val) {
            // Lanza una AssertionError si la condición no se cumple
            assert (l <= pos) && (pos <= r);
            if (l == r) {
                // Asigna el nuevo valor y devuelve el nuevo valor asignado
                st[node] = val;
                return st[node];
            }

            // Divide el segmento en dos
            int m = (l + r) / 2;
            int res;
            if (pos <= m) {
                res = U(IZDA(node), l, m, pos, val);
            } else {
                res = U(DCHA(node), m + 1, r, pos, val);
            }

            // Actualiza el valor del nodo actual con la suma de los valores de sus hijos
            st[node] = st[IZDA(node)] + st[DCHA(node)];
            return res;
        }

        // Función pública para actualizar un valor en el Segment Tree
        public int update(int pos, int val) {
            return U(1, 0, numElems - 1, pos, val);
        }

        // Función recursiva para inicializar el Segment Tree
        private void init(int[] v, int node, int l, int r) {
            if (l == r) {
                // Asigna el valor del vector a la hoja del Segment Tree
                st[node] = v[l];
                return;
            }

            // Divide el segmento en dos y realiza la inicialización recursiva
            int m = (l + r) / 2;
            init(v, IZDA(node), l, m);
            init(v, DCHA(node), m + 1, r);

            // Actualiza el valor del nodo actual con la suma de los valores de sus hijos
            st[node] = st[IZDA(node)] + st[DCHA(node)];
        }

        // Funciones auxiliares para obtener los índices de los hijos izquierdo y derecho
        private int IZDA(int n) {
            return 2 * n;
        }

        private int DCHA(int n) {
            return 2 * n + 1;
        }
    }

    public static boolean solve() {
        if (!in.hasNextInt()) return false;
        
        int N = in.nextInt();

       int[] resitencias = new int[N];
        for (int i = 0; i < N; i++) 
            resitencias[i] = in.nextInt();

        SegmentTree st = new Potenciometros().new SegmentTree(resitencias);
        String OP = "";

        while(!OP.equals("FIN")){
            OP = in.next();
            if(OP.equals("FIN")) break;
            int a = in.nextInt();
            int b = in.nextInt();

            if(OP.equals("M")){
                System.out.println(st.query(a-1, b-1));
            } else if(OP.equals("S")){
                st.update(a-1, b);
            }
        }

        System.out.println("---");
        return true;
    }

    public static void main(String[] args) throws FileNotFoundException {
        boolean isDebug = false;
        if (isDebug)
            in = new Scanner(new java.io.File("DOMjudge-2024/ClassName/input.txt"));
        else
            in = new Scanner(System.in);
        while (solve());

        in.close();
    }
}