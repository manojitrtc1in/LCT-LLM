import java.util.*;

class Main {
    static int[][] dp = new int[5005][5005];
    static final int M = 1000000007;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        String t = sc.nextLine();
        int sz1 = s.length();
        int sz2 = t.length();
        for (int i = 0; i < sz1; i++) {
            for (int j = 0; j < sz2; j++) {
                dp[i + 1][j + 1] = (((dp[i + 1][j] % M)) + (s.charAt(i) == t.charAt(j) ? ((dp[i][j] + 1) % M) : 0)) % M;
            }
        }
        int re = 0;
        for (int i = 0; i < sz1; i++) {
            re = (re + dp[i + 1][sz2] % M) % M;
        }
        System.out.println(re);
    }
}
