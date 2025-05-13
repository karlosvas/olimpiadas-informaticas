package p07EligiendoVagones;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Comparator;

class Pair {
    int difference;
    int position;

    public Pair(int difference, int position) {
        this.difference = difference;
        this.position = position;
    }
}

public class ElijiendoVagones {
    public static boolean solve(BufferedReader br) throws IOException {
        String[] line = br.readLine().trim().split(" ");
        // Cnatidad de personas que viajan juntas en grupo(p)
        int p = Integer.parseInt(line[0]);
        // Numero de vagones en el tren(n)
        int n = Integer.parseInt(line[1]);

        if(p+n == 0) return false;

        String[] parts = br.readLine().trim().split(" ");
        // Izquierda de vagones adyacenets (a) y derecha de vagones adyacentes (b)
        int a= 1, b= 1;
        int actualVagonSize = 0;
        Queue<Integer> queue = new LinkedList<>();
        // Implementa el Comparator usando una expresión lambda
        Comparator<Pair> registroComparator = (pair1, pair2) -> {
            if (pair1.difference != pair2.difference) {
                // Si los tiempos son diferentes elije el de menor momento
                return Integer.compare(pair1.difference, pair2.difference);
            } else {
                // Si los tiempos son iguales elije la caja mas cercana
                return Integer.compare(pair1.position, pair2.position);
            }
        };
        PriorityQueue<Pair> soluciones = new PriorityQueue<>(registroComparator);


        for (int i = 0; i < n; i++) {
            int vagones = Integer.parseInt(parts[i]);
            // Agregamos los la cantidad de vente de cada vagon a la pila
            queue.add(vagones);

            // Vamos sumando la cantidad de vagones que se van agregando
            actualVagonSize += vagones;
            // Si llega a ser la cantiad de personas necesarias
            if(actualVagonSize >= p){
                // Vemos si es posible restarle vagones de adelante y segir cumpliendo con la condición
                // O si a y b son iguales no se puede reducir porque apuntan al mismo vagon
                while(actualVagonSize - queue.peek() >= p && a < b){
                    actualVagonSize -= queue.poll();
                    a++;
                }
                // Agregar un nuevo par a la PriorityQueue
                soluciones.add(new Pair(Math.abs(a - b)+1, a));
            }
            b++;
        }

        // Mínimo número de vagones adyacentes necesarios para que los estudiantes del grupo puedan viajar
        // Posición del primer vagon que ocupan
        if(soluciones.isEmpty()){
            System.out.println("NO ENTRAN");
        } else {
            Pair solucion = soluciones.peek();
            System.out.println(solucion.difference + " " + solucion.position);
        }

        return true; 
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while(solve(br));
    }
}
