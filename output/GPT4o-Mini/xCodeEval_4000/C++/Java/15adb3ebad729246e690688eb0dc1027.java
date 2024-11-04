import java.io.*;
import java.util.*;

public class 15adb3ebad729246e690688eb0dc1027_nc {
    static final int MOD = (int) 1e9 + 7;
    static long n = 0;
    static long[][] dp = new long[61][8];

    static void solve() throws IOException {
        n = Long.parseLong(br.readLine().trim());
        for (int i = 0; i < 61; i++) {
            Arrays.fill(dp[i], 0);
        }
        dp[0][0] = 1;

        for (long i = 0; i < 60; i++) {
            boolean bit = ((1L << i) & n) != 0;

            for (int j = 0; j < (1 << 3); j++) {
                if (dp[(int) i][j] == 0) continue;

                for (int k = ((j % 2) ^ (bit ? 1 : 0)); k < 8; k += 2) {
                    int lol = (j + k);
                    dp[(int) (i + 1)][lol / 2] += dp[(int) i][j];
                    if (dp[(int) (i + 1)][lol / 2] >= MOD) {
                        dp[(int) (i + 1)][lol / 2] -= MOD;
                    }
                }
            }
        }

        System.out.println(dp[60][0]);
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int tests = Integer.parseInt(br.readLine().trim());
        while (tests-- > 0) {
            solve();
        }
    }
}
