package p11TecladoEstopeadoo;
import java.util.Scanner;

// Enviado en C++ por Time Limit Exceeded en DOMjudge23
public class TecladoEstropeado11 {
    public static boolean solve(Scanner sc) {
        if (!sc.hasNext())
            return false;

        // Creamos una lista para almacenar los caracteres
        String line = sc.next();
        StringBuilder resultado = new StringBuilder();
        int cursor = 0;

        for (int i = 0; i < line.length(); i++) {
            char c = line.charAt(i);
            switch (c) {
                // Inicio de la línea
                case '-':
                    cursor = 0;
                    break;
                // Final de la linea
                case '+':
                    cursor = resultado.length();
                    break;
                // Flecha derecha
                case '*':
                    if (cursor < resultado.length()) {
                        cursor++;
                    }
                    break;
                // Tecla suprimir
                case '3':
                    if (cursor < resultado.length()) {
                        resultado.deleteCharAt(cursor);
                    }
                    break;
                // Añadir caracter
                default:
                    resultado.insert(cursor, c);
                    cursor++;
                    break;
            }
        }

        System.out.println(resultado.toString());
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (solve(sc))
            ;
        sc.close();
    }
}
