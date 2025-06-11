package p31MilDoscientosSesentaDias;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class MilDoscientosSesentaDias {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // Meses en calendario juliano (ciclo de 4 años, 48 meses)
        int[] months = {
            31,28,31,30,31,30,31,31,30,31,30,31,
            31,29,31,30,31,30,31,31,30,31,30,31,
            31,28,31,30,31,30,31,31,30,31,30,31,
            31,28,31,30,31,30,31,31,30,31,30,31
        };
        int cycleLen = months.length; // 48
        long cycleDays = 4L * 365 + 1; // 1461

        // Precomputar todas las sumas de secuencias consecutivas de hasta 48 meses
        Set<Long> base = new HashSet<>();
        for (int i = 0; i < cycleLen; i++) {
            long sum = 0;
            for (int len = 1; len <= cycleLen; len++) {
                int idx = (i + len - 1) % cycleLen;
                sum += months[idx];
                base.add(sum);
            }
        }

        String line;
        while ((line = br.readLine()) != null) {
            long n = Long.parseLong(line.trim());
            if (n == 0) break;
            boolean ok = false;
            if (base.contains(n)) {
                ok = true;
            } else {
                for (long s : base) {
                    if (n > s && (n - s) % cycleDays == 0) {
                        ok = true;
                        break;
                    }
                }
            }
            System.out.println(ok ? "SI" : "NO");
        }
    }
}
