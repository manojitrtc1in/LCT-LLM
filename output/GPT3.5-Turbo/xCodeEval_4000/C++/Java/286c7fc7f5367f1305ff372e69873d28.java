import java.io.*;
import java.util.*;

class EDerevoDelitelei {
    public static void main(String[] args) throws IOException {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);
        solve(in, out);
        out.close();
    }

    static void solve(InputReader in, PrintWriter out) {
        int n = in.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextLong();
        }

        Arrays.sort(a);
        int[] d = new int[n];
        for (int i = 0; i < n; i++) {
            long c = a[i];
            for (long j = 2; j * j <= c; j++) {
                while (c % j == 0) {
                    d[i]++;
                    c /= j;
                }
            }
            if (c != 1) {
                d[i]++;
            }
        }
        int infty = Integer.MAX_VALUE / 2;
        int[] reachable = new int[1 << n];
        Arrays.fill(reachable, infty);
        reachable[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (1 << i); j++) {
                long rem = a[i];
                boolean good = true;
                for (int k = 0; k < i; k++) {
                    if ((j & (1 << k)) != 0) {
                        if (rem % a[k] != 0) {
                            good = false;
                            break;
                        }
                        rem /= a[k];
                    }
                }
                int qty = 0;
                for (long c = 2; c * c <= rem; c++) {
                    while (rem % c == 0) {
                        qty++;
                        rem /= c;
                    }
                }
                if (rem != 1) {
                    qty++;
                }
                int lim;
                if (i == 0) {
                    lim = 0;
                } else {
                    lim = 1 << (i - 1);
                }
                if (good) {
                    for (int k = 0; k < (1 << i); k++) {
                        if ((j & k) == 0 && reachable[j + k] != infty && j + k >= lim) {
                            reachable[(1 << i) + k] = Math.min(reachable[(1 << i) + k], reachable[j + k] + qty + (d[i] == 1 ? 0 : 1));
                        }
                    }
                }
            }
        }
        int answer = infty;
        for (int i = (1 << (n - 1)); i < (1 << n); i++) {
            if (reachable[i] != 0) {
                answer = Math.min(answer, reachable[i] + (Integer.bitCount(i) == 1 ? 0 : 1));
            }
        }
        out.println(answer);
    }

    static class InputReader {
        BufferedReader br;
        StringTokenizer st;

        public InputReader(InputStream stream) {
            br = new BufferedReader(new InputStreamReader(stream));
        }

        public String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }
    }
}
