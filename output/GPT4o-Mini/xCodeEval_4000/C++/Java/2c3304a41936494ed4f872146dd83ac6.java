import java.util.*;
import java.io.*;

public class 2c3304a41936494ed4f872146dd83ac6_nc {
    static final int MAX_SIZE = 5005;
    static final int M = 1000000007;
    static long[][] dp = new long[MAX_SIZE][MAX_SIZE];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        String t = br.readLine();
        int sz1 = s.length(), sz2 = t.length();
        for (int i = 0; i < MAX_SIZE; i++) {
            Arrays.fill(dp[i], 0);
        }
        
        for (int i = 0; i < sz1; i++) {
            for (int j = 0; j < sz2; j++) {
                dp[i + 1][j + 1] = (dp[i + 1][j] % M + (s.charAt(i) == t.charAt(j) ? (dp[i][j] + 1) % M : 0)) % M;
            }
        }
        
        long re = 0;
        for (int i = 0; i < sz1; i++) {
            re = (re + dp[i + 1][sz2] % M) % M;
        }
        
        System.out.println(re);
    }
}
