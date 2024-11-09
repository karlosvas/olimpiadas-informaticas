import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.LinkedList;
import java.util.Deque;
import java.util.TreeSet;

public class DetectiveDeModa17 {
    public static void main(String[] args) throws IOException {
        // Usamos BufferedReader y StringBuilder para mejorar la eficiencia
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        // Números de casos de prueba (Q)
        int Q = Integer.parseInt(br.readLine().trim());
        while (Q-- > 0) {
            // Número de camisetas actual (n)
            int n = Integer.parseInt(br.readLine().trim());

            Deque<Integer> barra = new LinkedList<>(); // Barra de camisetas donde se añaden y eliminan por los extremos
            TreeSet<Integer> camisetasUnicas = new TreeSet<>(); // Posiciones de las camisetas unicas, no repetidas y
                                                                // ordenadas por posición
            Map<Integer, TreeSet<Integer>> camisetasID = new HashMap<>(); // Posiciones de ese identificador ya sea
                                                                          // repetido o no

            // Entrada de los id de las camisetas
            String[] parts = br.readLine().trim().split(" ");

            for (int i = 0; i < n; i++) {
                int id = Integer.parseInt(parts[i]);
                // Añadimos el id a la barra
                barra.add(id);
                // Si no existe la camiseta la añadimos a las unicas, si existe la eliminamos
                TreeSet<Integer> uS = camisetasID.getOrDefault(id, new TreeSet<>());
                if (uS.isEmpty())
                    camisetasUnicas.add(i);
                else if (uS.size() == 1)
                    camisetasUnicas.remove(uS.first());
                // Añadimos la posición de la camiseta al map
                uS.add(i);
                camisetasID.put(id, uS);
            }

            // Número de eventos (E)
            int E = Integer.parseInt(br.readLine().trim());
            // Posiciones del extremo izquierdo y derecho
            int posI = 0, posD = n - 1;
            while (E-- > 0) {
                String[] operation = br.readLine().trim().split(" ");
                char op = operation[0].charAt(0);
                // Unico set izquierda y derecha
                TreeSet<Integer> uS_I, uS_D;
                switch (op) {
                    case 'P':
                        // Preguntamos en ese momento cuantas camisetas consecurivas de uno de los
                        // extremos deveria comprar como mínimo para que se lleve una única
                        preguntar(posI, posD, sb, camisetasUnicas);
                        break;
                    case 'I':
                        // Se añade camisetas por la izquierda actualizamos la posición de la izquierda
                        // posI
                        posI--;
                        // La camiseta que se añade a la barra en la posición de la izquierda
                        int idIzq = Integer.parseInt(operation[1]);
                        barra.addFirst(idIzq);
                        // Obtenemos las posiciones de ese id (uS_I) unico set izquierda
                        uS_I = camisetasID.getOrDefault(idIzq, new TreeSet<>());
                        // Si no existe la camiseta la añadimos a las unicas, si existe la eliminamos de
                        // las unicas
                        if (uS_I.isEmpty())
                            camisetasUnicas.add(posI);
                        else if (uS_I.size() == 1)
                            camisetasUnicas.remove(uS_I.first());
                        // Añadimos al map de camisetas
                        uS_I.add(posI);
                        camisetasID.put(idIzq, uS_I);
                        break;
                    case 'D':
                        // Lo mismo que el caso anterior pero por la derecha
                        posD++;
                        int idDer = Integer.parseInt(operation[1]);
                        barra.addLast(idDer);
                        uS_D = camisetasID.getOrDefault(idDer, new TreeSet<>());
                        if (uS_D.isEmpty())
                            camisetasUnicas.add(posD);
                        else if (uS_D.size() == 1)
                            camisetasUnicas.remove(uS_D.first());
                        uS_D.add(posD);
                        camisetasID.put(idDer, uS_D);
                        break;
                    case 'i':
                        // Si esta vacia no se puede eliminar
                        if (barra.isEmpty())
                            break;
                        // Obtenemos y eliminamos la camiseta de la izquierda de la brra y actualizamos
                        // la posición
                        // de posI
                        int first = barra.pollFirst();
                        // Obtenemos las posiciones de ese id (uS_I) unico set izquierda
                        uS_I = camisetasID.getOrDefault(first, new TreeSet<>());
                        uS_I.remove(posI);
                        if (uS_I.isEmpty()) {
                            // Si no estaba repetida la eliminamos de las unicas porque ya no es una opción
                            camisetasUnicas.remove(posI);
                        } else if (uS_I.size() == 1) {
                            // Si estaba repetida se añade a las unicas porque ahora queda una sola
                            camisetasUnicas.add(uS_I.first());
                        }
                        // En el map de apariciones de camisetas eliminamos la posición de la camiseta y
                        // actualizamos
                        camisetasID.put(first, uS_I);
                        posI++;
                        break;
                    case 'd':
                        // Lo mismo que el caso anterior pero por la derecha
                        if (barra.isEmpty())
                            break;
                        int last = barra.pollLast();
                        uS_D = camisetasID.getOrDefault(last, new TreeSet<>());
                        uS_D.remove(posD);
                        if (uS_D.isEmpty()) {
                            camisetasUnicas.remove(posD);
                        } else if (uS_D.size() == 1) {
                            camisetasUnicas.add(uS_D.first());
                        }
                        camisetasID.put(last, uS_D);
                        posD--;
                        break;
                }
            }
            sb.append("---\n");
        }
        System.out.print(sb);
    }

    // Número mínimo de camisetas consecutivas para llevarse la unica
    public static void preguntar(int posI, int posD, StringBuilder sb, TreeSet<Integer> camisetasUnicas) {
        if (camisetasUnicas.isEmpty()) {
            sb.append("NADA INTERESANTE\n");
            return;
        }
        // Obtener el primer elemento
        int firstElement = camisetasUnicas.first();
        int distI = firstElement - posI + 1;

        // Obtener el último elemento
        int lastElement = camisetasUnicas.last();
        int distD = posD - lastElement + 1;

        if (distI == distD) {
            // Si los dos apuntan a una unica camiseta se puede desde cualquiera de los dos
            // extremos
            sb.append(distI + " CUALQUIERA\n");
            return;
        } else if (distI < distD) {
            // Si solo la izquierda apunta a una unica camiseta cojemos desde la izquierda
            sb.append(distI + " IZQUIERDA\n");
            return;
        } else if (distI > distD) {
            // Si solo la derecha apunta a una unica camiseta cojemos desde la derecha
            sb.append(distD + " DERECHA\n");
            return;
        }
    }
}
