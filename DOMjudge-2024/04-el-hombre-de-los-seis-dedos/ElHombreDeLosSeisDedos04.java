import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class ElHombreDeLosSeisDedos04 {

    // Algoritmo de ventana deslizante
    public static int dedos(List<Integer> v, int k) {
        // Ventana mas grande encontrada hasta ahora (ret)
        int a = 0, b = 1, ret = 1;

        // Distancia entre papas k (<100)
        while (b < v.size()) {
            // Hacemos la ventana deslizante mas grande, hacia la derecha
            if (v.get(b) - v.get(a) < k)
                ++b;
            else 
                ++a;

            // Actualizamos la ventana mas grande encontrada
            if (b - a > ret) 
                ret = b - a;
        }
        return ret;
    }

    public static boolean resuelveCaso(Scanner sc) {
        // Nacimientos de los que tenemos constancia(n), máxima diferencia entre los años o rango (k)
        int n = sc.nextInt();
        int k = sc.nextInt();

        if (n == 0 && k == 0) 
            return false;

        // Años de nacimientos de personas con 6 dedos
        List<Integer> dedos = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            dedos.add(sc.nextInt());
        }

        System.out.println(dedos(dedos, k));
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (resuelveCaso(sc));
        sc.close();
    }
}