import java.util.*;

class Main {
    static int[][] dp = new int[5005][5005];
    static final int M = 1000000007;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();
        for (int i = 0; i <= s.length(); i++) {
            for (int j = 0; j <= t.length(); j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if (s.charAt(i - 1) == t.charAt(j - 1)) {
                    dp[i][j] = ((dp[i][j - 1] % M) + ((dp[i - 1][j] + 1) % M)) % M;
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        int re = 0;
        int sz = t.length();
        for (int i = 0; i < s.length(); i++) {
            re = (re + dp[i + 1][sz] % M) % M;
        }
        System.out.println(re);
    }
}
