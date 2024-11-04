import java.util.*;

public class 5598d7ef668fdcf1a6156c7a024869df_nc {
    
    static int[][] dp = new int[5005][5005];
    static final int M = 1000000007;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        String s = sc.next();
        String t = sc.next();
        
        for (int i = 0; i <= s.length(); i++) {
            for (int j = 0; j <= t.length(); j++) {
                dp[i][j] = 0;
            }
        }
        
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < t.length(); j++) {
                if (s.charAt(i) == t.charAt(j)) {
                    dp[i + 1][j + 1] = ((dp[i + 1][j] % M) + ((dp[i][j] + 1) % M)) % M;
                } else {
                    dp[i + 1][j + 1] = dp[i + 1][j];
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
