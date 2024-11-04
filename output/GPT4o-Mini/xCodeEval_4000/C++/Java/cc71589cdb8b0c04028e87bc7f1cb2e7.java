import java.util.*;
import java.io.*;

public class cc71589cdb8b0c04028e87bc7f1cb2e7_nc {
    static final int N = 1000 + 7;
    static long[] lim = {0, 9, 99, 99, 3099, 13099, 113099, 1113099, 11113099, 111113099};
    static String[] pr1 = {"", "198", "19", "2", "", "", "", "", "", ""};
    static String[] pr2 = {"", "199", "20", "3", "1", "1", "1", "1", "1", "1"};

    static String solve(String s) {
        long x = Long.parseLong(s);
        int n = s.length();
        if (x >= lim[n]) {
            return pr1[n] + s;
        } else {
            return pr2[n] + s;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        
        int tc = Integer.parseInt(br.readLine());
        while (tc-- > 0) {
            String s = br.readLine();
            s = s.substring(4);
            out.println(solve(s));
        }
        
        out.flush();
    }
}
