import java.io.*;
import java.util.*;

public class 81cde294d18625d210496b13e682ac47_nc {
    static final int MOD = 1000000007;
    static final int MOD1 = 998244353;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        int[] l = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = Integer.parseInt(input[i]);
        }
        if (n >= 100) {
            System.out.println(1);
            return;
        }
        int ans = n * n;
        int[] cur = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            cur[i] = cur[i - 1] ^ l[i - 1];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                for (int k = j + 1; k <= n; k++) {
                    if ((cur[j] ^ cur[i - 1]) > (cur[k] ^ cur[j])) {
                        ans = Math.min(ans, k - i - 1);
                    }
                }
            }
        }
        if (ans == n * n) {
            ans = -1;
        }
        System.out.println(ans);
    }
}
