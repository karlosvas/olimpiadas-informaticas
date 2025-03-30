import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import java.util.TreeSet;

public class ElBingoDeAzahara {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    
    public static boolean solve() throws IOException {
         // Lectura de la entrada
         String line = br.readLine();
         // Si esta vacia o "0", terminamos
         if (line.equals("0"))
             return false;
             
        // Participantes (N)
        int N = Integer.parseInt(line);

        // Por cada numero se guarda el nombre de la persona y un array con las personas que tienen ese numero
        Map<Integer, ArrayList<String>> participantes = new HashMap<>();
        // Cada persona tiene un carton con una cantidad de núemros
        Map<String, Integer> carton = new HashMap<>();
        // Personas que han ganado ordenadas alfabeticamente
        Set<String> resultado = new TreeSet<>();

        for (int i = 0; i < N; i++) {
            String[] person = br.readLine().split(" ");
            // Nombre de el carton de la persona
            String nombre = person[0];
            // Por cada numero del carton, osea desde la segunda posicion hasta la penultima ya que la ultima es 0 y no cuenta
            for (int j = 1; j < person.length-1; j++){
                int num_bombo = Integer.parseInt(person[j]);
                // Si no existe el numero en el mapa, se crea una nueva lista con el nombre de la persona si no se añade
                participantes.computeIfAbsent(num_bombo, k -> new ArrayList<>()).add(nombre);
                // Almacenamos el tamaño de su carton
                carton.put(nombre, carton.getOrDefault(nombre, 0) + 1);
            }
        }

        // Numero de bolas del carton (M)
        int M = Integer.parseInt(br.readLine());
        String[] balls = br.readLine().split(" ");

        // Ganador encontrado (ganador)
        boolean ganador = false;
        // Van saliendo numeros del bombo
        for (int i = 0; i < M; i++) {
            // Número de la bola que salió en el carton
            int num_bola = Integer.parseInt(balls[i]);

            // El número de la bola esta en uno de los cartones
            if(participantes.containsKey(num_bola)){
                // Obtenemos las personas que les toco ese nuemro
               ArrayList<String> personas = participantes.get(num_bola);
               for (int j = 0; j < personas.size(); j++) {
                    // Nombre de la persona (nombre)
                    String nombre = personas.get(j);
                    // Disminuimos el tamaño de su carton
                    carton.put(nombre, carton.get(nombre) - 1);
                    // Si no tiene mas numero sen su carton ha ganado
                    if(carton.get(nombre) == 0){
                        ganador = true;
                        resultado.add(nombre);
                    }
               }

            }
            if(ganador) break;
        }
        
        // Imprimimos el resultado, recorriendo el set de nombres al ser treeSet se ordenan alfabeticamente
        for (int i = 0; i < resultado.size(); i++) {
            if(i == 0) bw.write((String) resultado.toArray()[i]);
            else bw.write(" " + (String) resultado.toArray()[i]);
        }
        bw.write("\n");
        return true;
    }
    public static void main(String[] args) throws IOException {
        while(solve());
        bw.flush();
        bw.close();
    }
}