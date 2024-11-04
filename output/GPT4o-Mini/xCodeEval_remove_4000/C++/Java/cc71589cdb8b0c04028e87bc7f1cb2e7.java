import java.util.*;
import java.io.*;

public class cc71589cdb8b0c04028e87bc7f1cb2e7xcodeeval_processed_4000.json {
    static long[] lim = {0, 9, 99, 99, 3099, 13099, 113099, 1113099, 11113099, 111113099};
    static String[] pr1 = {"", "198", "19", "2", "", "", "", "", "", ""};
    static String[] pr2 = {"", "199", "20", "3", "1", "1", "1", "1", "1", "1"};

    static String s;
    static int n;

    static boolean read(Scanner scanner) {
        if (!scanner.hasNext()) return false;
        s = scanner.next();
        s = s.substring(4);
        n = s.length();
        return true;
    }

    static String solve() {
        long x = Long.parseLong(s);
        if (x >= lim[n]) {
            return pr1[n] + s;
        } else {
            return pr2[n] + s;
        }
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("input.txt"));
        PrintStream out = new PrintStream(new File("output.txt"));
        System.setOut(out);

        long startTime = System.currentTimeMillis();

        int tc = scanner.nextInt();
        while (tc-- > 0) {
            read(scanner);
            System.out.println(solve());

            long elapsedTime = System.currentTimeMillis() - startTime;
            System.err.printf("TIME = %d ms%n", elapsedTime);
            startTime = System.currentTimeMillis();
        }
        scanner.close();
    }
}
