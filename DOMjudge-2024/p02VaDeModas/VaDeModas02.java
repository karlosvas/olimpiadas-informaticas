package p02VaDeModas;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public
class VaDeModas02 {
   public
    static int modas(ArrayList<Integer> v) {
        // Ordenar el vector
        Collections.sort(v);

        // Encontrar la moda
        int moda = v.get(0);
        int max_count = 1, current_count = 1;

        for (int i = 1; i < v.size(); ++i) {
            // Si el elemento actual es igual al anterior, incrementar el contador
            if (v.get(i).equals(v.get(i - 1))) {
                current_count++;
            } else {
                // Si el contador actual es mayor que el máximo, actualizar la moda
                if (current_count > max_count) {
                    max_count = current_count;
                    moda = v.get(i - 1);
                }
                // Reiniciar el contador
                current_count = 1;
            }
        }

        // Verificar la última secuencia
        if (current_count > max_count)
            moda = v.get(v.size() - 1);

        return moda;
    }

   public
    static boolean solve(Scanner sc) {
        int n = sc.nextInt();
        if (n == 0) return false;

        ArrayList<Integer> v = new ArrayList<>(n);

        for (int i = 0; i < n; i++) {
            v.add(sc.nextInt());
        }

        int m = modas(v);
        System.out.println(m);

        return true;
    }

   public
    static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (solve(sc));

        sc.close();
    }
}