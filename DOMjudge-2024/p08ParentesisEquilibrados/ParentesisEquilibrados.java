package p08_ParentesisEquilibrados;

import java.util.Scanner;
import java.util.Stack;

// LIFO: Last In First Out
public class ParentesisEquilibrados {

    // Funcion que comprueba si dos parentesis son pareja
    public static boolean casan(char a, char b) {
        return (a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}');
    }

    public static boolean solve(Scanner sc) {
        
        // Verificamos que no nos hemos quedado sin entrada
        if(!sc.hasNextLine()) return false;

        // Creamos una pila para almacenar los parentesis abiertos no cerrados
        Stack<Character> pila = new Stack<>();
        boolean correct = true;
        
        // Leemos la cadena y la recorremos
        String n = sc.nextLine();
        for (char c : n.toCharArray()) {
            // ALmacenamos los parentesis abiertos no cerrados
            if (c == '(' || c == '[' || c == '{') {
                pila.push(c);
            } else if (c == ')' || c == ']' || c == '}') {
                // Si encontramos un parentesis cerrado, comprobamos si el ultimo parentesis abierto es su pareja
                if (pila.isEmpty() || !casan(pila.peek(), c)) {
                    correct = false;
                    break;
                }
                // Y lo eliminamos de la cima de la pila, el ultimo elemento introducido
                pila.pop();
            }
        }

        // Comprobamos si la pila esta vacia y si no hemos encontrado ningun error
        if(correct && pila.isEmpty())
            System.out.println("SI");
        else 
            System.out.println("NO");

        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (solve(sc));
        sc.close();
    }
}