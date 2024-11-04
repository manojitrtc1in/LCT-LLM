import java.util.Scanner;

public class b99e42d812ec5a02be1b527eea89e66axcodeeval_processed_4000.json {
    static final int M = 1000000007;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        String t = scanner.nextLine();
        int sz1 = s.length();
        int sz2 = t.length();
        int[][] dp = new int[sz1 + 1][sz2 + 1];
        for (int i = 0; i <= sz1; i++) {
            for (int j = 0; j <= sz2; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = (dp[i][j - 1] + (s.charAt(i - 1) == t.charAt(j - 1) ? (dp[i - 1][j - 1] + 1) : 0)) % M;
                }
            }
        }
        int re = 0;
        for (int i = 0; i < sz1; i++) {
            re = (re + dp[i + 1][sz2]) % M;
        }
        System.out.println(re);
    }
}
