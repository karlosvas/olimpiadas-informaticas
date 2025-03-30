package p06_Tandem;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Tandem06 {

    public static long tandem(ArrayList<Integer> v, int k){
        // Número de emparejamientos distintos que se pueden formar son romper el tandem(ret)
        // Puntero a la izquierda(a) y derecha(b)
        int a = 0, b = v.size() -1, ret = 0;
        // Ordenamos el vector de pesos porque cuando para un peso i, si otro peso j>i no cumple la condición, quiere decir que todos los pesos mayores a j tampoco lo cumplirán, ya que romperan el tandem
        Collections.sort(v);

        // Cual es el último b con el que puedo emparejar el a para obtener el numero de emparejamientos distintos
        while(a < b){
            // Si la suma de los pesos de los tándem es mayor que el peso máximo que el tándem puede soportar, reducimos el peso de este, elijiendo uno mas pequeño
            if(v.get(a) + v.get(b) > k){
                b--;
            } else {
                // Si la suma de los pesos de los tándem es menor o igual que el peso máximo que el tándem puede soportar, incrementamos el número de emparejamientos distintos
                // Y almacenamos el número de emparejamientos distintos
                ret += b - a;
                a++;
            }
        }

        return ret;
    }

    public static boolean solve(Scanner sc){
        if (!sc.hasNext()) return false;
        
        // Número de integrantes de la familia(n) [1, 200.000]
        int n = sc.nextInt();

        // Peso máximo que el tándem puede soportar(k) [1, 2*10^9] 
        int k = sc.nextInt();


        // Este ejercicio no es suficientemente eficiente por lo que si da timelimit mejor utilizar C++,
        // no he probado con Array.parallelShort
        ArrayList<Integer> v = new ArrayList<>(n);  
        
        for (int i = 0; i < n; i++) {
            // Peso de cada uno de los tándem [0, 10^9]
            v.add(sc.nextInt()); 
        }

        System.out.println(tandem(v, k));

        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(solve(sc));
        sc.close();
    } 
}
