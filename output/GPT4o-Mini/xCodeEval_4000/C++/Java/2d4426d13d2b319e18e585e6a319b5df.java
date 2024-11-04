import java.io.*;
import java.util.*;

public class 2d4426d13d2b319e18e585e6a319b5df_nc {
    static final int jt = 998244353;
    static final int MAX_MASK = (1 << 20) + 5;
    static int n, m;
    static String[] s = new String[55];
    static long[] dy = new long[MAX_MASK];
    static double[] dp = new double[MAX_MASK];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        
        n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            s[i] = br.readLine();
        }
        m = s[0].length();
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int num = 0;
                for (int k = 0; k < m; k++) {
                    num |= (s[i].charAt(k) == s[j].charAt(k) ? (1 << k) : 0);
                }
                dy[num] |= (1L << i) | (1L << j);
            }
        }
        
        for (int i = 0; i < (1 << m); i++) {
            for (int j = i; j > 0; j &= (j - 1)) {
                int lst = j & -j;
                dy[i ^ lst] |= dy[i];
            }
        }
        
        dp[0] = 1;
        double ans = 0;
        
        for (int i = 0; i < (1 << m); i++) {
            double v = dp[i] / (m - Integer.bitCount(i));
            for (int j = ((1 << m) - 1) ^ i; j > 0; j &= (j - 1)) {
                dp[i | (j & -j)] += v;
            }
            ans += dp[i] * Long.bitCount(dy[i]);
        }
        
        out.printf("%.10f%n", ans / n);
        out.close();
    }
}
