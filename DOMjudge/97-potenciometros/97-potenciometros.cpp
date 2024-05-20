#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline int IZDA(int n) { return 2 * n; };
inline int DCHA(int n) { return 2 * n + 1; };

struct segment_tree {
    vector<int> st;
    int numElems;

    // Constructor para crear una instancia del Segment Tree con un tamaño máximo de 4*n
    segment_tree(int n) : numElems(n), st(4 * n, 0) {
    }
    // Constructor para inicializar el Segment Tree con un vector de resistencias dado
    segment_tree(const vector<int> &v) : numElems(v.size()), st(4 * v.size(), 0) {
        // Inicializa el Segment Tree utilizando el vector dado
        init(v, 1, 0, numElems - 1);
    }

    // Función recursiva para realizar consultas en el Segment Tree
    int Q(int node, int l, int r, int a, int b) {
        // Sanity-check: [a..b] interseca [l..r]
        assert((l <= b) && (a <= r));
        if ((a <= l) && (r <= b)) return st[node];

        // Caso recursivo
        int m = (l + r) / 2;
        int izda, dcha;

        // Parte de la consulta está en el hijo izquierdo
        if (a <= m)
            izda = Q(IZDA(node), l, m, a, b);
        // Parte de la consulta está en el hijo derecho
        if (m < b)
            dcha = Q(DCHA(node), m + 1, r, a, b);

        if (b <= m) return izda;
        if (m < a) return dcha;
        return izda + dcha;
    }

    // Función pública para realizar consultas en el Segment Tree
    int query(int a, int b) {
        return Q(1, 0, numElems - 1, a, b);
    }

    // Función recursiva para actualizar un valor en el Segment Tree
    int U(int node, int l, int r, int pos, int val) {
        assert((l <= pos) && (pos <= r));
        if (l == r) {
            // Asigna el nuevo valor y devuelve el nuevo valor asignado
            st[node] = val;
            return st[node];
        }
        // Divide el segmento en dos
        int m = (l + r) / 2;
        int res;
        if (pos <= m)
            res = U(IZDA(node), l, m, pos, val);
        else
            res = U(DCHA(node), m + 1, r, pos, val);
        // Actualiza el valor del nodo actual con la suma de los valores de sus hijos
        st[node] = st[IZDA(node)] + st[DCHA(node)];
        return res;
    }

    // Función pública para actualizar un valor en el Segment Tree
    int update(int pos, int val) {
        return U(1, 0, numElems - 1, pos, val);
    }

    // Función recursiva para inicializar el Segment Tree
    void init(const vector<int> &v, int node, int l, int r) {
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
};

bool solve() {
    // Potenciómetros(N)
    int N;
    cin >> N;

    if (!cin)
        return false;

    // Agregamos el vector de los valores de las resistencias
    vector<int> resistencias(N);
    for (int i = 0; i < N; i++)
        cin >> resistencias[i];

    // Inicializamos uan instancia de Segment Trees
    segment_tree tree(resistencias);

    string OP;
    while (cin >> OP && OP != "FIN") {
        // OP=M Medimos los valores en el rango[a..b]
        if (OP == "M") {
            int a, b;
            cin >> a >> b;
            cout << tree.query(a - 1, b - 1) << "\n";
            // Actualizamos los datos en a con el valor b
        } else if (OP == "S") {
            int a, b;
            cin >> a >> b;
            tree.update(a - 1, b);
        }
    }
    // Fin del caso de prueba
    cout << "---\n";
    return true;
}

int main() {
    while (solve());
    return 0;
}