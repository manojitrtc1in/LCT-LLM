import java.util.*;

class Main {
    static int N = 3000 + 10;
    static int n, k;
    static int[] m = new int[N];
    static int[][] a = new int[N][N];
    static long ans;
    static long[] sum = new long[N];

    static void insert(List<Long> dp, int a, long b) {
        for (int i = k; i >= a; i--) {
            dp.set(i, Math.max(dp.get(i), dp.get(i - a) + b));
        }
    }

    static void DFS(int l, int r, List<Long> f) {
        if (l == r) {
            ans = Math.max(ans, f.get(k));
            long s = 0;
            for (int i = 1; i <= m[l] && i <= k; i++) {
                s += a[l][i];
                ans = Math.max(ans, s + f.get(k - i));
            }
            return;
        }
        List<Long> g = new ArrayList<>(f);
        int mid = (l + r) >> 1;
        for (int i = mid + 1; i <= r; i++) {
            insert(g, m[i], sum[i]);
        }
        DFS(l, mid, g);
        g = new ArrayList<>(f);
        for (int i = l; i <= mid; i++) {
            insert(g, m[i], sum[i]);
        }
        DFS(mid + 1, r, g);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            m[i] = sc.nextInt();
            for (int j = 1; j <= m[i]; j++) {
                a[i][j] = sc.nextInt();
                sum[i] += a[i][j];
            }
        }
        DFS(1, n, new ArrayList<>(Collections.nCopies(k + 1, 0L)));
        System.out.println(ans);
    }
}
