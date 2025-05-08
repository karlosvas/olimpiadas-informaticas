package p57VeinticincoAnos;

public class VeinticincoAnos57 {

    static java.util.Scanner in;

    // Cantidad de ceros en el factorial de un número !k
    public static long factoriaZero(long k) {
         // La cantidad de ceros finales en un factorial está determinada por 
        // la cantidad de factores 5 en la descomposición factorial
        // Cada factor 5 añade un cero, cada factor 25 añade otro cero adicional, etc.
        long zeros = 0, i = 5;
        while ((k / i) >= 1) {
          zeros += k / i;
          i *= 5;
        }
        return zeros;
    }

    public static boolean solve() {
        String[] line = in.nextLine().split(" ");
        if (line[0].equals("0") && line[1].equals("0"))
            return false;
        
        // Numero que deve de ser divisible (d)
        long d = Long.parseLong(line[0]);
        // Cantiad de ceros que se deben de encontrar (n)
        long n = Long.parseLong(line[1]);
        
           
        // Binary search para encontrar el rango donde puede estar: buscamos un rango inicial donde pueda existir la solución
        // Empezamos con límites l=0 y r=1, y expandimos r exponencialmente
        // hasta encontrar un valor r tal que k=d*r tenga al menos n ceros en su factorial
        long l = 0;
        long r = 1;
        while(factoriaZero(d*r) < n){
            l = r;
            r <<= 1; // multiplicamos r por 2 desplazando los bits a la izquierda en binario
        }

        // Busqueda binaria para encontrar el valor exacto, siempre que el limite izquierdo sea menor al derecho quiere decir que no se ha encontrado la solución
        while (l + 1 < r) {
            // Calculamos el punto medio(k)
            long k = (l + r) / 2;
            // Si el número de ceros es menor a el número de ceros, movemos el
            // limite izquierdo hacia la derecha, de lo contrario movemos el limite derecho hacia la izquierda
            // de modo que el rango se reduzca a la mitad y que al encontrarse habrá solución
            if (factoriaZero(k * d) < n)
              l = k;
            else
              r = k;
          }
        
        // Al finalizar la búsqueda binaria, el valor de r representa el primer número
        // cuyo factorial tiene al menos n ceros. Comprobamos valores cercanos [r, r+4] 
        // buscando el primer valor exacto que tenga exactamente n ceros, ya que
        // la cantidad de 0 va cambiando cada multiplo de 5
        for (long i = 0; i < 5; i++) {
            // Si se encontró una solución exacta, la devolvemos
            if (factoriaZero((r + i) * d) == n) {
                System.out.println((r + i) * d);
                return true;
            }
        }

        System.out.println("NINGUNO");
        return true;
    }

    public static void main(String[] args) {
        in = new java.util.Scanner(System.in);
        while (solve())
            ;
        in.close(); 
    }
}