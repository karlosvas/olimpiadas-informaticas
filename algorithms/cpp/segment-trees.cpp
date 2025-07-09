#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

// Segment Tree básico para suma de rangos
class SegmentTree {
   private:
    vector<long long> tree;
    int n;

    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void updateHelper(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                updateHelper(2 * node, start, mid, idx, val);
            } else {
                updateHelper(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    long long queryHelper(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0;  // Fuera del rango
        }
        if (l <= start && end <= r) {
            return tree[node];  // Completamente dentro del rango
        }
        int mid = (start + end) / 2;
        return queryHelper(2 * node, start, mid, l, r) +
               queryHelper(2 * node + 1, mid + 1, end, l, r);
    }

   public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    void update(int idx, int val) {
        updateHelper(1, 0, n - 1, idx, val);
    }

    long long query(int l, int r) {
        return queryHelper(1, 0, n - 1, l, r);
    }

    void printTree() {
        cout << "Árbol interno: ";
        for (int i = 1; i < tree.size() && tree[i] != 0; i++) {
            cout << tree[i] << " ";
        }
        cout << endl;
    }
};

// Segment Tree para mínimo en rango
class SegmentTreeMin {
   private:
    vector<int> tree;
    int n;

    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void updateHelper(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                updateHelper(2 * node, start, mid, idx, val);
            } else {
                updateHelper(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int queryHelper(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return INT_MAX;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        return min(queryHelper(2 * node, start, mid, l, r),
                   queryHelper(2 * node + 1, mid + 1, end, l, r));
    }

   public:
    SegmentTreeMin(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    void update(int idx, int val) {
        updateHelper(1, 0, n - 1, idx, val);
    }

    int query(int l, int r) {
        return queryHelper(1, 0, n - 1, l, r);
    }
};

// Segment Tree con Lazy Propagation para actualizaciones de rango
class LazySegmentTree {
   private:
    vector<long long> tree, lazy;
    int n;

    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void updateLazy(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node] * (end - start + 1);
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void updateRangeHelper(int node, int start, int end, int l, int r, int val) {
        updateLazy(node, start, end);
        if (start > r || end < l) {
            return;
        }
        if (start >= l && end <= r) {
            tree[node] += val * (end - start + 1);
            if (start != end) {
                lazy[2 * node] += val;
                lazy[2 * node + 1] += val;
            }
            return;
        }
        int mid = (start + end) / 2;
        updateRangeHelper(2 * node, start, mid, l, r, val);
        updateRangeHelper(2 * node + 1, mid + 1, end, l, r, val);
        updateLazy(2 * node, start, mid);
        updateLazy(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    long long queryHelper(int node, int start, int end, int l, int r) {
        if (start > r || end < l) {
            return 0;
        }
        updateLazy(node, start, end);
        if (start >= l && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        return queryHelper(2 * node, start, mid, l, r) +
               queryHelper(2 * node + 1, mid + 1, end, l, r);
    }

   public:
    LazySegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        lazy.resize(4 * n, 0);
        build(arr, 1, 0, n - 1);
    }

    void updateRange(int l, int r, int val) {
        updateRangeHelper(1, 0, n - 1, l, r, val);
    }

    long long query(int l, int r) {
        return queryHelper(1, 0, n - 1, l, r);
    }
};

// Segment Tree para máximo y su frecuencia
class SegmentTreeMaxFreq {
   private:
    struct Node {
        int maxVal;
        int freq;
        Node() : maxVal(INT_MIN), freq(0) {}
        Node(int val) : maxVal(val), freq(1) {}
    };

    vector<Node> tree;
    int n;

    Node combine(Node a, Node b) {
        Node result;
        if (a.maxVal > b.maxVal) {
            result.maxVal = a.maxVal;
            result.freq = a.freq;
        } else if (b.maxVal > a.maxVal) {
            result.maxVal = b.maxVal;
            result.freq = b.freq;
        } else {
            result.maxVal = a.maxVal;
            result.freq = a.freq + b.freq;
        }
        return result;
    }

    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = Node(arr[start]);
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void updateHelper(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = Node(val);
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                updateHelper(2 * node, start, mid, idx, val);
            } else {
                updateHelper(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
        }
    }

    Node queryHelper(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return Node();
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        return combine(queryHelper(2 * node, start, mid, l, r),
                       queryHelper(2 * node + 1, mid + 1, end, l, r));
    }

   public:
    SegmentTreeMaxFreq(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    void update(int idx, int val) {
        updateHelper(1, 0, n - 1, idx, val);
    }

    pair<int, int> query(int l, int r) {
        Node result = queryHelper(1, 0, n - 1, l, r);
        return {result.maxVal, result.freq};
    }
};

// Segment Tree genérico con template
template <typename T>
class GenericSegmentTree {
   private:
    vector<T> tree;
    int n;
    function<T(T, T)> combine;
    T neutral;

    void build(vector<T>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void updateHelper(int node, int start, int end, int idx, T val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                updateHelper(2 * node, start, mid, idx, val);
            } else {
                updateHelper(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
        }
    }

    T queryHelper(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return neutral;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        return combine(queryHelper(2 * node, start, mid, l, r),
                       queryHelper(2 * node + 1, mid + 1, end, l, r));
    }

   public:
    GenericSegmentTree(vector<T>& arr, function<T(T, T)> combineFunc, T neutralElement)
        : combine(combineFunc), neutral(neutralElement) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    void update(int idx, T val) {
        updateHelper(1, 0, n - 1, idx, val);
    }

    T query(int l, int r) {
        return queryHelper(1, 0, n - 1, l, r);
    }
};

// Función principal con ejemplos
int main() {
    cout << "=== Segment Trees (Árboles de Segmentos) ===" << endl;

    // Ejemplo 1: Segment Tree básico para suma
    cout << "\n1. Segment Tree para suma de rangos:" << endl;
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree st(arr);

    cout << "Array original: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    st.printTree();

    cout << "Suma del rango [1, 3]: " << st.query(1, 3) << endl;
    cout << "Suma del rango [2, 5]: " << st.query(2, 5) << endl;

    cout << "Actualizando índice 1 a 10" << endl;
    st.update(1, 10);
    cout << "Nueva suma del rango [1, 3]: " << st.query(1, 3) << endl;

    // Ejemplo 2: Segment Tree para mínimo
    cout << "\n2. Segment Tree para mínimo en rango:" << endl;
    vector<int> arr2 = {4, 2, 8, 1, 6, 3, 9};
    SegmentTreeMin stMin(arr2);

    cout << "Array: ";
    for (int x : arr2) cout << x << " ";
    cout << endl;

    cout << "Mínimo en rango [1, 4]: " << stMin.query(1, 4) << endl;
    cout << "Mínimo en rango [2, 6]: " << stMin.query(2, 6) << endl;

    cout << "Actualizando índice 3 a 0" << endl;
    stMin.update(3, 0);
    cout << "Nuevo mínimo en rango [1, 4]: " << stMin.query(1, 4) << endl;

    // Ejemplo 3: Lazy Propagation
    cout << "\n3. Segment Tree con Lazy Propagation:" << endl;
    vector<int> arr3 = {1, 2, 3, 4, 5};
    LazySegmentTree lstTree(arr3);

    cout << "Array inicial: ";
    for (int x : arr3) cout << x << " ";
    cout << endl;

    cout << "Suma inicial del rango [0, 4]: " << lstTree.query(0, 4) << endl;

    cout << "Sumando 5 al rango [1, 3]" << endl;
    lstTree.updateRange(1, 3, 5);
    cout << "Nueva suma del rango [0, 4]: " << lstTree.query(0, 4) << endl;
    cout << "Suma del rango [1, 3]: " << lstTree.query(1, 3) << endl;

    // Ejemplo 4: Máximo y frecuencia
    cout << "\n4. Segment Tree para máximo y frecuencia:" << endl;
    vector<int> arr4 = {3, 7, 2, 7, 1, 7, 4};
    SegmentTreeMaxFreq stMaxFreq(arr4);

    cout << "Array: ";
    for (int x : arr4) cout << x << " ";
    cout << endl;

    auto result1 = stMaxFreq.query(1, 5);
    cout << "Máximo en rango [1, 5]: " << result1.first
         << " (frecuencia: " << result1.second << ")" << endl;

    auto result2 = stMaxFreq.query(0, 6);
    cout << "Máximo en rango [0, 6]: " << result2.first
         << " (frecuencia: " << result2.second << ")" << endl;

    // Ejemplo 5: Segment Tree genérico
    cout << "\n5. Segment Tree genérico:" << endl;

    // Para máximo
    vector<int> arr5 = {2, 8, 3, 9, 1, 6};
    auto maxFunc = [](int a, int b) { return max(a, b); };
    GenericSegmentTree<int> stGenericMax(arr5, maxFunc, INT_MIN);

    cout << "Array: ";
    for (int x : arr5) cout << x << " ";
    cout << endl;

    cout << "Máximo en rango [1, 4]: " << stGenericMax.query(1, 4) << endl;

    // Para XOR
    auto xorFunc = [](int a, int b) { return a ^ b; };
    GenericSegmentTree<int> stGenericXor(arr5, xorFunc, 0);

    cout << "XOR en rango [0, 3]: " << stGenericXor.query(0, 3) << endl;
    cout << "XOR en rango [2, 5]: " << stGenericXor.query(2, 5) << endl;

    // Ejemplo 6: Operaciones múltiples
    cout << "\n6. Múltiples operaciones en Segment Tree:" << endl;
    vector<int> arrMulti = {1, 4, 2, 8, 5, 7};
    SegmentTree stMulti(arrMulti);

    cout << "Array inicial: ";
    for (int x : arrMulti) cout << x << " ";
    cout << endl;

    // Realizar múltiples queries
    vector<pair<int, int>> queries = {{0, 2}, {1, 4}, {3, 5}, {0, 5}};
    for (auto& q : queries) {
        cout << "Suma [" << q.first << ", " << q.second << "]: "
             << stMulti.query(q.first, q.second) << endl;
    }

    // Realizar múltiples updates
    vector<pair<int, int>> updates = {{0, 10}, {2, 15}, {4, 20}};
    for (auto& u : updates) {
        cout << "Actualizando índice " << u.first << " a " << u.second << endl;
        stMulti.update(u.first, u.second);
    }

    cout << "Después de las actualizaciones:" << endl;
    for (auto& q : queries) {
        cout << "Suma [" << q.first << ", " << q.second << "]: "
             << stMulti.query(q.first, q.second) << endl;
    }

    return 0;
}

/*
Complejidad de Segment Trees:
- Construcción: O(n)
- Query: O(log n)
- Update: O(log n)
- Espacio: O(4n) ≈ O(n)

Características principales:
- Estructura de árbol binario completo
- Cada nodo representa un segmento del array
- Las hojas representan elementos individuales
- Los nodos internos combinan información de sus hijos

Tipos de Segment Trees:
1. Básico - suma, mínimo, máximo, XOR, etc.
2. Lazy Propagation - actualizaciones de rango eficientes
3. Persistente - mantiene versiones históricas
4. 2D - para consultas en matrices
5. Dinámico - con coordenadas comprimidas

Aplicaciones comunes:
- Consultas de rango (suma, mínimo, máximo)
- Actualizaciones puntuales y de rango
- Problemas de geometría computacional
- Algoritmos de programación dinámica optimizada
- Procesamiento de consultas offline

Ventajas:
- Consultas y actualizaciones eficientes O(log n)
- Versátil para muchos tipos de operaciones
- Implementación relativamente directa

Desventajas:
- Usa más memoria que arrays simples
- Más complejo que estructuras básicas
- Para actualizaciones de rango necesita lazy propagation

Variantes avanzadas:
- Segment Tree 2D
- Persistent Segment Tree
- Segment Tree with coordinate compression
- Heavy-Light Decomposition con Segment Trees
*/