import java.io.*;
import java.util.*;

public class ee30789657a7c1b6969f94228dc10465_nc {
    static final long MOD = 1000000007;
    static long[][][][] dp = new long[65][2][2][2];

    static void solve() throws IOException {
        long t = Long.parseLong(io.readLine());

        for (int i = 0; i < 61; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    for (int l = 0; l < 2; l++)
                        dp[i][j][k][l] = 0;

        dp[0][0][0][0] = 1;

        for (int i = 0; i < 60; i++) {
            boolean f2 = (t >> i & 1) == 1;

            if (f2) {
                dp[i + 1][0][0][0] += dp[i][0][0][0];
                dp[i + 1][1][0][0] += dp[i][0][0][0];
                dp[i + 1][0][1][0] += dp[i][0][0][0];
                dp[i + 1][1][1][0] += dp[i][0][0][0];
                dp[i + 1][0][1][0] += dp[i][0][0][1];
                dp[i + 1][1][1][0] += dp[i][0][0][1];
                dp[i + 1][0][0][1] += dp[i][0][0][1];
                dp[i + 1][1][0][1] += dp[i][0][0][1];
                dp[i + 1][1][0][0] += dp[i][0][1][0];
                dp[i + 1][0][1][0] += dp[i][0][1][0];
                dp[i + 1][1][1][0] += dp[i][0][1][0];
                dp[i + 1][0][0][1] += dp[i][0][1][0];
                dp[i + 1][1][1][0] += dp[i][0][1][1];
                dp[i + 1][0][0][1] += dp[i][0][1][1];
                dp[i + 1][1][0][1] += dp[i][0][1][1];
                dp[i + 1][0][1][1] += dp[i][0][1][1];
                dp[i + 1][0][0][0] += dp[i][1][0][0];
                dp[i + 1][1][0][0] += dp[i][1][0][0];
                dp[i + 1][0][1][0] += dp[i][1][0][0];
                dp[i + 1][1][1][0] += dp[i][1][0][0];
                dp[i + 1][0][1][0] += dp[i][1][0][1];
                dp[i + 1][1][1][0] += dp[i][1][0][1];
                dp[i + 1][0][0][1] += dp[i][1][0][1];
                dp[i + 1][1][0][1] += dp[i][1][0][1];
                dp[i + 1][1][0][0] += dp[i][1][1][0];
                dp[i + 1][0][1][0] += dp[i][1][1][0];
                dp[i + 1][1][1][0] += dp[i][1][1][0];
                dp[i + 1][0][0][1] += dp[i][1][1][0];
                dp[i + 1][1][1][0] += dp[i][1][1][1];
                dp[i + 1][0][0][1] += dp[i][1][1][1];
                dp[i + 1][1][0][1] += dp[i][1][1][1];
                dp[i + 1][0][1][1] += dp[i][1][1][1];
            } else {
                dp[i + 1][0][0][0] += dp[i][0][0][0];
                dp[i + 1][1][0][0] += dp[i][0][0][0];
                dp[i + 1][0][1][0] += dp[i][0][0][0];
                dp[i + 1][1][1][0] += dp[i][0][0][0];
                dp[i + 1][0][1][0] += dp[i][0][0][1];
                dp[i + 1][1][1][0] += dp[i][0][0][1];
                dp[i + 1][0][0][1] += dp[i][0][0][1];
                dp[i + 1][1][0][1] += dp[i][0][0][1];
                dp[i + 1][1][0][0] += dp[i][0][1][0];
                dp[i + 1][0][1][0] += dp[i][0][1][0];
                dp[i + 1][1][1][0] += dp[i][0][1][0];
                dp[i + 1][0][0][1] += dp[i][0][1][0];
                dp[i + 1][1][1][0] += dp[i][0][1][1];
                dp[i + 1][0][0][1] += dp[i][0][1][1];
                dp[i + 1][1][0][1] += dp[i][0][1][1];
                dp[i + 1][0][1][1] += dp[i][0][1][1];
                dp[i + 1][1][0][0] += dp[i][1][0][0];
                dp[i + 1][0][1][0] += dp[i][1][0][0];
                dp[i + 1][1][1][0] += dp[i][1][0][0];
                dp[i + 1][0][0][1] += dp[i][1][0][0];
                dp[i + 1][1][1][0] += dp[i][1][0][1];
                dp[i + 1][0][0][1] += dp[i][1][0][1];
                dp[i + 1][1][0][1] += dp[i][1][0][1];
                dp[i + 1][0][1][1] += dp[i][1][0][1];
                dp[i + 1][0][1][0] += dp[i][1][1][0];
                dp[i + 1][1][1][0] += dp[i][1][1][0];
                dp[i + 1][0][0][1] += dp[i][1][1][0];
                dp[i + 1][1][0][1] += dp[i][1][1][0];
                dp[i + 1][0][0][1] += dp[i][1][1][1];
                dp[i + 1][1][0][1] += dp[i][1][1][1];
                dp[i + 1][0][1][1] += dp[i][1][1][1];
                dp[i + 1][1][1][1] += dp[i][1][1][1];
            }

            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    for (int l = 0; l < 2; l++)
                        dp[i + 1][j][k][l] %= MOD;
        }

        io.writeln(dp[60][0][0][0]);
    }

    public static void main(String[] args) throws IOException {
        io = new FastIO();
        int q = Integer.parseInt(io.readLine());
        while (q-- > 0) {
            solve();
        }
    }

    static FastIO io;

    static class FastIO {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        String readLine() throws IOException {
            return br.readLine();
        }

        void writeln(long x) {
            out.println(x);
        }
    }
}
