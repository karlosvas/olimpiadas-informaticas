import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;
import java.util.Set;

public class LaLiga30 {
    public static boolean solve(BufferedReader br, BufferedWriter bw) throws IOException {
        String line;
        if ((line = br.readLine()) == null || line.isEmpty())
            return false;

        // Cantidad de cromos
        int n = Integer.parseInt(line);

        if (n == 0)
            return false;
        // leemos cada uno de loca cromos
        String[] input = br.readLine().split(" ");

        // Lo almacenamos en un set para eliminar los repetidos
        Set<String> set = new HashSet<>();
        for (String s : input)
            set.add(s);

        // Escribimos la cantidad de cromos no repetidos
        bw.write(set.size() + "\n");
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        while (solve(br, bw))
            ;
        bw.flush();
        bw.close();
        br.close();
    }
}