package p62Historigrama;

import java.io.FileNotFoundException;
import java.util.Scanner;

public class Historigrama62 {
    static Scanner in;

     public static int quest(int a, int b) {
        System.out.println("? " + a + " " + b);
        System.out.flush();
        return Integer.parseInt(in.next()); 
    }

    public static void main(String[] args) throws FileNotFoundException {
        in = new Scanner(System.in);
        int N = in.nextInt();
        
        int y = 0, x = 0;

        while (y < N && x < N) {
            if(quest(x,y) == 1){
                y++;
            } else {
                x++;
            }
        }

        System.out.println("! " + y);
        in.close();
    }
}