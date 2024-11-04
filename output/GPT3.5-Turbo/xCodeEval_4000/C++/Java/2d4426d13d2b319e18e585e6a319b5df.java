import java.util.*;
import java.io.*;

class Main {
    static final int jt = 998244353;
    static final int Inf = 0x3f3f3f3f;
    static final long INF = 0x3f3f3f3f3f3f3f3fL;
    static final double eps = 1e-10;
    static final double pi = Math.acos(-1);

    static int n, m;
    static char[][] s = new char[55][25];
    static int[] val = new int[55];
    static long[] dy = new long[(1 << 20) + 5];
    static double[] dp = new double[(1 << 20) + 5];

    public static void main(String[] args) throws IOException {
        FastScanner sc = new FastScanner(System.in);
        n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            s[i] = sc.next().toCharArray();
        }
        m = s[0].length;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int num = 0;
                for (int k = 0; k < m; k++) {
                    num |= (s[i][k] == s[j][k] ? (1 << k) : 0);
                }
                dy[num] |= (1L << i) | (1L << j);
            }
        }
        for (int i = (1 << m) - 1; i >= 0; i--) {
            for (int j = i; j > 0; j -= j & -j) {
                int lst = j & -j;
                dy[i ^ lst] |= dy[i];
            }
        }
        dp[0] = 1;
        double ans = 0;
        for (int i = 0; i < (1 << m); i++) {
            double v = dp[i] / (m - Integer.bitCount(i));
            for (int j = (1 << m) - 1 ^ i; j > 0; j -= j & -j) {
                dp[i | (j & -j)] += v;
            }
            ans += dp[i] * Long.bitCount(dy[i]);
        }
        System.out.println(ans / n);
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
            st = null;
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
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
}
