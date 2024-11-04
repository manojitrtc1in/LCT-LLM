import java.util.*;
import java.io.*;

public class b99e42d812ec5a02be1b527eea89e66axcodeeval_processed_4000.json {
    static final int MAXI = 2 << 29;
    static final int M = 1000000007;
    static long[][] dp = new long[5005][5005];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        String t = br.readLine();
        int sz1 = s.length(), sz2 = t.length();
        Arrays.fill(dp[0], 0);

        for (int i = 0; i < sz1; i++) {
            for (int j = 0; j < sz2; j++) {
                dp[i + 1][j + 1] = (dp[i + 1][j] + ((s.charAt(i) == t.charAt(j)) ? (dp[i][j] + 1) : 0)) % M;
            }
        }

        long re = 0;
        for (int i = 0; i < sz1; i++) {
            re = (re + dp[i + 1][sz2]) % M;
        }
        System.out.println(re);
    }
}