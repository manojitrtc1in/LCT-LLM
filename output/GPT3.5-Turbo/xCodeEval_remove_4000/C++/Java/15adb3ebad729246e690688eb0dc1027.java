import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

class Main {
    static final int MOD = (int) 1e9 + 7;

    static long n = 0;
    static int[][] dp = new int[61][8];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int tests = Integer.parseInt(br.readLine());

        while (tests-- > 0) {
            n = Long.parseLong(br.readLine());

            for (int i = 0; i < 61; i++) {
                for (int j = 0; j < 8; j++) {
                    dp[i][j] = 0;
                }
            }

            dp[0][0] = 1;
            for (int i = 0; i < 60; i++) {
                boolean bit = ((1L << i) & n) != 0;

                for (int j = 0; j < (1 << 3); j++) {
                    if (dp[i][j] == 0) {
                        continue;
                    }

                    for (int k = ((j % 2) ^ (bit ? 1 : 0)); k < 8; k += 2) {
                        int lol = (j + k);

                        dp[i + 1][lol / 2] += dp[i][j];
                        if (dp[i + 1][lol / 2] >= MOD) {
                            dp[i + 1][lol / 2] -= MOD;
                        }
                    }
                }
            }

            pw.println(dp[60][0]);
        }

        pw.flush();
        pw.close();
        br.close();
    }
}
