package p15MePilloElToro;

import java.util.TreeMap;
import java.util.Map;
import java.util.Scanner;

public class MePilloElToro15 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(solve(sc));
        sc.close();
    }

    public static boolean solve(Scanner sc) {
        // Numero de ejercicios que el profesor deve corregir(n)
        int n = sc.nextInt();
        if(n == 0) return false;
        Map<String, Integer> map = new TreeMap<>();

        for (int i = 0; i < n; i++) {
            // Nombre del autor(nombre)
            String nombre = sc.nextLine();
            if (nombre.equals(""))
                nombre = sc.nextLine();

            // Opcion del autor(opcion)
            // "CORRECTO" o "INCORRECTO"
            String opcion = sc.next();

            if (opcion.equals("INCORRECTO")){
                // Si es incorrecto, decrementamos la nota
                if (map.containsKey(nombre)) {
                    int numero = map.get(nombre);
                    map.put(nombre, --numero);
                } else {
                    map.put(nombre, -1);
                }
            } else {
                // Si es correcto, incrementamos la nota
                if (map.containsKey(nombre)){
                    int numero = map.get(nombre);
                    map.put(nombre, ++numero);
                } else {
                    map.put(nombre, 1);
                }
            }
        }

        // Al ser un set ya está ordenado por defecto, no es necesario ordenar
        // Mostramos los resultados
        for (Map.Entry<String, Integer> entry : map.entrySet()) 
            if (entry.getValue() != 0)
                System.out.printf("%s, %d%n", entry.getKey(), entry.getValue());
        

        System.out.println("---");

        return true;
    }
}