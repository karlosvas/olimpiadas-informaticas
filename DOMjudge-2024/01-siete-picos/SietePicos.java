import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class SietePicos {

    public static int numPicos(List<Integer> v) {
        int picos = 0;
        int n = v.size();

        // Desde el segundo elemento hasta el penúltimo para no salirnos de rango
        // Si el elemento actual es mayor que el anterior y el siguiente, es un pico
        for (int i = 1; i < n - 1; ++i) {
            if (v.get(i - 1) < v.get(i) && v.get(i) > v.get(i + 1))
                ++picos;
        }

        // Comprobamos los extremos
        if (v.get(n - 1) < v.get(0) && v.get(0) > v.get(1))
            ++picos;
        if (v.get(n - 2) < v.get(n - 1) && v.get(n - 1) > v.get(0))
            ++picos;

        return picos;
    }

    public static boolean solve(Scanner scanner) {
        int n = scanner.nextInt();
        if (n == 0) return false;

        List<Integer> v = new ArrayList<>(n);

        for (int i = 0; i < n; ++i) 
            v.add(scanner.nextInt());
        

        int picos = numPicos(v);
        System.out.println(picos);

        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (solve(scanner));
    }
}