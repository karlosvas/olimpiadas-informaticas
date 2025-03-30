package p68_DesarolloEnLasBicicletas;

import java.io.FileNotFoundException;
import java.util.PriorityQueue;
import java.util.Scanner;

public class DesarolloEnLasBicicletas68 {
    static Scanner in;      

    public static class Info implements Comparable<Info> {
        public int preferencia;
        public int diente;
        public int corona;

        public Info(int preferencia, int diente, int corona) {
            this.preferencia = preferencia;
            this.diente = diente;
            this.corona = corona;
        }

        @Override
        public int compareTo(Info other) {
            return Integer.compare(this.preferencia, other.preferencia);
        }
    }

    public static boolean solve() {
        
        String[] line = in.nextLine().split(" ");
        // Numero de platos(P)
        int P = Integer.parseInt(line[0]);
        // Número de coronas(C)
        int C = Integer.parseInt(line[1]);
        
        if(P+C == 0)
            return false;

        // Nuemro de dientes de cada palto
        String[] dienetsPlato = in.nextLine().split(" ");
        int[] dientesSolucion = new int[P];
        for (int i = 0; i < P; i++) {
            int diente = Integer.parseInt(dienetsPlato[i]);
            dientesSolucion[i] = diente;
        }

        // Nuemro de dientes de cada corona
        int actualMCM = 1;
        String[] dientesCorona = in.nextLine().split(" ");
        int[] coronaSolucion = new int[C];
        for (int i = 0; i < C; i++) {
            int diente = Integer.parseInt(dientesCorona[i]);
            coronaSolucion[i] = diente;
            actualMCM = mcm(actualMCM, diente);
        }

        PriorityQueue<Info> pq = new PriorityQueue<>();
        for (int i = 0; i < dientesSolucion.length; i++) {
            int factor = actualMCM / dientesSolucion[i];
            int diente = dientesSolucion[i];
            dientesSolucion[i] = dientesSolucion[i] * factor;

            for(int j = 0; j < coronaSolucion.length; j++){
                int preferencia = Math.abs(dientesSolucion[i] - coronaSolucion[j]);
                Info info = new Info(preferencia, diente, coronaSolucion[j]);
                pq.add(info);
            }
        }
        

        while (!pq.isEmpty()) {
            Info info = pq.poll();
            if(pq.size() == 0){
                System.out.println(info.diente + "-" + info.corona);
            } else {
                System.out.print(info.diente + "-" + info.corona +  " ");
            }
        }

        return true;
    }

    public static int mcm(int a, int b) {
        return (a * b) / gcd(a, b);
    }

    // máximo común divisor
    public static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    public static void main(String[] args) throws FileNotFoundException {
        in = new Scanner(System.in);
        while (solve());
        in.close();
    }
}
