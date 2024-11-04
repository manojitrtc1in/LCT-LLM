import java.io.*;
import java.util.*;

public class 3258bffc0e01cc65ae06816d90e14176_nc {
    static String cppstr_infile = "FILE.IN";
    static String cppstr_outfile = "FILE.OUT";
    static String s;
    static Map<Character, Long> Map = new HashMap<>();
    static long q = 0;

    public static void main(String[] args) throws IOException {
        ControlIO(args);
        Input();
        Solve();
    }

    static void ControlIO(String[] args) throws IOException {
        if (args.length > 0) {
            System.setIn(new FileInputStream(args[0]));
        }
        if (args.length > 1) {
            System.setOut(new PrintStream(new FileOutputStream(args[1])));
        }
    }

    static void Input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        s = br.readLine();
    }

    static void Solve() {
        long baseAnswer = 1;
        for (char x : s.toCharArray()) {
            if (Character.isDigit(x)) continue;
            if (x == '?') {
                q++;
                continue;
            }
            Map.put(x, Map.getOrDefault(x, 0L) + 1);
        }
        for (long i = 10; i > 10 - Map.size(); i--) {
            baseAnswer *= i;
        }
        if (s.charAt(0) >= 'A' && s.charAt(0) <= 'J') {
            baseAnswer /= 10;
            baseAnswer *= 9;
        }
        if (s.charAt(0) == '?') {
            baseAnswer *= 9;
            q--;
        }
        System.out.print(baseAnswer);
        for (long i = 0; i < q; i++) {
            System.out.print("0");
        }
    }
}
