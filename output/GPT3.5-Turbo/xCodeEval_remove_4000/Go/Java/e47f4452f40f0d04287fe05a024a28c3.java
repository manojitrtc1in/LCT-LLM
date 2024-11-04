import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class e47f4452f40f0d04287fe05a024a28c3xcodeeval_processed_4000.json {
    static final int MOD = 1000 * 1000 * 1000 + 7;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        solve(br);
        br.close();
    }

    static void solve(BufferedReader br) throws IOException {
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int a = Integer.parseInt(input[1]);
        int b = Integer.parseInt(input[2]);
        int movesNum = Integer.parseInt(input[3]);

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
}
