package ElChispometroCuantico;

import java.io.*;

public class ElChispometroCuantico61 {
    static BufferedReader in;
    static PrintWriter out;
    static int[] P;
    
    // Consulta al juez o devuelve la respuesta en modo debug
    public static int quest(int a, int b) throws IOException {
        System.out.println("? " + a + " " + b);
        System.out.flush();
        return Integer.parseInt(in.readLine());
    }
    
    // Muestra el vector de energias
    public static void showEnergy() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < P.length; i++) {
            sb.append(P[i]);
            if (i < P.length - 1)
                sb.append(" ");
        }
        out.println(sb.toString());
    }
    
    public static boolean solve() throws IOException {
        // Pilas(N), limpiamos el vector de energias
        int N = Integer.parseInt(in.readLine());

        if (N == 0)
            return false;

        // Plias(p)
        P = new int[N];

        // Pila de energias
        int pSize = 0;
        int a = 1, b = 2, c = 3;
        
        int ab = quest(a, b);
        int ac = quest(a, c);
        int bc = quest(b, c);
        
         // Valor de a
        int x = (ab + ac - bc) / 2;
        P[pSize++] = x;
        
        // Valor de b
        x = ab - P[a - 1];
        P[pSize++] = x;
        
        // Valor de c
        x = bc - P[b - 1];
        P[pSize++] = x;
        
        // c = bc - b
        int d = c + 1;
        
        while (pSize < N) {
            int cd = quest(c, d);
            x = cd - P[c - 1];
            P[pSize++] = x;
            c++;
            d++;
        }
        
        System.out.print("Respuesta: ");
        showEnergy();
        out.flush();
        
        return true;
    }
    
    public static void main(String[] args) throws IOException {
        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        while (solve());
        in.close();
        out.close();
    }
}