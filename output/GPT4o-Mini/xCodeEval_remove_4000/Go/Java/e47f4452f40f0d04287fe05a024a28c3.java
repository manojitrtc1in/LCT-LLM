import java.io.*;
import java.util.*;

public class e47f4452f40f0d04287fe05a024a28c3xcodeeval_processed_4000.json {
    static final int MOD = 1000 * 1000 * 1000 + 7;
    static Scanner scanner;
    static PrintWriter writer;

    public static void main(String[] args) {
        scanner = new Scanner(System.in);
        writer = new PrintWriter(System.out);
        solve();
        writer.close();
    }

    static void solve() {
        int n = readInt();
        int a = readInt();
        int b = readInt();
        int movesNum = readInt();

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
        printInt(ans);
        printLine();
    }

    static int readInt() {
        return Integer.parseInt(scanner.next());
    }

    static void printInt(int value) {
        writer.print(value);
    }

    static void printLine() {
        writer.println();
    }
}
