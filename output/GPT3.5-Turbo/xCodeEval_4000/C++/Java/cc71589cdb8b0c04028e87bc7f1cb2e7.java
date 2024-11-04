import java.util.*;
import java.io.*;

class Main {
    static final int N = 1000 + 7;
    static int n;
    static String s;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int tc = 1;
        // Uncomment the next line if there is a test case count
        // tc = Integer.parseInt(br.readLine());
        while (tc-- > 0) {
            read(br);
            pw.println(solve());
        }

        pw.close();
        br.close();
    }

    static void read(BufferedReader br) throws IOException {
        String line = br.readLine();
        s = line.substring(4);
        n = s.length();
    }

    static long[] lim = {0, 9, 99, 99, 3099, 13099, 113099, 1113099, 11113099, 111113099};
    static String[] pr1 = {"", "198", "19", "2", "", "", "", "", "", ""};
    static String[] pr2 = {"", "199", "20", "3", "1", "1", "1", "1", "1", "1"};

    static String solve() {
        long x = Long.parseLong(s);
        if (x >= lim[n])
            return pr1[n] + s;
        else
            return pr2[n] + s;
    }
}
