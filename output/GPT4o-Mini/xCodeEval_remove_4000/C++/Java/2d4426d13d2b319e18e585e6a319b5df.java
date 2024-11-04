import java.util.*;
import java.io.*;

class Main {
    static final int jt = 998244353;
    static final int MAX_N = 55;
    static final int MAX_M = 25;
    static final int MAX_MASK = (1 << 20) + 5;

    static long[] dy = new long[MAX_MASK];
    static double[] dp = new double[MAX_MASK];
    static String[] s = new String[MAX_N];
    static int n, m;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        n = Integer.parseInt(br.readLine());
        
        for (int i = 0; i < n; i++) {
            s[i] = br.readLine();
        }
        
        m = s[0].length();
        
        for (int i = 0; i < n; i++) {
            for (int j = (i + 1) % n; j != i; j = (j + 1) % n) {
                int num = 0;
                for (int k = 0; k < m; k++) {
                    if (s[i].charAt(k) == s[j].charAt(k)) {
                        num |= (1 << k);
                    }
                }
                dy[num] |= (1L << i) | (1L << j);
            }
        }
        
        for (int i = 0; i < (1 << m); i++) {
            for (int j = i; j != 0; j &= (j - 1)) {
                int lst = j & -j;
                dy[i ^ lst] |= dy[i];
            }
        }
        
        dp[0] = 1;
        double ans = 0;
        
        for (int i = 0; i < (1 << m); i++) {
            double v = dp[i] / (m - Integer.bitCount(i));
            for (int j = ((1 << m) - 1) ^ i; j != 0; j &= (j - 1)) {
                dp[i | (j & -j)] += v;
            }
            ans += dp[i] * Long.bitCount(dy[i]);
        }
        
        out.printf("%.10f\n", ans / n);
        out.close();
    }
}
