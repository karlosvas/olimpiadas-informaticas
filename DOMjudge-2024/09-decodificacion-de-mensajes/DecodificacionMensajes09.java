import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class DecodificacionMensajes09 {

    // Verifica si el char pasado por parametro es una vocal
    public static boolean isVocal(char c) {
        c = Character.toLowerCase(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
    // Cambia de lugar los caracteres consecutivos que no sean vocales
    public static String Xii(String s) {
        // StringBuilder para poder modificar la cadena
        StringBuilder sb = new StringBuilder(s);
        // Pila para almacenar los caracteres que no son vocales
        Deque<Character> stack = new ArrayDeque<>();

        for (int i = 0; i < sb.length(); i++) {
            char c = sb.charAt(i);
            // Si no es vocal lo metemos en la pila
            if (!isVocal(c)) {
                stack.push(c);
            } else{
                // Vaciamos la pila en la cadena, haciendo que los caracteres no vocales se inviertan, siempre que queden caracteres en la pila seguimos añadiendolos
                while (!stack.isEmpty())
                    sb.setCharAt(i - stack.size(), stack.pop());
            }
        }

        // Vaciar cualquier resto en la pila sobrante depues del bucle
        int index = sb.length() - stack.size();
        while (!stack.isEmpty())
            sb.setCharAt(index++, stack.pop());
        
        return sb.toString();
    }

    public static String Xi(String s) {
        // Array de caracteres para poder modificar la cadena
        char[] result = new char[s.length()];
        // Indices del principio y final de la cadena
        int left = 0;
        int right = s.length() - 1;

        // Ponemos xi al principio xi2 al final, xi3 al siguiente de el principio, xi4 al anterior del final...
        for (int i = 0; i < s.length(); i++) {
            if (i % 2 == 0) 
                result[left++] = s.charAt(i);
            else 
                result[right--] = s.charAt(i);
        }

        return new String(result);
    }

    public static boolean solve(Scanner sc){
        if(!sc.hasNextLine()) return false;

        String s = sc.nextLine();
        String paso1 = Xi(s);
        String paso2 = Xii(paso1);
        System.out.println(paso2);

        return true;
    }
    public static void main(String[] args) {
        // X se transforma en el el Xi de caracteres consecutivos que no sean vocales por su inversa
        // Xi se transforma en la sucesion de caracteres Xii  obtenida al ir tomando sucesivamente el primer caracter de xi, lugo el ultimo luego el segundo, luego el penultimo...
        Scanner sc = new Scanner(System.in);
        while(solve(sc));
        sc.close();
    }
}
