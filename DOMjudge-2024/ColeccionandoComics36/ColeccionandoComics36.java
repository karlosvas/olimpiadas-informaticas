package ColeccionandoComics36;

import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Stack;

// Pila de cómics
class ComicPile {
    Stack<Long> stack;
    Long top;

    public ComicPile(Stack<Long> stack, Long top) {
        this.stack = stack;
        this.top = stack.isEmpty() ? Long.MAX_VALUE : stack.peek();
    }
}

public class ColeccionandoComics36 {
    static java.util.Scanner sc;

    public static boolean solve() {
        if (!sc.hasNextLine())
            return false;

        // Si la línea está vacía, terminamos
        String line = sc.nextLine();

        // Número de pilas de cómics
        int N = Integer.parseInt(line);

        // Puntero al cómic con menor id
        long punteroMin = Long.MAX_VALUE;

        // MinHeap para las pilas, ordenado por el elemento superior
        PriorityQueue<ComicPile> minHeap = new PriorityQueue<>((a, b) -> Long.compare(a.top, b.top));

        for (int n = 0; n < N; n++) {
            String line2 = sc.nextLine();
            String[] comics = line2.split(" ");
            // Cantidad de commics en la pila
            int K = Integer.parseInt(comics[0]);

            // Pila de comics
            Stack<Long> pila = new Stack<>();
            for (int k = 0; k < K; k++) {
                // Guardamos el id en la pila y actualizamos el puntero del mínimo
                long id = Long.parseLong(comics[k + 1]);
                punteroMin = Math.min(punteroMin, id);
                pila.push(id);
            }

            // Verifica si una pila de cómics no está vacía y, si es así, la
            // añade al montículo de mínimos (MinHeap).
            if (!pila.isEmpty())
                minHeap.offer(new ComicPile(pila, pila.peek()));
        }

        // Contador de espera
        int wait = 1;
        while (!minHeap.isEmpty()) {
            // Obtenemos la pila con el cómic de menor id
            ComicPile pila = minHeap.poll();
            
            // Verificar si la pila está vacía
            if (pila.stack.isEmpty())
                continue;

            // Si encontramos el comic con el ID mínimo, terminamos
            if (pila.top != null && pila.top == punteroMin)
                break;

            // Sacamos el cómic de la pila
            pila.stack.pop();
            
            // Actualizamos y volvemos a insertar si no está vacía
            if (!pila.stack.isEmpty()) {
                pila.top = pila.stack.peek();
                minHeap.offer(pila);
            }
            wait++;
        }

        // Imprimimos el tiempo de espera
        System.out.println(wait);
        return true;
    }

    public static void main(String[] args) {
        sc = new Scanner(System.in);
        while (solve())
            ;
        sc.close();
    }
}