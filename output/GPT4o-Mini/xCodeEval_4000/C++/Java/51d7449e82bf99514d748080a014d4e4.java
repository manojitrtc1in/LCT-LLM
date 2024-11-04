import java.io.*;
import java.util.*;

public class 51d7449e82bf99514d748080a014d4e4_nc {
    static final int N = 3000 + 10;
    static int n, k;
    static int[] m = new int[N];
    static long[][] a = new long[N][N];
    static long ans = 0;
    static long[] sum = new long[N];

    static void insert(long[] dp, int a, long b) {
        for (int i = k; i >= a; i--) {
            dp[i] = Math.max(dp[i], dp[i - a] + b);
        }
    }

    static void DFS(int l, int r, long[] f) {
        if (l == r) {
            ans = Math.max(ans, f[k]);
            long s = 0;
            for (int i = 1; i <= m[l] && i <= k; i++) {
                s += a[l][i];
                ans = Math.max(ans, s + f[k - i]);
            }
            return;
        }
        long[] g = f.clone();
        int mid = (l + r) >> 1;
        for (int i = mid + 1; i <= r; i++) {
            insert(g, m[i], sum[i]);
        }
        DFS(l, mid, g);
        g = f.clone();
        for (int i = l; i <= mid; i++) {
            insert(g, m[i], sum[i]);
        }
        DFS(mid + 1, r, g);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("1.in"));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        for (int i = 1; i <= n; i++) {
            m[i] = Integer.parseInt(br.readLine());
            for (int j = 1; j <= m[i]; j++) {
                a[i][j] = Long.parseLong(br.readLine());
                sum[i] += a[i][j];
            }
        }
        DFS(1, n, new long[k + 1]);
        System.out.println(ans);
    }
}
