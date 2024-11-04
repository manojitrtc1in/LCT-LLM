import java.util.*;
import java.io.*;

class Main {
    static int[][] dp;
    static final int M = 1000000007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        String t = br.readLine();
        int sz1 = s.length();
        int sz2 = t.length();
        dp = new int[sz1 + 1][sz2 + 1];
        for (int i = 0; i <= sz1; i++) {
            for (int j = 0; j <= sz2; j++) {
                dp[i][j] = 0;
            }
        }
        for (int i = 0; i < sz1; i++) {
            for (int j = 0; j < sz2; j++) {
                dp[i + 1][j + 1] = (dp[i + 1][j] + (s.charAt(i) == t.charAt(j) ? (dp[i][j] + 1) : 0)) % M;
            }
        }
        int re = 0;
        for (int i = 0; i < sz1; i++) {
            re = (re + dp[i + 1][sz2]) % M;
        }
        System.out.println(re);
    }
}
