import java.util.*;
import java.io.*;

class Main {
    static final long MOD = 998244353;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        int[][] a = new int[n][];
        int[] w = new int[n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int t = Integer.parseInt(st.nextToken());
            a[i] = new int[t];
            for (int j = 0; j < t; j++) {
                a[i][j] = Integer.parseInt(st.nextToken());
                w[i] += a[i][j];
            }
        }

        int ans = 0;
        solve(a, w, new int[k + 1], 0, n, k, ans);
        System.out.println(ans);
    }

    static void solve(int[][] a, int[] w, int[] dp, int l, int r, int k, int ans) {
        if (r - l == 1) {
            int sum = 0;
            for (int i = 0; i <= a[l].length; i++) {
                ans = Math.max(ans, dp[k - i] + sum);
                if (i != a[l].length) {
                    sum += a[l][i];
                }
            }
            return;
        }

        int m = (l + r) / 2;
        int[] dp2 = Arrays.copyOf(dp, dp.length);
        for (int i = m; i < r; i++) {
            for (int j = k - 1; j >= 0; j--) {
                if (a[i].length + j <= k) {
                    dp2[j + a[i].length] = Math.max(dp2[j + a[i].length], dp2[j] + w[i]);
                }
            }
        }
        solve(a, w, dp2, l, m, k, ans);
        for (int i = l; i < m; i++) {
            for (int j = k - 1; j >= 0; j--) {
                if (a[i].length + j <= k) {
                    dp[j + a[i].length] = Math.max(dp[j + a[i].length], dp[j] + w[i]);
                }
            }
        }
        solve(a, w, dp, m, r, k, ans);
    }
}
