import java.util.*;
import java.io.*;

public class 3258bffc0e01cc65ae06816d90e14176xcodeeval_processed_4000.json {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    static class Pair {
        long first, second;

        public Pair(long first, long second) {
            this.first = first;
            this.second = second;
        }
    }

    static final long Mod = 1000000007L;
    static final long INF = 1000000000L;
    static final long LINF = 1000000000000000000L;
    static final double Pi = 3.141592653589793116;
    static final double EPS = 1e-9;
    static final double Gold = (1 + Math.sqrt(5)) / 2;
    static final long[] keymod = {1000000007L, 1000000009L, 1000000021L, 1000000033L};
    static final int keyCount = keymod.length;

    static FastReader sc = new FastReader();
    static PrintWriter out = new PrintWriter(System.out);

    static String s;
    static Map<Character, Long> Map;
    static long q;

    static void Input() {
        s = sc.next();
    }

    static void Solve() {
        long baseAnswer = 1;
        for (char x : s.toCharArray()) {
            if (x >= '0' && x <= '9') continue;
            if (x == '?') {
                q++;
                continue;
            }
            Map.put(x, Map.getOrDefault(x, 0L) + 1);
        }
        for (long i = 10; i > 10 - Map.size(); i--) baseAnswer *= i;
        if (s.charAt(0) >= 'A' && s.charAt(0) <= 'J') {
            baseAnswer /= 10;
            baseAnswer *= 9;
        }
        if (s.charAt(0) == '?') {
            baseAnswer *= 9;
            q--;
        }
        out.print(baseAnswer);
        for (long i = 0; i < q; i++) out.print("0");
    }

    public static void main(String[] args) {
        Input();
        Solve();
        out.close();
    }
}
