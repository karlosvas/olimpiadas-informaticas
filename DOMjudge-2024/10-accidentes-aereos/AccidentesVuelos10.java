import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class AccidentesVuelos10 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (solve(sc))
            ;
        sc.close();
    }

    public static boolean solve(Scanner sc) {
        if (!sc.hasNextInt())
            return false;
        int n = sc.nextInt();

        List<Pair<String, Integer>> vuelos = new ArrayList<>();

        for (int i = 0; i < n; ++i) {
            String fecha = sc.next();
            int victimas = sc.nextInt();

            // Si no hay vuelos anteriores o mientras que el ultimo vuelo tenga menos
            // victimas que el actual se eliminan los vuelos anteriores
            while (!vuelos.isEmpty() && vuelos.get(vuelos.size() - 1).getValue() <= victimas)
                vuelos.remove(vuelos.size() - 1);

            // Si hay vuelos anteriores quiere decir que el vuelo actual es el que tiene más
            // víctimas hasta el momento o que no hay vuelos anteriores
            if (!vuelos.isEmpty())
                System.out.println(vuelos.get(vuelos.size() - 1).getKey());
            else
                System.out.println("NO HAY");

            // Se añade el vuelo actual a la lista de vuelos
            vuelos.add(new Pair<>(fecha, victimas));
        }
        System.out.println("---");
        return true;
    }

    static class Pair<K, V> {
        private final K key;
        private final V value;

        public Pair(K key, V value) {
            this.key = key;
            this.value = value;
        }

        public K getKey() {
            return key;
        }

        public V getValue() {
            return value;
        }
    }
}