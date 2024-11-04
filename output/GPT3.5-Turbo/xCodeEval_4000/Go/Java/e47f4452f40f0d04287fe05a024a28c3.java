import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class e47f4452f40f0d04287fe05a024a28c3_nc {
    static final int MOD = 1000 * 1000 * 1000 + 7;

    public static void main(String[] args) {
        FastScanner scanner = new FastScanner();
        int n = scanner.nextInt();
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int movesNum = scanner.nextInt();

        int[][] dp = new int[2][n + 1];
        for (int i = 1; i <= n; i++) {
            dp[0][i] = 1 + dp[0][i - 1];
            if (dp[0][i] >= MOD) {
                dp[0][i] -= MOD;
            }
        }

        for (int move = 0; move < movesNum; move++) {
            for (int x = 1; x <= n; x++) {
                int length = Math.abs(x - b);
                dp[(move & 1) ^ 1][x] = dp[(move & 1) ^ 1][x - 1];
                if (length > 1) {
                    int left = Math.max(x - (length - 1), 1);
                    int right = Math.min(x + (length - 1), n);
                    int add = dp[(move & 1)][right] - dp[(move & 1)][left - 1];
                    if (add < 0) {
                        add += MOD;
                    }
                    int sub = dp[(move & 1)][x] - dp[(move & 1)][x - 1];
                    if (sub < 0) {
                        sub += MOD;
                    }
                    int diff = add - sub;
                    if (diff < 0) {
                        diff += MOD;
                    }
                    dp[(move & 1) ^ 1][x] += diff;
                    if (dp[(move & 1) ^ 1][x] >= MOD) {
                        dp[(move & 1) ^ 1][x] -= MOD;
                    }
                }
            }
        }

        int ans = dp[((movesNum - 1) & 1) ^ 1][a] - dp[((movesNum - 1) & 1) ^ 1][a - 1];
        if (ans < 0) {
            ans += MOD;
        }
        System.out.println(ans);
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
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
    }
}
